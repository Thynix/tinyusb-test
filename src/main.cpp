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
  const unsigned long target_frame_time_microseconds = 500000;
  unsigned long frame_start_microseconds = micros();
  Serial.print("looping ");
  Serial.println(frame_start_microseconds);

  unsigned long frame_duration_microseconds = micros() - frame_start_microseconds;
  if (frame_duration_microseconds < target_frame_time_microseconds)
    delayMicroseconds(target_frame_time_microseconds - frame_duration_microseconds);
}
