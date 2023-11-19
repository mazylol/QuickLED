#include <Arduino.h>

#include <QuickLED.h>

RGBLed::LED rgbLed = RGBLed::create(9, 5, 6);

void setup() {
  rgbLed.setup();
}

void loop() {
  rgbLed.set(RGBLed::Color{255, 0, 0});
  delay(1000);
  rgbLed.set(RGBLed::Color{0, 255, 0});
  delay(1000);
  rgbLed.set(RGBLed::Color{0, 0, 255});
  delay(1000);
}