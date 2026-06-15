#include <WiFi.h>
#include <esp_now.h>

#define LED_PIN 2   // built-in LED on many ESP32 boards

typedef struct Message {
  char command;   // 'o' = on, 'f' = off, 't' = toggle
} Message;

Message incomingMessage;
bool ledState = false;

void onDataReceive(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  memcpy(&incomingMessage, data, sizeof(incomingMessage));

  if (incomingMessage.command == 'o') {
    ledState = true;
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
  }
  else if (incomingMessage.command == 'f') {
    ledState = false;
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
  }
  else if (incomingMessage.command == 't') {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println("LED TOGGLED");
  }
  else {
    Serial.println("Unknown command received");
  }

  Serial.print("Received Command: ");
  Serial.println(incomingMessage.command);
  Serial.println("------------------");
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

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