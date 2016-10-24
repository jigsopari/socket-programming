/*******************************************************
* Name: start
* Description:
*   This is where execution of this embedded system program begins.
*   This function initializes stack pointer and base pointer registers.
*   Next it calls root function, which i defined in root.c
*********************************************************************/
.text 

.globl _start
_start:
      cli
      movl $0, %ebp
      movl $0x3ffff0, %esp
      call root

/****************************************************************
* Name: inb
* Description:
*   Reads i/o ports and returns that value. From C language this 
*   function is called as "inb(ioPortAddrs)"   
*****************************************************************/
.globl inb
inb:
    
	movl 4 (%esp),%edx  /* move io address to edx register */
	xorl %eax, %eax    /*  clear eax register to zero */
	inb  %dx, %al
	ret

/***************************************************************
* Name: outb
* Description:
*   This function writes the given value to given i/o address using
*   "outb" assembly language instruction. This function is called
*   from C language as "outb(ioPortAddrs, value)"
****************************************************************/
.globl outb

outb:
	movl 4(%esp),%edx  /* move io address to edx register */
	movl 8(%esp),%eax  /* move value to eax register  */
	outb  %al, %dx 
	ret
