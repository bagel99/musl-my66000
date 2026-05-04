static inline uintptr_t __get_tp()
{
	register uintptr_t tp __asm__("r16");
	__asm__ ("" : "=r" (tp) );
	return tp;
}


// the kernel calls the ip "nip", it's the first saved value after the 32
// GPRs.
#define MC_PC gp_regs[32]
