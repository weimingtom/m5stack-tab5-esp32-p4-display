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

#define USE_SQUARELINE 1
#define USE_PYTHON_GEN_IMAGE 1

#if USE_SQUARELINE
#include "export/ui.h"

LV_IMG_DECLARE(ui_img_pic0001);
LV_IMG_DECLARE(ui_img_pic0002);
LV_IMG_DECLARE(ui_img_pic0003);
LV_IMG_DECLARE(ui_img_pic0004);
LV_IMG_DECLARE(ui_img_pic0005);


static uint8_t pic_num = 1;
//static void screen_img_num4event_handler(lv_obj_t * obj, lv_event_t event)
static void screen_img_num4event_handler(lv_event_t * e)
{
	//switch (event)
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
				pic_num ++;
#if !USE_PYTHON_GEN_IMAGE
				if(pic_num == 6) pic_num = 1;
				switch (pic_num)
				{					
						case 1:
							lv_img_set_src(ui_Image4,&ui_img_pic001_png);
							break;
						case 2:
							lv_img_set_src(ui_Image4,&ui_img_pic002_png);
							break;
						case 3:
							lv_img_set_src(ui_Image4,&ui_img_pic003_png);
							break;
						case 4:
							lv_img_set_src(ui_Image4,&ui_img_pic004_png);
							break;
						case 5:
							lv_img_set_src(ui_Image4,&ui_img_pic005_png);
							break;		
#else
				if(pic_num == 4) pic_num = 1;
				switch (pic_num)
				{					
						case 1:
							lv_img_set_src(ui_Image4,&ui_img_pic0002);
							break;
						case 2:
							lv_img_set_src(ui_Image4,&ui_img_pic0003);
							break;
						case 3:
							lv_img_set_src(ui_Image4,&ui_img_pic0004);
							break;
#endif
						default:
							break;
				}
	}
		break;
	default:
		break;
	}
}
#else
extern void example_lvgl_demo_ui(lv_obj_t *scr);
#endif

lv_disp_t *lvDisp = NULL;
void app_main(void)
{
    lvDisp = bsp_display_start();

    ESP_LOGI("example", "Display LVGL animation");
    bsp_display_lock(0);
#if USE_SQUARELINE
    lv_disp_set_rotation(lvDisp, LV_DISPLAY_ROTATION_90); //FIXME:rotate, or use bsp_display_rotate=lv_disp_set_rotation
#else
    lv_obj_t *scr = lv_disp_get_scr_act(NULL);
#endif
#if (CONFIG_ESP_LCD_TOUCH_MAX_POINTS > 1 && CONFIG_LV_USE_GESTURE_RECOGNITION)
    lv_indev_t *indev = bsp_display_get_input_dev();
    lv_indev_set_rotation_rad_threshold(indev, 0.15f);
#endif
#if USE_SQUARELINE
#if 1
        ui_init();
#if USE_PYTHON_GEN_IMAGE
		lv_img_set_src(ui_Image4,&ui_img_pic0002);
#endif
        //lv_obj_set_event_cb(ui_Screen1, screen_img_num4event_handler);
        lv_obj_add_event_cb(ui_Screen1, screen_img_num4event_handler, LV_EVENT_ALL, NULL);
#else
    lv_demo_widgets();      /* A widgets example */
    //lv_demo_music();        /* A modern, smartphone-like music player demo. */
    // lv_demo_stress();       /* A stress test for LVGL. */
    // lv_demo_benchmark();    /* A demo to measure the performance of LVGL or to compare different settings. */
#endif	
#else
    example_lvgl_demo_ui(scr);
#endif

    bsp_display_unlock();
    bsp_display_backlight_on();
}
