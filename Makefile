BUILD_DIR=build
T3D_INST=$(shell realpath ../..)

include $(N64_INST)/include/n64.mk
include $(N64_INST)/include/t3d.mk

N64_CFLAGS += -std=gnu2x -Os

src = main.c

all: pigeon_grabbing.z64

$(BUILD_DIR)/pigeon_grabbing.elf: $(src:%.c=$(BUILD_DIR)/%.o)

pigeon_grabbing.z64: N64_ROM_TITLE="Pigeon Grabbing"

clean:
	rm -rf $(BUILD_DIR) *.z64

build_lib:
	rm -rf $(BUILD_DIR) *.z64
	make -C $(T3D_INST)
	make all

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean