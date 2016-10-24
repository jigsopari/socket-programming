	.file	"root.c"
	.text
.globl getchar
	.type	getchar, @function
getchar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	nop
.L2:
	subl	$12, %esp
	pushl	$16349
	call	inb
	addl	$16, %esp
	andl	$1, %eax
	testl	%eax, %eax
	je	.L2
	subl	$12, %esp
	pushl	$16344
	call	inb
	addl	$16, %esp
	movb	%al, -1(%ebp)
	movzbl	-1(%ebp), %eax
	leave
	ret
	.size	getchar, .-getchar
.globl putchar
	.type	putchar, @function
putchar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movb	%al, -1(%ebp)
.L6:
	subl	$12, %esp
	pushl	$0
	call	inb
	addl	$16, %esp
	testl	%eax, %eax
	je	.L6
	subl	$8, %esp
	movzbl	-1(%ebp), %eax
	pushl	%eax
	pushl	$16344
	call	outb
	addl	$16, %esp
	leave
	ret
	.size	putchar, .-putchar
.globl puts
	.type	puts, @function
puts:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	nop
.L10:
	movl	8(%ebp), %eax
	cmpb	$0, (%eax)
	jne	.L12
	jmp	.L9
.L12:
	subl	$12, %esp
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	pushl	%eax
	incl	8(%ebp)
	call	putchar
	addl	$16, %esp
	jmp	.L10
.L9:
	leave
	ret
	.size	puts, .-puts
	.section	.rodata
.LC0:
	.string	"First embedded program\n\r"
	.text
.globl root
	.type	root, @function
root:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	subl	$12, %esp
	pushl	$.LC0
	call	puts
	addl	$16, %esp
.L14:
	call	getchar
	movb	%al, -1(%ebp)
	subl	$12, %esp
	movzbl	-1(%ebp), %eax
	pushl	%eax
	call	putchar
	addl	$16, %esp
	cmpb	$3, -1(%ebp)
	jne	.L14
	leave
	ret
	.size	root, .-root
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.3 20040412 (Red Hat Linux 3.3.3-7)"
