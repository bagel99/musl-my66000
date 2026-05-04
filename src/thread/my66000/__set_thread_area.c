#include "pthread_impl.h"

int __set_thread_area(void *p)
{
	register long r16 __asm__("r16");
	__asm__ __volatile__ ("mov %0,%1" : "=r"(r16) : "r"(p));
	return 0;
}
