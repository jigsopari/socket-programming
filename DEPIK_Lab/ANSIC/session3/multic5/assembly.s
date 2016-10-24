	.file	"assembly.c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	call	testFunc
	leave
	ret
	.size	main, .-main
	.section	.rodata
.LC0:
	.string	"average=%d\n"
	.text
.globl testFunc
	.type	testFunc, @function
testFunc:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$20, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	addl	-4(%ebp), %eax
	movl	%eax, -12(%ebp)
	subl	$4, %esp
	pushl	-12(%ebp)
	pushl	-8(%ebp)
	pushl	-4(%ebp)
	call	average
	addl	$16, %esp
	movl	%eax, sum
	subl	$8, %esp
	pushl	sum
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	leave
	ret
	.size	testFunc, .-testFunc
.globl average
	.type	average, @function
average:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	12(%ebp), %eax
	addl	8(%ebp), %eax
	movl	%eax, %ecx
	addl	16(%ebp), %ecx
	movl	$1431655766, %eax
	imull	%ecx
	sarl	$31, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.size	average, .-average
	.comm	sum,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.3 20040412 (Red Hat Linux 3.3.3-7)"
