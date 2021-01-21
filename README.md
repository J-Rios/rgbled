# RGBLEDs

A C++ library to ease RGB LED usage with HAL emphasis to be used in different kind of devices and frameworks. 

## Supported Devices & Frameworks

Currently, just Arduino devices are compatible, however is simply to add support to other devices and frameworks.

## Adding new Device Support

To add a new device or framework support to library, yo just need to write the low level functionalities to control and interface with a RGB LED through the **hal_*()** private methods (hal_gpio_as_digital_output(), hal_gpio_low(), hal_gpio_high(), etc):

```cpp

// ...

// Device/Framework Libraries
#if defined(ARDUINO)
    #include <Arduino.h>
#elif defined(ESP_IDF)
    // Unimplemented
#elif defined(SAM_ASF)
    // Unimplemented
#elif defined(__AVR__)
    // Unimplemented
#endif

// ...

void RGBLED::hal_gpio_as_digital_output(const uint32_t gpio)
{
    #if defined(ARDUINO)
        pinMode(gpio, OUTPUT);
    #elif defined(ESP_IDF)
        // Unimplemented
    #elif defined(SAM_ASF)
        // Unimplemented
    #elif defined(__AVR__)
        // Unimplemented
    #endif

    this->gpios_initialized = true;
}

// ...

```

## Donation

[![paypal](https://www.paypal.com/en_US/i/btn/btn_donateCC_LG.gif)](https://paypal.me/josrios)

Do you like this project?

Please, considere making a donation.
