/*
 * SPDX-FileCopyrightText: 2021-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

/**
 * @file
 * @brief BSP Display Example
 * @details Show an image on the screen with a simple startup animation (LVGL)
 * @example https://espressif.github.io/esp-launchpad/?flashConfigURL=https://espressif.github.io/esp-bsp/config.toml&app=display-
 */

#include <stdio.h>
#include "bsp/esp-bsp.h"
#include "lvgl.h"
#include "esp_log.h"
#include "lv_demos.h"

#include "export/ui.h"

lv_disp_t *lvDisp = NULL;
void app_main(void)
{
    lvDisp = bsp_display_start();

    ESP_LOGI("example", "Display LVGL animation");
    bsp_display_lock(0);
    
	lv_disp_set_rotation(lvDisp, LV_DISPLAY_ROTATION_90); //FIXME:rotate, or use bsp_display_rotate=lv_disp_set_rotation
	
#if (CONFIG_ESP_LCD_TOUCH_MAX_POINTS > 1 && CONFIG_LV_USE_GESTURE_RECOGNITION)
    lv_indev_t *indev = bsp_display_get_input_dev();
    lv_indev_set_rotation_rad_threshold(indev, 0.15f);
#endif

    ui_init();
    //lv_demo_widgets();      /* A widgets example */
    //lv_demo_music();        /* A modern, smartphone-like music player demo. */
    // lv_demo_stress();       /* A stress test for LVGL. */
    // lv_demo_benchmark();    /* A demo to measure the performance of LVGL or to compare different settings. */

    bsp_display_unlock();
    bsp_display_backlight_on();
}
