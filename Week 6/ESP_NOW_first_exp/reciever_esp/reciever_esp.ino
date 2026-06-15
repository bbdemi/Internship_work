#include <WiFi.h>
#include <esp_now.h>

typedef struct Message {
  int counter;
  char text[32];
} Message;

Message incomingMessage;

void onDataReceive(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  memcpy(&incomingMessage, data, sizeof(incomingMessage));

  Serial.print("Received Counter: ");
  Serial.println(incomingMessage.counter);

  Serial.print("Received Text: ");
  Serial.println(incomingMessage.text);

  Serial.println("------------------");
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_recv_cb(onDataReceive);

  Serial.println("ESP-NOW Receiver Ready");
}

void loop() {
}