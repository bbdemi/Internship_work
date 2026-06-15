#include <WiFi.h>
#include <esp_now.h>

uint8_t receiverAddress[] = {0xF4,0x65,0x0B,0xB5,0x5A,0x2C};

typedef struct Message {
  int counter;
  char text[32];
} Message;

Message outgoingMessage;

void onDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
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
}

void loop() {
  static int count = 0;

  outgoingMessage.counter = count;
  snprintf(outgoingMessage.text, sizeof(outgoingMessage.text), "Hello %d", count);

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

  count++;
  delay(1000);
}