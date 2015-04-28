	.text	
	.globl		main
main:
	li		$t0, 3
	li		$t1, 4
	bne		$t0, $t1, L1
	li		$t2, 0
	b		L2
L1:
	li		$t2, 1
L2:
	sw		$t2, i
	li		$t0, 2
	li		$t1, 3
	blt		$t0, $t1, L3
	li		$t2, 0
	b		L4
L3:
	li		$t2, 1
L4:
	sw		$t2, j
	li		$t0, 7
	li		$t1, 5
	bgt		$t0, $t1, L5
	li		$t2, 0
	b		L6
L5:
	li		$t2, 1
L6:
	sw		$t2, k
	li		$t0, 6
	li		$t1, 5
	beq		$t0, $t1, L7
	bgt		$t0, $t1, L7
	li		$t2, 0
	b		L8
L7:
	li		$t2, 1
L8:
	sw		$t2, l
	li		$t0, 4
	li		$t1, 8
	beq		$t0, $t1, L9
	blt		$t0, $t1, L9
	li		$t2, 0
	b		L10
L9:
	li		$t2, 1
L10:
	sw		$t2, m
	lw		$t0, i
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, j
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, k
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, l
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, m
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
k:	.word		0
l:	.word		0
m:	.word		0
