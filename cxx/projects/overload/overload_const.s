	.file	"overload_const.cpp"
	.text
	.section	.rodata
.LC0:
	.string	"func"
	.section	.text._ZN1A4funcEv,"axG",@progbits,_ZN1A4funcEv,comdat
	.align 2
	.weak	_ZN1A4funcEv
	.type	_ZN1A4funcEv, @function
_ZN1A4funcEv:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_ZN1A4funcEv, .-_ZN1A4funcEv
	.section	.rodata
.LC1:
	.string	"const func"
	.section	.text._ZNK1A4funcEv,"axG",@progbits,_ZNK1A4funcEv,comdat
	.align 2
	.weak	_ZNK1A4funcEv
	.type	_ZNK1A4funcEv, @function
_ZNK1A4funcEv:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZNK1A4funcEv, .-_ZNK1A4funcEv
	.section	.rodata
.LC2:
	.string	"foo %d"
	.section	.text._ZN1A3fooERi,"axG",@progbits,_ZN1A3fooERi,comdat
	.align 2
	.weak	_ZN1A3fooERi
	.type	_ZN1A3fooERi, @function
_ZN1A3fooERi:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_ZN1A3fooERi, .-_ZN1A3fooERi
	.section	.rodata
.LC3:
	.string	"foo const %d"
	.section	.text._ZN1A3fooERKi,"axG",@progbits,_ZN1A3fooERKi,comdat
	.align 2
	.weak	_ZN1A3fooERKi
	.type	_ZN1A3fooERKi, @function
_ZN1A3fooERKi:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_ZN1A3fooERKi, .-_ZN1A3fooERKi
	.section	.rodata
.LC4:
	.string	"fooo %d"
	.section	.text._ZN1A4foooEPi,"axG",@progbits,_ZN1A4foooEPi,comdat
	.align 2
	.weak	_ZN1A4foooEPi
	.type	_ZN1A4foooEPi, @function
_ZN1A4foooEPi:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_ZN1A4foooEPi, .-_ZN1A4foooEPi
	.section	.rodata
.LC5:
	.string	"fooo const %d"
	.section	.text._ZN1A4foooEPKi,"axG",@progbits,_ZN1A4foooEPKi,comdat
	.align 2
	.weak	_ZN1A4foooEPKi
	.type	_ZN1A4foooEPKi, @function
_ZN1A4foooEPKi:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_ZN1A4foooEPKi, .-_ZN1A4foooEPKi
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-18(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN1A4funcEv
	leaq	-17(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK1A4funcEv
	movl	$66, -16(%rbp)
	leaq	-16(%rbp), %rdx
	leaq	-18(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN1A3fooERi
	leaq	-16(%rbp), %rdx
	leaq	-18(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN1A4foooEPi
	movl	$88, -12(%rbp)
	leaq	-12(%rbp), %rdx
	leaq	-18(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN1A3fooERKi
	leaq	-12(%rbp), %rdx
	leaq	-18(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN1A4foooEPKi
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
