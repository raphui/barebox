#ifndef __ASM_CACHE_H
#define __ASM_CACHE_H

static inline void flush_icache(void)
{
	v8_invalidate_icache_all();
}

int arm_set_cache_functions(void);

void arm_early_mmu_cache_flush(void);
void arm_early_mmu_cache_invalidate(void);

#endif
