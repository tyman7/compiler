	.text	
	.globl		main
main:
	li		$t0, 1
	sw		$t0, k
	lw		$t0, k
	beq		$0, $t0, L1
	li		$t0, 0
	b		L2
L1:
	li		$t0, 1
L2:
	sw		$t0, i
	lw		$t0, k
	li		$v0, 4
	beq		$0, $t0, L4
	la		$a0, _tru
	syscall	
	b		L3
L4:
	la		$a0, _fal
	syscall	
L3:
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, i
	li		$v0, 4
	beq		$0, $t0, L6
	la		$a0, _tru
	syscall	
	b		L5
L6:
	la		$a0, _fal
	syscall	
L5:
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$v0, 10
	syscall	
	.data	
	.align		4
_nl:	.asciiz		"\n"
_tru:	.asciiz		"true"
_fal:	.asciiz		"false"
i:	.word		0
k:	.word		0
