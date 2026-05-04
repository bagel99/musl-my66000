__asm__(
".text\n"
".weak _DYNAMIC \n"
".hidden _DYNAMIC \n"
".globl " START "\n"
".type " START ",%function\n"
START ":\n"
"	mov r1,sp\n"
"	mov r30,#0\n"
"	call " START "_c \n"
);
