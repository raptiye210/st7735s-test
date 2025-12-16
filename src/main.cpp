#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println("ESP8266 hazır. Seri üzerinden gönderilen satırlar eko yapılacak.");
}

void loop() {

}
