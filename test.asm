	.text	
	.globl		main
main:
	li		$t0, 10
	sw		$t0, j
L4:
	lw		$t0, j
	li		$t1, 0
	bgt		$t0, $t1, L1
	li		$t2, 0
	b		L2
L1:
	li		$t2, 1
L2:
	beq		$t2, $0, L5
	lw		$t0, j
	li		$v0, 1
	move		$a0, $t0
	syscall	
L3:
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, j
	li		$t1, 1
	sub		$t0, $t0, $t1
	sw		$t0, j
	b		L4
L5:
	li		$v0, 10
	syscall	
	.data	
	.align		4
_nl:	.asciiz		"\n"
_tru:	.asciiz		"true"
_fal:	.asciiz		"false"
_sp:	.asciiz		" "
j:	.word		0
