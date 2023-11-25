# QuickLED

A dead simple C++ library for Arduino framework Platformio projects.

## Features
- LEDs
- RGB LEDs
- Effects
- Is simplicity a feature?

## Usage
First things first you need to import it into your project like this:
```ini
[env:something]
framework = arduino
lib_deps = mazylol/QuickLED@^[insert-version-here]
```

Then do one of the following based on your type of LED

### Non RGB
```cpp
#include <Arduino.h>

#include <QuickLED.h>

/*
The param for Led::create is the pin that your led is connected to
NOTE: You must be connected to a PWM pin. Like on the uno the ones with a "~". This also goes for the RGB example.
*/
Led::LED led = Led::create(11);

void setup() {
    led.setup(); /* does the pinMode stuff for you */
}

void loop() {
    /* This is the brightness value, 0-255 (don't worry, it caps out at 255) */
    led.set(150);

    delay(1000);

    led.set(0);

    delay(1000);
}
```

### RGB
```cpp
#include <Arduino.h>

#include <QuickLED.h>

/*
Params in this case are the pins for Red, Green, and Blue.
*/
RGBLed::LED rgbLed = RGBLed::create(9, 5, 6);

void setup() {
    rgbLed.setup(); /* does the pinMode stuff for you */
}

void loop() {
    /* Yet again, there is a safeguard to cap out the values. Don't be afraid to use a loop. */
    rgbLed.set(RGBLed::Color{
    .Red = 255,
    .Green = 0,
    .Blue = 0
  });

  delay(1000);

  rgbLed.set(RGBLed::Color{
    .Red = 0,
    .Green = 0,
    .Blue = 255
  });

  delay(1000);
}
```

## Effects
I have a few effects for each type of Led. They are not much but they could be useful to you.

They are accessable under:
```cpp
Led::Effects::
/* and */
RGBLed::Effects::
```

### Non RGB
- blink
  - ***Params:***
  - LED (pass in your led variable)
  - maxBrightness (0-255)
  - delayMs
- fadeOut
  - ***Params:***
    - LED
    - delayMs
- fadeIn
  - ***Params:***
    - LED
    - delayMs

### RGB
- blink
  - ***Params:***
    - RGBLed (pass in your led variable)
    - color (RGBLed::Color)
    - delayMs
- rainbow
  - ***Params:***
    - RGBLed
    - delayMs