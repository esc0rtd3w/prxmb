SCETOOL_FLAGS := -0 SELF
SCETOOL_FLAGS += -1 TRUE
SCETOOL_FLAGS += -s FALSE
SCETOOL_FLAGS += -2 04
SCETOOL_FLAGS += -3 1070000052000001
SCETOOL_FLAGS += -4 01000002
SCETOOL_FLAGS += -5 APP
SCETOOL_FLAGS += -A 0001000000000000
SCETOOL_FLAGS += -6 0003004000000000

CELL_SDK ?= /usr/local/cell
CELL_MK_DIR ?= $(CELL_SDK)/samples/mk
include $(CELL_MK_DIR)/sdk.makedef.mk

OBJS_DIR = .

PPU_SRCS = $(wildcard *.c)
PPU_PRX_TARGET = prxmb_proxy.prx
PPU_CFLAGS += -Wno-unused-parameter -ffunction-sections -fdata-sections -fno-builtin-printf

PPU_PRX_LDFLAGS += -Wl,--strip-unused-data -nodefaultlibs
PPU_PRX_LDLIBDIR += -L../ -L../vsh/lib

PPU_PRX_LDLIBS += -lprxmb_prx
PPU_PRX_LDLIBS += -lpaf_export_stub -lsysPrxForUser_export_stub -lvshtask_export_stub

PPU_OPTIMIZE_LV = -Os
PPU_INCDIRS += -I. -I../ -I../vsh/include -I../include

all: $(PPU_PRX_TARGET)
	$(PPU_PRX_STRIP) --strip-debug --strip-section-header $<
	scetool $(SCETOOL_FLAGS) -e $< $(PPU_SPRX_TARGET)

include $(CELL_MK_DIR)/sdk.target.mk
