#include <Arduino.h>

/// @brief A class to control RGB LEDs.
class RGBLed
{
public:
    /// @brief RGB color struct.
    typedef struct
    {
        unsigned int Red;
        unsigned int Green;
        unsigned int Blue;
    } Color;

    /// @brief LED struct. Represents a single RGB LED. Contains most of the important stuff.
    typedef struct
    {
        const unsigned int RedPin;
        const unsigned int GreenPin;
        const unsigned int BluePin;

        /// @brief Sets the color of the LED.
        /// @param color
        void set(Color color)
        {
            color = validateColor(color);

            analogWrite(RedPin, color.Red);
            analogWrite(GreenPin, color.Green);
            analogWrite(BluePin, color.Blue);
        }

        /// @brief Convenience method to setup the pins for the LED.
        void setup()
        {
            pinMode(RedPin, OUTPUT);
            pinMode(GreenPin, OUTPUT);
            pinMode(BluePin, OUTPUT);
        }
    } LED;

    /// @brief Creates a new LED struct.
    static LED create(unsigned int redPin, unsigned int greenPin, unsigned int bluePin)
    {
        return LED{.RedPin = redPin, .GreenPin = greenPin, .BluePin = bluePin};
    }

    /// @brief Contains effects for the LED.
    class Effects
    {
    public:
        /// @brief Blink the LED.
        /// @param led
        /// @param color
        /// @param delayMs
        static void blink(LED led, Color color, int delayMs)
        {
            color = validateColor(color);

            led.set(color);
            delay(delayMs);
            led.set({.Red = 0, .Green = 0, .Blue = 0});
            delay(delayMs);
        }

        /// @brief Rainbow effect.
        /// @param led
        /// @param delayMs
        static void rainbow(LED led, int delayMs)
        {
            for (unsigned int i = 0; i < 255; i++)
            {
                led.set(Color{.Red = i, .Green = 0, .Blue = 0});
                delay(delayMs);
            }
            for (unsigned int i = 0; i < 255; i++)
            {
                led.set(Color{.Red = 255, .Green = i, .Blue = 0});
                delay(delayMs);
            }
            for (unsigned int i = 0; i < 255; i++)
            {
                led.set(Color{.Red = 255 - i, .Green = 255, .Blue = 0});
                delay(10);
            }
            for (unsigned int i = 0; i < 255; i++)
            {
                led.set(Color{.Red = 0, .Green = 255, .Blue = i});
                delay(10);
            }
            for (unsigned int i = 0; i < 255; i++)
            {
                led.set(Color{.Red = 0, .Green = 255 - i, .Blue = 255});
                delay(10);
            }
            for (unsigned int i = 0; i < 255; i++)
            {
                led.set(Color{.Red = i, .Green = 0, .Blue = 255});
                delay(10);
            }
        }
    };

private:
    /// @brief Validates and corrects the color value.
    static Color validateColor(Color color)
    {
        if (color.Red > 255)
        {
            color.Red = 255;
        }
        if (color.Green > 255)
        {
            color.Green = 255;
        }
        if (color.Blue > 255)
        {
            color.Blue = 255;
        }

        return color;
    }
};