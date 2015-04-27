	.text	
	.globl		main
main:
	li		$t0, 5
	sw		$t0, i
	li		$t0, 4
	sw		$t0, j
	lw		$t0, i
	lw		$t1, j
	sub		$t2, $t0, $t1
	sw		$t2, z
	lw		$t0, z
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
j:	.word		0
z:	.word		0
