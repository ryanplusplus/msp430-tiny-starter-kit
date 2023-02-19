include tools/setup.mk

TARGET := tiny
MCU := msp430g2553
BUILD_DIR := ./build

MSPDEBUG_DEVICE ?= tilib

DEFINES := \

include tools/defaults.mk

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
