	.text	
	.globl		main
main:
	li		$t0, 0
	li		$t1, 1
	or		$t0, $t0, $t1
	li		$t1, 0
	li		$t2, 1
	or		$t1, $t1, $t2
	and		$t0, $t0, $t1
	sw		$t0, i
	lw		$t0, i
	li		$v0, 4
	beq		$0, $t0, L2
	la		$a0, _tru
	syscall	
	b		L1
L2:
	la		$a0, _fal
	syscall	
L1:
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
