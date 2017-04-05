	.file	"loop.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"%f "
	.section	.text.unlikely,"ax",@progbits
.LCOLDB3:
	.section	.text.startup,"ax",@progbits
.LHOTB3:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB38:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movl	$1, %esi
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	$4000000, %edi
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	call	calloc
	movl	$1, %esi
	movl	$8000000, %edi
	movq	%rax, %rbx
	call	calloc
	movq	%rax, %rbp
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L2:
	movl	%eax, (%rbx,%rax,4)
	addq	$1, %rax
	cmpq	$1000000, %rax
	jne	.L2
	movsd	.LC0(%rip), %xmm3
	movl	$1000, %ecx
	movsd	.LC1(%rip), %xmm2
	.p2align 4,,10
	.p2align 3
.L5:
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L4:
	movl	(%rbx,%rdx), %eax
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sd	%eax, %xmm0
	leal	(%rax,%rax,4), %eax
	leal	(%rax,%rax,4), %eax
	cvtsi2sd	%eax, %xmm1
	mulsd	%xmm3, %xmm0
	addsd	%xmm1, %xmm0
	addsd	%xmm2, %xmm0
	movsd	%xmm0, 0(%rbp,%rdx,2)
	addq	$4, %rdx
	cmpq	$4000000, %rdx
	jne	.L4
	subl	$1, %ecx
	jne	.L5
	leaq	8000000(%rbp), %r13
	movq	%rbp, %r12
	.p2align 4,,10
	.p2align 3
.L7:
	movsd	(%r12), %xmm0
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$1, %eax
	addq	$8, %r12
	call	__printf_chk
	cmpq	%r13, %r12
	jne	.L7
	movl	$10, %edi
	call	putchar
	movq	%rbx, %rdi
	call	free
	movq	%rbp, %rdi
	call	free
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE38:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE3:
	.section	.text.startup
.LHOTE3:
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	1374389535
	.long	1074339512
	.align 8
.LC1:
	.long	0
	.long	1076101120
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
