.text

.globl _sysInint

_sysInit:
	cli
	movl $0,%ebp
	movl $0x3ffff0,%esp
        call usrInit
	int  $3
	ret

















