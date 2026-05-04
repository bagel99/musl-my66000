#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

#define __asm_syscall(k, ...) \
	__asm__ __volatile__ ("svc\t#%1,#0" \
	: "=r"(r1) :  "i"(k), __VA_ARGS__ : "memory"); \
	return r1; \

static inline long __syscall0(long n)
{
	register long r8 __asm__("r8") = n;
	register long r1 __asm__("r1");
	__asm_syscall(0, "r"(r8))
}

static inline long __syscall1(long n, long a)
{
	register long r8 __asm__("r8") = n;
	register long r1 __asm__("r1") = a;
	__asm_syscall(1, "r"(r8), "0"(r1))
}

static inline long __syscall2(long n, long a, long b)
{
	register long r8 __asm__("r8") = n;
	register long r1 __asm__("r1") = a;
	register long r2 __asm__("r2") = b;
	__asm_syscall(2, "r"(r8), "0"(r1), "r"(r2))
}

static inline long __syscall3(long n, long a, long b, long c)
{
	register long r8 __asm__("r8") = n;
	register long r1 __asm__("r1") = a;
	register long r2 __asm__("r2") = b;
	register long r3 __asm__("r3") = c;
	__asm_syscall(3, "r"(r8), "0"(r1), "r"(r2), "r"(r3))
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
	register long r8 __asm__("r8") = n;
	register long r1 __asm__("r1") = a;
	register long r2 __asm__("r2") = b;
	register long r3 __asm__("r3") = c;
	register long r4 __asm__("r4") = d;
	__asm_syscall(4, "r"(r8), "0"(r1), "r"(r2), "r"(r3), "r"(r4))
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	register long r8 __asm__("r8") = n;
	register long r1 __asm__("r1") = a;
	register long r2 __asm__("r2") = b;
	register long r3 __asm__("r3") = c;
	register long r4 __asm__("r4") = d;
	register long r5 __asm__("r5") = e;
	__asm_syscall(5, "r"(r8), "0"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5))
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	register long r8 __asm__("r8") = n;
	register long r1 __asm__("r1") = a;
	register long r2 __asm__("r2") = b;
	register long r3 __asm__("r3") = c;
	register long r4 __asm__("r4") = d;
	register long r5 __asm__("r5") = e;
	register long r6 __asm__("r6") = f;
	__asm_syscall(6, "r"(r8), "0"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5), "r"(r6))
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_4.15"

#define IPC_64 0
