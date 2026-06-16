#include <WiFi.h>
#include <esp_now.h>
#include <ESP32Servo.h>

#define SERVO_PIN 13

Servo servo;

bool running = true;

uint8_t receiverAddress[] = {0x8C,0x4B,0x14,0xDB,0x00,0xE8};

typedef struct Message {
  char command;   // 'h' = hit
} Message;

Message outgoingMessage;
Message incomingMessage;

void sendCommand(char cmd);

void onDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

void hitServo() {
  servo.write(150);
  delay(250);
  servo.write(90);
}

void hitAndSend() {
  if(!running)
  return;
  Serial.println("Hitting ball");
  hitServo();
  delay(500);          // small delay before sending to other ESP
  if(running)
  sendCommand('h');
}

void stop()
{
  running=false;
}
void onDataReceive(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  memcpy(&incomingMessage, data, sizeof(incomingMessage));

  if (incomingMessage.command == 'h') {
    Serial.println("Received HIT command");
    hitAndSend();
  }
}

void sendCommand(char cmd) {
  outgoingMessage.command = cmd;

  esp_err_t result = esp_now_send(
    receiverAddress,
    (uint8_t *)&outgoingMessage,
    sizeof(outgoingMessage)
  );

  if (result == ESP_OK) {
    Serial.println("Message sent");
  } else {
    Serial.println("Send error");
  }
}

void readCommand() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "hit") {
      running = true;
      hitAndSend();
    }
    else if (command == "stop") {
      Serial.println("Stop command received");
      running = false;
      sendCommand('s');
    }
    else {
      Serial.println("Unknown command");
    }
  }
}

void setup() {
  Serial.begin(115200);

  servo.attach(SERVO_PIN);
  servo.write(90);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_send_cb(onDataSent);
  esp_now_register_recv_cb(onDataReceive);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  Serial.println("Servo ready");
  Serial.println("ESP-NOW Ready");
  Serial.println("Type: hit / stop");
}

void loop() {
  readCommand();
}