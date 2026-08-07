BUILD_DIR=build
T3D_INST=$(shell realpath ../..)

include $(N64_INST)/include/n64.mk
include $(N64_INST)/include/t3d.mk

N64_CFLAGS += -std=gnu2x -Os

src := $(shell find src -name '*.c')

assets_png = $(wildcard assets/*.png)
assets_gltf = $(wildcard assets/*.glb)
assets_xm = $(wildcard src/resources/audio/*.xm)
assets_conv = $(addprefix filesystem/,$(notdir $(assets_png:%.png=%.sprite))) \
			  $(addprefix filesystem/,$(notdir $(assets_ttf:%.ttf=%.font64))) \
			  $(addprefix filesystem/,$(notdir $(assets_gltf:%.glb=%.t3dm))) \
			  $(addprefix filesystem/,$(notdir $(assets_xm:%.xm=%.xm64)))

all: pigeon_grabbing.z64

filesystem/%.sprite: assets/%.png
	@mkdir -p $(dir $@)
	@echo "    [SPRITE] $@"
	$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o filesystem "$<"

filesystem/%.t3dm: assets/%.glb
	@mkdir -p $(dir $@)
	@echo "    [T3D-MODEL] $@"
	$(T3D_GLTF_TO_3D) "$<" $@
	$(N64_BINDIR)/mkasset -c 2 -o filesystem $@

filesystem/%.xm64: src/resources/audio/%.xm
	@mkdir -p $(dir $@)
	@echo "     [AUDIO] $@ $<"
	@echo "$<"
	audioconv64 --output filesystem $<
	mv $(notdir $@) $@

$(BUILD_DIR)/pigeon_grabbing.dfs: $(assets_conv)
$(BUILD_DIR)/pigeon_grabbing.elf: $(src:%.c=$(BUILD_DIR)/%.o)

pigeon_grabbing.z64: N64_ROM_TITLE="Pigeon Grabbing"
pigeon_grabbing.z64: $(BUILD_DIR)/pigeon_grabbing.dfs

clean:
	rm -rf $(BUILD_DIR) *.z64

build_lib:
	rm -rf $(BUILD_DIR) *.z64
	make -C $(T3D_INST)
	make all

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean