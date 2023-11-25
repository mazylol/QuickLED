#include <Arduino.h>

/// @brief A class to control LEDs.
class Led
{
public:
    /// @brief LED struct.
    typedef struct
    {
        const int Pin;

        /// @brief Convenience method to setup the pin for the LED.
        void setup()
        {
            pinMode(Pin, OUTPUT);
        }

        /// @brief Sets the value (brightness) of the LED.
        /// @param value
        void set(unsigned int value)
        {
            value = validateBrightness(value);

            analogWrite(Pin, value);
        }
    } LED;

    /// @brief Creates a new LED struct.
    static LED create(int pin)
    {
        return LED{.Pin = pin};
    }

    /// @brief Contains effects for the LED.
    class Effects
    {
    public:
        /// @brief Blink the LED.
        /// @param led
        /// @param delayMs
        static void blink(LED led, unsigned int maxBrightness, int delayMs)
        {
            maxBrightness = validateBrightness(maxBrightness);

            led.set(maxBrightness);
            delay(delayMs);
            led.set(0);
            delay(delayMs);
        }

        /// @brief Fade the LED out.
        /// @param led
        /// @param delayMs
        static void fadeOut(LED led, int delayMs)
        {
            for (unsigned int i = 255; i >= 0; i--)
            {
                led.set(i);
                delay(delayMs);
            }
        }

        /// @brief Fade the LED in.
        /// @param led
        /// @param delayMs
        static void fadeIn(LED led, int delayMs)
        {
            for (unsigned int i = 0; i <= 255; i++)
            {
                led.set(i);
                delay(delayMs);
            }
        }
    };

private:
    /// @brief Validates and corrects the brightness value.
    static unsigned int validateBrightness(unsigned int brightness)
    {
        if (brightness > 255)
            brightness = 255;

        return brightness;
    }
};