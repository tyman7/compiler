	.text	
	.globl		main
main:
	li		$t1, 1
	li		$t0, 0
	la		$t2, i
	mul		$t0, $t0, 4
	add		$t2, $t2, $t0
	sw		$t1, 0($t2)
	lw		$t0, i
L1:
	li		$v0, 10
	syscall	
	.data	
	.align		4
_nl:	.asciiz		"\n"
_tru:	.asciiz		"true"
_fal:	.asciiz		"false"
_sp:	.asciiz		" "
	.align		4
i:	.space		20
