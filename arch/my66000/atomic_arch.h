#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
	long old, tmp;
	__asm__ __volatile__ (
	    "lduwl\t%0,[%2]\n\t"
	    "cmp\t%1,%0,%3\n\t"
	    "peq\t%1,T\n\t"
	    "stwl\t%4,[%2]"
		: "=&r"(old), "=&r"(tmp)
		: "r"(p), "r"(t), "r"(s)
		: "memory");
	return old;
}

#define a_cas_p a_cas_p
static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
	void *old;
	long tmp;
	__asm__ __volatile__ (
	    "lddl\t%0,[%2]\n\t"
	    "cmp\t%1,%0,%3\n\t"
	    "peq\t%1,T\n\t"
	    "stdl\t%4,[%2]"
		: "=&r"(old), "=&r"(tmp)
		: "r"(p), "r"(t), "r"(s)
		: "memory");
	return old;
}

#define a_crash a_crash
static inline void a_crash()
{
	__asm__ __volatile__ (".long 0");
}

#define a_clz_64 a_clz_64
static inline int a_clz_64(uint64_t x)
{
	__asm__ ("clz %0,%1" : "=r"(x) : "r"(x));
	return x;
}
