idf_component_register(SRCS "main.c" "lvgl_demo_ui.c"
	export/screens/ui_Screen1.c
    export/ui.c
    export/components/ui_comp_hook.c
    export/ui_helpers.c
    export/images/ui_img_pic001_png.c
    export/images/ui_img_pic002_png.c
    export/images/ui_img_pic003_png.c
    export/images/ui_img_pic004_png.c
    export/images/ui_img_pic005_png.c

    images/gen/ui_img_pic0001.c
    images/gen/ui_img_pic0002.c
    images/gen/ui_img_pic0003.c
    images/gen/ui_img_pic0004.c
    images/gen/ui_img_pic0005.c
	
	INCLUDE_DIRS "." "./export")

lvgl_port_create_c_image("images/esp_logo.png" "images/gen/" "ARGB8888" "NONE")
lvgl_port_create_c_image("images/esp_text.png" "images/gen/" "ARGB8888" "NONE")

#used
#lvgl_port_create_c_image("images/ui_img_pic0001.png" "images/gen/" "ARGB8888" "NONE")
#lvgl_port_create_c_image("images/ui_img_pic0002.png" "images/gen/" "ARGB8888" "NONE")
#lvgl_port_create_c_image("images/ui_img_pic0003.png" "images/gen/" "ARGB8888" "NONE")
#lvgl_port_create_c_image("images/ui_img_pic0004.png" "images/gen/" "ARGB8888" "NONE")
#lvgl_port_create_c_image("images/ui_img_pic0005.png" "images/gen/" "ARGB8888" "NONE")

#not used
#lvgl_port_create_c_image("images/ui_img_pic001_png.png" "export/images/" "ARGB8888" "NONE")
#lvgl_port_create_c_image("images/ui_img_pic002_png.png" "export/images/" "ARGB8888" "NONE")
#lvgl_port_create_c_image("images/ui_img_pic003_png.png" "export/images/" "ARGB8888" "NONE")
#lvgl_port_create_c_image("images/ui_img_pic004_png.png" "export/images/" "ARGB8888" "NONE")
#lvgl_port_create_c_image("images/ui_img_pic005_png.png" "export/images/" "ARGB8888" "NONE")

lvgl_port_add_images(${COMPONENT_LIB} "images/gen/")
