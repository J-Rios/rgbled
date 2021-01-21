/**
 * @file    basic_usage.ino
 * @author  Jose Miguel Rios Rubio <jrios.github@gmail.com>
 * @date    21-01-2021
 * @version 1.0.0
 *
 * @section DESCRIPTION
 *
 * RGBLED library basic usage example.
 *
 * @section LICENSE
 *
 * Copyright (c) 2021 Jose Miguel Rios Rubio. All right reserved.
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

// Device Framework libraries
#include <Arduino.h>

// Custom libraries
#include <rgbled.h>

/**************************************************************************************************/

/* Defines, Macros, Constants and Types */

// I/O pins defines
#define IO_O_RGBLED_R 6
#define IO_O_RGBLED_G 7
#define IO_O_RGBLED_B 8

/*****************************************************************************/

/* Global Elements */

// RGB LED
RGBLED LED_RGB(IO_O_RGBLED_R, IO_O_RGBLED_G, IO_O_RGBLED_B);

/**************************************************************************************************/

/* Setup & Loop */

void setup()
{
    LED_RGB.setup();
}

void loop()
{
    LED_RGB.red();
    delay(1000);
    LED_RGB.green();
    delay(1000);
    LED_RGB.blue();
    delay(1000);
    LED_RGB.yellow();
    delay(1000);
    LED_RGB.cyan();
    delay(1000);
    LED_RGB.magenta();
    delay(1000);
    LED_RGB.white();
    delay(1000);
    LED_RGB.off();
    delay(3000);
}
