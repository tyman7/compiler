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
	li		$t0, 4
	sw		$t0, j
	li		$t0, 5
	sw		$t0, k
	li		$t0, 5
	li		$t1, 6
	bgt		$t0, $t1, L1
	li		$t2, 0
	b		L2
L1:
	li		$t2, 1
L2:
	sw		$t2, l
	li		$t0, 7
	li		$t1, 4
	bgt		$t0, $t1, L3
	li		$t2, 0
	b		L4
L3:
	li		$t2, 1
L4:
	li		$v0, 4
	beq		$0, $t2, L6
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
	lw		$t0, l
	li		$v0, 4
	beq		$0, $t0, L8
	la		$a0, _tru
	syscall	
	b		L7
L8:
	la		$a0, _fal
	syscall	
L7:
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, i
	li		$v0, 4
	beq		$0, $t0, L11
	la		$a0, _tru
	syscall	
	b		L10
L11:
	la		$a0, _fal
	syscall	
L10:
	li		$v0, 4
	la		$a0, _sp
	syscall	
	lw		$t1, j
	li		$v0, 1
	move		$a0, $t1
	syscall	
L9:
	li		$t0, 8
	addi		$t2, $0, 1
	blt		$t0, $0, L12
	li		$t1, 0
L13:
	li		$v0, 4
	la		$a0, _sp
	syscall	
	addi		$t1, $t1, 1
	blt		$t1, $t0, L13
L12:
	lw		$t0, k
	li		$v0, 1
	move		$a0, $t0
	syscall	
L14:
	li		$v0, 4
	la		$a0, _nl
	syscall	
	la		$t0, L15
	li		$v0, 4
	move		$a0, $t0
	syscall	
L18:
	li		$v0, 4
	la		$a0, _sp
	syscall	
	la		$t1, L16
	li		$v0, 4
	move		$a0, $t1
	syscall	
L17:
	li		$v0, 10
	syscall	
	.data	
	.align		4
_nl:	.asciiz		"\n"
_tru:	.asciiz		"true"
_fal:	.asciiz		"false"
_sp:	.asciiz		" "
c:	.word		0
i:	.word		0
j:	.word		0
k:	.word		0
l:	.word		0
	.align		4
L16:	.asciiz		"Nick Sucks"
	.align		4
L15:	.asciiz		"hello world"
