#include <Arduino.h>
#include <Adafruit_TinyUSB.h>

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  do {
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  } while (!Serial.availableForWrite());

  Serial.println("setup done");
}

void loop() {
  Serial.print("looping ");
  Serial.println(millis());
  delay(500);
}
