	.text	
	.globl		main
main:
	li		$t0, 5
	sw		$t0, i
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
