#include <Arduino.h>
// Comment out here and in platform.ini to use Arduino Serial
#include <Adafruit_TinyUSB.h>

// This test case is liable to prevent directly uploading code when it doesn't work!

// Double-clicking the reset microswitch will restart it into the
// bootloader to still allow uploading in such a state.

void setup() {
  // Turn on builtin LED before Serial.begin()
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);

  Serial.begin(9600);

  // Turn off after
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  // Blink while waiting
  do {
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  } while (!Serial);

  Serial.println("setup done");
}

void loop() {
  Serial.print("looping ");
  Serial.println(millis());
  delay(500);
}
