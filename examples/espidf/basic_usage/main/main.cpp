/**
 * @file    basic_usage.ino
 * @author  Jose Miguel Rios Rubio <jrios.github@gmail.com>
 * @date    01-03-2021
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

// Standard libraries
#include <stdio.h>
#include <stdlib.h>

// Device Framework libraries
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

// Custom libraries
#include <rgbled.h>

/*****************************************************************************/

/* Defines, Macros, Constants and Types */

// I/O pins defines
#define IO_O_RGBLED_R GPIO_NUM_6
#define IO_O_RGBLED_G GPIO_NUM_7
#define IO_O_RGBLED_B GPIO_NUM_8

static const char *TAG = "RGBLED";

/*****************************************************************************/

/* Functions Prototypes */

extern "C" { void app_main(void); }
void task_rgb(void *arg);

/*****************************************************************************/

/* Main Function */

void app_main(void)
{
    RGBLED LED_RGB(IO_O_RGBLED_R, IO_O_RGBLED_G, IO_O_RGBLED_B);

    // Initialialize RGB LED controller
    LED_RGB.setup();

    // Tasks creation
    ESP_LOGI(TAG, "Initializing Tasks...");
    if (xTaskCreate(task_rgb, "rgb_task", 2048, (void*)(&LED_RGB),
            tskIDLE_PRIORITY+5, NULL) != pdPASS)
    {
        ESP_LOGE(TAG, "Can't create RGB task (not enough memory?)");
        ESP_LOGI(TAG, "Rebooting the system...");
        esp_restart();
    }

    // Main Task Loop
    while (1)
    {
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

void task_rgb(void* arg)
{
    RGBLED* LED_RGB = (RGBLED*)arg;

    ESP_LOGI(TAG, "RGB Task started");

    while (1)
    {
        LED_RGB->red();
        vTaskDelay(1000/portTICK_RATE_MS);
        LED_RGB->green();
        vTaskDelay(1000/portTICK_RATE_MS);
        LED_RGB->blue();
        vTaskDelay(1000/portTICK_RATE_MS);
        LED_RGB->yellow();
        vTaskDelay(1000/portTICK_RATE_MS);
        LED_RGB->cyan();
        vTaskDelay(1000/portTICK_RATE_MS);
        LED_RGB->magenta();
        vTaskDelay(1000/portTICK_RATE_MS);
        LED_RGB->white();
        vTaskDelay(1000/portTICK_RATE_MS);
        LED_RGB->off();
        vTaskDelay(3000/portTICK_RATE_MS);

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}
