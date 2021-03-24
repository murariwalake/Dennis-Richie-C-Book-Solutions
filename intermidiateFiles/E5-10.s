	.file	"E5-10.c"
	.comm	s,400,32
	.globl	t
	.bss
	.align 4
	.type	t, @object
	.size	t, 4
t:
	.zero	4
	.section	.rodata
	.align 8
.LC0:
	.string	"Usage: comand line reverse polish expression calculation"
.LC2:
	.string	"ERROR: divide by zero"
.LC3:
	.string	"enter the value of %c\n"
.LC4:
	.string	"%f"
.LC5:
	.string	"%f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -12(%rbp)
	cmpl	$1, -20(%rbp)
	jne	.L4
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L16
.L15:
	addl	$1, -12(%rbp)
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$43, %al
	jne	.L5
	call	pop
	movss	%xmm0, -40(%rbp)
	call	pop
	addss	-40(%rbp), %xmm0
	call	push
	jmp	.L4
.L5:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$45, %al
	jne	.L6
	call	pop
	movd	%xmm0, %eax
	movl	%eax, -16(%rbp)
	call	pop
	movaps	%xmm0, %xmm1
	movss	-16(%rbp), %xmm0
	subss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	call	push
	jmp	.L4
.L6:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$42, %al
	jne	.L7
	call	pop
	movss	%xmm0, -40(%rbp)
	call	pop
	mulss	-40(%rbp), %xmm0
	call	push
	jmp	.L4
.L7:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$47, %al
	jne	.L8
	call	pop
	movd	%xmm0, %eax
	movl	%eax, -16(%rbp)
	movss	-16(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L18
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	je	.L20
.L18:
	call	pop
	movaps	%xmm0, %xmm1
	movss	-16(%rbp), %xmm0
	divss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	call	push
	jmp	.L4
.L20:
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L16
.L8:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$37, %al
	jne	.L11
	call	pop
	movd	%xmm0, %eax
	movl	%eax, -16(%rbp)
	movss	-16(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L19
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	je	.L21
.L19:
	movss	-16(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm4
	movsd	%xmm4, -40(%rbp)
	call	pop
	cvtss2sd	%xmm0, %xmm0
	movsd	-40(%rbp), %xmm1
	call	fmod@PLT
	cvtsd2ss	%xmm0, %xmm0
	call	push
	jmp	.L4
.L21:
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	jmp	.L16
.L11:
	call	__ctype_b_loc@PLT
	movq	(%rax), %rdx
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	movsbq	%al, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$1024, %eax
	testl	%eax, %eax
	je	.L14
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-16(%rbp), %eax
	movl	%eax, -40(%rbp)
	movss	-40(%rbp), %xmm0
	call	push
	jmp	.L4
.L14:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atof@PLT
	cvtsd2ss	%xmm0, %xmm0
	call	push
.L4:
	subl	$1, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jne	.L15
	call	pop
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC5(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
.L16:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L17
	call	__stack_chk_fail@PLT
.L17:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC6:
	.string	"ERROR: stack is full, the value %f cannot be pushed\n"
	.text
	.globl	push
	.type	push, @function
push:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movss	%xmm0, -4(%rbp)
	movl	t(%rip), %eax
	cmpl	$99, %eax
	jg	.L23
	movl	t(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, t(%rip)
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	s(%rip), %rax
	movss	-4(%rbp), %xmm0
	movss	%xmm0, (%rdx,%rax)
	jmp	.L25
.L23:
	cvtss2sd	-4(%rbp), %xmm0
	leaq	.LC6(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
.L25:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	push, .-push
	.section	.rodata
	.align 8
.LC7:
	.string	"ERROR: stack is empty, cannot be popped any element"
	.text
	.globl	pop
	.type	pop, @function
pop:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	t(%rip), %eax
	testl	%eax, %eax
	jle	.L27
	movl	t(%rip), %eax
	subl	$1, %eax
	movl	%eax, t(%rip)
	movl	t(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	s(%rip), %rax
	movss	(%rdx,%rax), %xmm0
	jmp	.L28
.L27:
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	pxor	%xmm0, %xmm0
.L28:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	pop, .-pop
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
