	.file	"array.c"
	.section	.rodata
	.align 4
.LC0:
	.long	70
	.long	65
	.long	89
	.long	45
	.long	32
	.long	58
	.long	91
	.long	83
	.long	28
	.long	59
	.long	66
	.long	60
	.long	45
	.long	38
	.long	78
	.long	68
.LC1:
	.string	"average=%d"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	subl	$80, %esp
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	leal	-88(%ebp), %edi
	movl	$.LC0, %esi
	cld
	movl	$16, %eax
	movl	%eax, %ecx
	rep
	movsl
	subl	$8, %esp
	pushl	$16
	leal	-88(%ebp), %eax
	pushl	%eax
	call	avgMark
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	subl	$8, %esp
	pushl	-12(%ebp)
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	leal	-8(%ebp), %esp
	popl	%esi
	popl	%edi
	leave
	ret
	.size	main, .-main
.globl avgMark
	.type	avgMark, @function
avgMark:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -12(%ebp)
	movl	$0, -8(%ebp)
.L3:
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	.L6
	jmp	.L4
.L6:
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	leal	-12(%ebp), %eax
	addl	%edx, (%eax)
	addl	$4, 8(%ebp)
	leal	-8(%ebp), %eax
	incl	(%eax)
	jmp	.L3
.L4:
	movl	-12(%ebp), %edx
	leal	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	%edx, %eax
	movl	-16(%ebp), %ecx
	cltd
	idivl	(%ecx)
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.size	avgMark, .-avgMark
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.3 20040412 (Red Hat Linux 3.3.3-7)"
