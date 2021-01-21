
/**
 * @file    rgbled.h
 * @author  Jose Miguel Rios Rubio <jrios.github@gmail.com>
 * @date    21-01-2021
 * @version 1.0.0
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

/* Include Guard */

#ifndef RGBLED_H_
#define RGBLED_H_

/*****************************************************************************/

/* Libraries */

// Standard C/C++ libraries
#include <stdint.h>
#include <stdbool.h>

/*****************************************************************************/

class RGBLED
{
    public:
        RGBLED(const uint32_t pin_r, const uint32_t pin_g, const uint32_t pin_b);

        void setup(void);
        void off(void);

        void red(void);
        void green(void);
        void blue(void);
        void yellow(void);
        void cyan(void);
        void magenta(void);
        void white(void);

    private:
        uint32_t pin_r, pin_g, pin_b;
        bool gpios_initialized;

        bool gpios_are_not_initialized(void);

        void hal_gpio_as_digital_output(const uint32_t gpio);
        void hal_gpio_low(const uint32_t gpio);
        void hal_gpio_high(const uint32_t gpio);
};

/*****************************************************************************/

#endif /* RGBLED_H_ */
