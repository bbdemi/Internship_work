#include <WiFi.h>
#include <esp_now.h>

#define PIN_EN_MOTOR_M1 26
#define PIN_STEP_M1 27
#define PIN_DIR_M1 32

uint8_t servoEspAddress[] = {0xF4,0x65,0x0B,0xC0,0xF2,0xB8}; // servo ESP MAC
bool running = true;

typedef struct Message {
  char command;   // 'h' = hit
} Message;

Message incomingMessage;
Message outgoingMessage;

void sendCommand(char cmd) {
  outgoingMessage.command = cmd;

  esp_err_t result = esp_now_send(
    servoEspAddress,
    (uint8_t *)&outgoingMessage,
    sizeof(outgoingMessage)
  );

  if (result == ESP_OK) {
    Serial.println("Sent h back to servo ESP");
  } else {
    Serial.println("Send error");
  }
}

void moveStepper(int steps) {
  digitalWrite(PIN_EN_MOTOR_M1, LOW);   // enable driver
  digitalWrite(PIN_DIR_M1, HIGH);

  for (int i = 0; i < steps; i++) {
    digitalWrite(PIN_STEP_M1, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_STEP_M1, LOW);
    delayMicroseconds(800);
  }
}

void stepperHit() {
  if(!running)
  return;
  Serial.println("Stepper hitting");

  moveStepper(800);

  delay(500);
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
    Serial.println("Received h from servo ESP");
    stepperHit();
  }
  else if(incomingMessage.command == 's')
  {
    Serial.println("Received s from servo ESP");
   running=false;
  }
}

void onDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

void setup() {
  Serial.begin(115200);

  pinMode(PIN_EN_MOTOR_M1, OUTPUT);
  pinMode(PIN_STEP_M1, OUTPUT);
  pinMode(PIN_DIR_M1, OUTPUT);

  digitalWrite(PIN_EN_MOTOR_M1, LOW);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_recv_cb(onDataReceive);
  esp_now_register_send_cb(onDataSent);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, servoEspAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add servo peer");
    return;
  }

  Serial.println("Stepper ESP ready");
}

void loop() {
}