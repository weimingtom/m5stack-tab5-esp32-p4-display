#
# Makefile
#
#CC = /home/wmt/work_licheepi_zero/gcc-linaro-6.3.1-2017.05-i686_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc
CC = gcc
LVGL_DIR_NAME ?= lvgl
LVGL_DIR ?= ${shell pwd}

#ubuntu140432
#sudo apt install libsdl2-dev

#or -std=gnu99 
#DT_DIR
CFLAGS ?= -std=c99 -O3 -g0 -I$(LVGL_DIR)/ -D_BSD_SOURCE
#-DUSE_FBDEV=1 -DUSE_EVDEV=1 
#-fsanitize=undefined
LDFLAGS ?= -lSDL2main -lm -lpthread -lpng -lSDL2 -fsanitize=address  -fno-omit-frame-pointer
BIN = demo


#Collect the files to compile
MAINSRC = ./main.c

include $(LVGL_DIR)/lvgl/lvgl.mk
include $(LVGL_DIR)/lv_drivers/lv_drivers.mk
#include $(LVGL_DIR)/lv_examples/lv_examples.mk
include $(LVGL_DIR)/ui/ui.mk

#CSRCS +=$(LVGL_DIR)/mouse_cursor_icon.c

OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS = $(AOBJS) $(COBJS)

## MAINOBJ -> OBJFILES

all: default

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"
    
default: $(AOBJS) $(COBJS) $(MAINOBJ)
	$(CC) -o $(BIN) $(MAINOBJ) $(AOBJS) $(COBJS) $(LDFLAGS)

clean: 
	rm -f $(BIN) $(AOBJS) $(COBJS) $(MAINOBJ)

run:
	sudo cp demo /media/wmt/50641143-6315-449a-b9e6-d8fe8b4d75aa/root/


