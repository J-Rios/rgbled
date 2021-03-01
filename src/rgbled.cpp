
/**
 * @file    rgbled.cpp
 * @author  Jose Miguel Rios Rubio <jrios.github@gmail.com>
 * @date    21-01-2021
 * @version 1.0.1
 *
 * @section DESCRIPTION
 *
 * RGB LEDs ease control class.
 *
 * @section LICENSE
 *
 * Copyright (c) 2020 Jose Miguel Rios Rubio. All right reserved.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

/*****************************************************************************/

/* Libraries */

// Header Interface
#include "rgbled.h"

// Device/Framework Libraries
#if defined(ARDUINO)
    #include <Arduino.h>
#elif defined(PICO_BOARD)
    #include "hardware/gpio.h"
#elif defined(ESP_IDF)
    // Unimplemented
#elif defined(SAM_ASF)
    // Unimplemented
#elif defined(__AVR__)
    // Unimplemented
#else
    #warning "Unsupported device"
#endif

/*****************************************************************************/

/* Constructor */

/**
  * @brief  Constructor, get GPIO pins numbers to be used for the RGB LED.
  * @param  pin_r GPIO pin number for RGB Red LED control.
  * @param  pin_g GPIO pin number for RGB Green LED control.
  * @param  pin_b GPIO pin number for RGB Blue LED control.
  */
RGBLED::RGBLED(const uint32_t pin_r, const uint32_t pin_g, const uint32_t pin_b)
{
    this->pin_r = pin_r;
    this->pin_g = pin_g;
    this->pin_b = pin_b;
    this->gpios_initialized = false;
}

/*****************************************************************************/

/* Public Methods */

/**
  * @brief  Initialize RGB GPIOs as outputs and set them to HIGH (LED off).
  */
void RGBLED::setup(void)
{
    hal_gpio_as_digital_output(this->pin_r);
    hal_gpio_as_digital_output(this->pin_g);
    hal_gpio_as_digital_output(this->pin_b);
    hal_gpio_high(this->pin_r);
    hal_gpio_high(this->pin_g);
    hal_gpio_high(this->pin_b);
}

/**
  * @brief  Turn OFF the RGB LED.
  */
void RGBLED::off(void)
{
    hal_gpio_high(this->pin_r);
    hal_gpio_high(this->pin_g);
    hal_gpio_high(this->pin_b);
}

/**
  * @brief  Set RGB LED to Red color.
  */
void RGBLED::red(void)
{
    hal_gpio_low(this->pin_r);
    hal_gpio_high(this->pin_g);
    hal_gpio_high(this->pin_b);
}

/**
  * @brief  Set RGB LED to Green color.
  */
void RGBLED::green(void)
{
    hal_gpio_high(this->pin_r);
    hal_gpio_low(this->pin_g);
    hal_gpio_high(this->pin_b);
}

/**
  * @brief  Set RGB LED to Blue color.
  */
void RGBLED::blue(void)
{
    hal_gpio_high(this->pin_r);
    hal_gpio_high(this->pin_g);
    hal_gpio_low(this->pin_b);
}

/**
  * @brief  Set RGB LED to Yellow color.
  */
void RGBLED::yellow(void)
{
    hal_gpio_low(this->pin_r);
    hal_gpio_low(this->pin_g);
    hal_gpio_high(this->pin_b);
}

/**
  * @brief  Set RGB LED to Cyan color.
  */
void RGBLED::cyan(void)
{
    hal_gpio_high(this->pin_r);
    hal_gpio_low(this->pin_g);
    hal_gpio_low(this->pin_b);
}

/**
  * @brief  Set RGB LED to Magenta color.
  */
void RGBLED::magenta(void)
{
    hal_gpio_low(this->pin_r);
    hal_gpio_high(this->pin_g);
    hal_gpio_low(this->pin_b);
}

/**
  * @brief  Set RGB LED to White color.
  */
void RGBLED::white(void)
{
    hal_gpio_low(this->pin_r);
    hal_gpio_low(this->pin_g);
    hal_gpio_low(this->pin_b);
}

/*****************************************************************************/

/* Private Methods */

/**
  * @brief  Check if needed GPIOs are initialized.
  * @return If all needed GPIOs are initialized (true or false).
  */
bool RGBLED::gpios_are_not_initialized(void)
{
    return (this->gpios_initialized == false);
}

/*****************************************************************************/

/* Specific Device/Framework HAL functions */

/**
  * @brief  Set the provided GPIO as Digital Output.
  * @param  gpio GPIO pin number to setup.
  */
void RGBLED::hal_gpio_as_digital_output(const uint32_t gpio)
{
    #if defined(ARDUINO)
        pinMode(gpio, OUTPUT);
    #elif defined(PICO_BOARD)
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    #elif defined(ESP_IDF)
        // Unimplemented
    #elif defined(SAM_ASF)
        // Unimplemented
    #elif defined(__AVR__)
        // Unimplemented
    #endif

    this->gpios_initialized = true;
}

/**
  * @brief  Set the provided digital output GPIO to LOW.
  * @param  gpio GPIO pin number to set the logic level.
  */
void RGBLED::hal_gpio_low(const uint32_t gpio)
{
    // Do nothing if GPIOS has not been initialized
    if(gpios_are_not_initialized())
        return;
    
    // Set LED GPIOs logic levels for this color
    #if defined(ARDUINO)
        digitalWrite(gpio, LOW);
    #elif defined(PICO_BOARD)
        gpio_put(gpio, 0);
    #elif defined(ESP_IDF)
        // Unimplemented
    #elif defined(SAM_ASF)
        // Unimplemented
    #elif defined(__AVR__)
        // Unimplemented
    #endif
}

/**
  * @brief  Set the provided digital output GPIO to HIGH.
  * @param  gpio GPIO pin number to set the logic level.
  */
void RGBLED::hal_gpio_high(const uint32_t gpio)
{
    // Do nothing if GPIOS has not been initialized
    if(gpios_are_not_initialized())
        return;

    #if defined(ARDUINO)
        digitalWrite(gpio, HIGH);
    #elif defined(PICO_BOARD)
        gpio_put(gpio, 1);
    #elif defined(ESP_IDF)
        // Unimplemented
    #elif defined(SAM_ASF)
        // Unimplemented
    #elif defined(__AVR__)
        // Unimplemented
    #endif
}
