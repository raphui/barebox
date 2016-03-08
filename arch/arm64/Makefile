
CPPFLAGS	+= -D__ARM__ -fno-strict-aliasing
CPPFLAGS	+=$(call cc-option,-maarch64,)

ifeq ($(CONFIG_CPU_BIG_ENDIAN),y)
CPPFLAGS	+= -mbig-endian
AS		+= -EB
LD		+= -EB
else
CPPFLAGS	+= -mlittle-endian
AS		+= -EL
LD		+= -EL
endif

# This selects which instruction set is used.
# Note that GCC does not numerically define an architecture version
# macro, but instead defines a whole series of macros which makes
# testing for a specific architecture or later rather impossible.
arch-$(CONFIG_CPU_64v8)		:= -D__LINUX_ARM_ARCH__=8 $(call cc-option,-march=armv8-a)

CFLAGS_ABI	:=-mabi=lp64

ifeq ($(CONFIG_ARM_UNWIND),y)
CFLAGS_ABI	+=-funwind-tables
endif

CPPFLAGS += $(CFLAGS_ABI) $(arch-y) $(tune-y) 

AFLAGS   += -include asm/unified.h

# Machine directory name.  This list is sorted alphanumerically
# by CONFIG_* macro name.
machine-$(CONFIG_ARCH_VEXPRESS)		:= vexpress


machdirs := $(patsubst %,arch/arm64/mach-%/,$(machine-y))

ifeq ($(KBUILD_SRC),)
CPPFLAGS += $(patsubst %,-I%include,$(machdirs))
else
CPPFLAGS += $(patsubst %,-I$(srctree)/%include,$(machdirs))
endif

TEXT_BASE = $(CONFIG_TEXT_BASE)

CPPFLAGS += -DTEXT_BASE=$(TEXT_BASE)

# Add cleanup flags
CPPFLAGS += -fdata-sections -ffunction-sections
LDFLAGS_barebox += --gc-sections

ifdef CONFIG_RELOCATABLE
LDFLAGS_barebox += -pie
else
LDFLAGS_barebox += -static
endif

ifdef CONFIG_IMAGE_COMPRESSION
KBUILD_BINARY := arch/arm64/pbl/zbarebox.bin
else
KBUILD_BINARY := barebox.bin
endif

barebox.netx: $(KBUILD_BINARY)
	$(Q)scripts/gen_netx_image -i $< -o barebox.netx		\
		--sdramctrl=$(CONFIG_NETX_SDRAM_CTRL)			\
		--sdramtimctrl=$(CONFIG_NETX_SDRAM_TIMING_CTRL)		\
		--memctrl=$(CONFIG_NETX_MEM_CTRL)			\
		--entrypoint=$(CONFIG_TEXT_BASE)			\
		--cookie=$(CONFIG_NETX_COOKIE);

ifeq ($(machine-y),netx)
KBUILD_IMAGE := barebox.netx
endif

barebox.s5p: $(KBUILD_BINARY)
	$(Q)scripts/s5p_cksum $< barebox.s5p

boarddir = $(srctree)/arch/arm64/boards

pbl := arch/arm64/pbl
$(pbl)/zbarebox.S $(pbl)/zbarebox.bin $(pbl)/zbarebox: barebox.bin FORCE
	$(Q)$(MAKE) $(build)=$(pbl) $@

archclean:
	$(MAKE) $(clean)=$(pbl)

dts := arch/arm64/dts

%.dtb: scripts
	$(Q)$(MAKE) $(build)=$(dts) $(dts)/$@

KBUILD_IMAGE ?= $(KBUILD_BINARY)

archprepare: maketools
maketools:
	$(Q)$(MAKE) $(build)=arch/arm64/tools include/generated/mach-types.h

PHONY += maketools

ifneq ($(board-y),)
BOARD := arch/arm64/boards/$(board-y)/
else
BOARD :=
endif

ifneq ($(machine-y),)
MACH := arch/arm64/mach-$(machine-y)/
else
MACH :=
endif

common-y += $(BOARD) arch/arm64/boards/ $(MACH)
common-y += arch/arm64/lib/ arch/arm64/cpu/

common-$(CONFIG_OFTREE) += arch/arm64/dts/

lds-y	:= arch/arm64/lib/barebox.lds

common- += $(patsubst %,arch/arm64/boards/%/,$(board-))

CLEAN_FILES += include/generated/mach-types.h arch/arm64/lib/barebox.lds barebox-flash-image
