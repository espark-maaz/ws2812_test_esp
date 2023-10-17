/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "led.h"
#include "status.h"
#include "config.h"


void app_main(void)
{
    printf("Hello world!\n");
	status_init();
    config_init();
    led_on();
	config_update_channels(); 	
    vTaskDelay(1000/portTICK_PERIOD_MS);
    config_setMode(FX_MODE_STATIC);
    int count = 21;
    while (1)
    {
        printf("Hello world!\n");
        vTaskDelay(10000/portTICK_PERIOD_MS);
        config_setMode(count);
        count++;
        if(count>66){
            count = 0;
        }
    }
    

}
