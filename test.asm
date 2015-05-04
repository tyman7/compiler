	.text	
	.globl		main
main:
	subu		$sp, $sp, 8
	sw		$t0, 0($sp)
	sw		$ra, 4($sp)
	jal		_main
	lw		$t0, 0($sp)
	lw		$ra, 4($sp)
	addu		$sp, $sp, 8
	move		$t0, $v0
	li		$v0, 10
	syscall	
_test:
	li		$t0, 2
	li		$t1, 2
	add		$t2, $t0, $t1
	move		$v0, $t2
	jr		$ra
	jr		$ra
_printval:
	lw		$t0, i
	li		$v0, 1
	move		$a0, $t0
	syscall	
L1:
	jr		$ra
_main:
	subu		$sp, $sp, 8
	sw		$t0, 0($sp)
	sw		$ra, 4($sp)
	jal		_test
	lw		$t0, 0($sp)
	lw		$ra, 4($sp)
	addu		$sp, $sp, 8
	move		$t0, $v0
	sw		$t0, i
	subu		$sp, $sp, 8
	sw		$t0, 0($sp)
	sw		$ra, 4($sp)
	jal		_printval
	lw		$t0, 0($sp)
	lw		$ra, 4($sp)
	addu		$sp, $sp, 8
	move		$t0, $v0
	jr		$ra
	.data	
	.align		4
_nl:	.asciiz		"\n"
_tru:	.asciiz		"true"
_fal:	.asciiz		"false"
_sp:	.asciiz		" "
	.align		4
i:	.word		0
