#include <WiFi.h>
#include <esp_now.h>

uint8_t receiverAddress[] = {0xF4, 0x65, 0x0B, 0xB5, 0x5A, 0x2C};

typedef struct Message {
  char command;   // 'o' = on, 'f' = off, 't' = toggle
} Message;

Message outgoingMessage;

void onDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
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

    if (command == "on") {
      Serial.println("Command: ON");
      sendCommand('o');
    }
    else if (command == "off") {
      Serial.println("Command: OFF");
      sendCommand('f');
    }
    else if (command == "toggle") {
      Serial.println("Command: TOGGLE");
      sendCommand('t');
    }
    else {
      Serial.println("Unknown command");
    }
  }
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_send_cb(onDataSent);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  Serial.println("ESP-NOW Sender Ready");
  Serial.println("Type: on / off / toggle");
}

void loop() {
  readCommand();
}