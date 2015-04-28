	.text	
	.globl		main
main:
	li		$t0, 3
	li		$t1, 2
	move		$t3, $0
	addi		$t4, $0, 1
	beq		$t1, $0, L2
L1:
	mul		$t4, $t4, $t0
	addi		$t3, $t3, 1
	blt		$t3, $t1, L1
L2:
	sw		$t4, i
	lw		$t0, i
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$v0, 10
	syscall	
	.data	
	.align		4
_nl:	.asciiz		"\n"
i:	.word		0
