include tools/setup.mk

TARGET := tiny
MCU := msp430g2553
BUILD_DIR := ./build

# LINKER_SCRIPT := /home/ryan/toolchain/msp430-gcc-9.3.1.2/include/msp430g2553.ld

DEFINES := \

include tools/defaults.mk

# CPPFLAGS += -L/home/ryan/toolchain/msp430-gcc-9.3.1.2/include

CXXFLAGS += \

CPPFLAGS += \
  -flto \
  -fwhole-program \

SRC_DIRS := \
  src \
  src/hardware \

include lib/tiny/lib_tiny.mk

.PHONY: all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex
	@$(SIZE) $<

include tools/tools.mk
