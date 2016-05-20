obj-y += cpu.o
obj-$(CONFIG_ARM_EXCEPTIONS) += exceptions.o
obj-$(CONFIG_ARM_EXCEPTIONS) += interrupts.o
obj-y += start.o entry.o

#
# Any variants can be called as start-armxyz.S
#
obj-$(CONFIG_CMD_ARM_CPUINFO) += cpuinfo.o
obj-$(CONFIG_CMD_ARM_MMUINFO) += mmuinfo.o
obj-$(CONFIG_MMU) += mmu.o cache.o

AFLAGS_cache-armv8.o       :=-Wa,-march=armv8-a
obj-$(CONFIG_CPU_64v8) += cache-armv8.o
AFLAGS_pbl-cache-armv8.o       :=-Wa,-march=armv8-a
pbl-$(CONFIG_CPU_64v8) += cache-armv8.o

pbl-y += setupc.o entry.o
pbl-$(CONFIG_PBL_SINGLE_IMAGE) += start-pbl.o
pbl-$(CONFIG_PBL_MULTI_IMAGES) += uncompress.o

obj-y += cache.o
pbl-y += cache.o

lwl-y += lowlevel.o
