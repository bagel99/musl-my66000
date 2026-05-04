#define LDSO_ARCH "my66000"

#define TPOFF_K 0

#define REL_SYMBOLIC    R_MY66000_64
#define REL_RELATIVE    R_MY66000_PCREL64

#define CRTJMP(pc,sp) __asm__ __volatile__( \
	"mov sp,%1\n\tjmpx [%0]" : : "r"(pc), "r"(sp) : "memory" )

// FIXME - the following is wrong, just to get things to compile
#define GETFUNCSYM(fp, sym, got) __asm__ ( \
	".hidden " #sym "\n" \
	"la %0,[ip," #sym "]\n" \
	: "=r"(*fp) : : "memory" )
