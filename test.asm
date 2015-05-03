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
	li		$t0, 5
	li		$t1, 6
	bgt		$t0, $t1, L1
	li		$t2, 0
	b		L2
L1:
	li		$t2, 1
L2:
	sw		$t2, l
	li		$t0, 5
	li		$t1, 2
	bgt		$t0, $t1, L3
	li		$t2, 0
	b		L4
L3:
	li		$t2, 1
L4:
	beq		$t2, $0, L7
	la		$t0, L5
	li		$v0, 4
	move		$a0, $t0
	syscall	
L6:
L7:
	li		$t0, 3
	li		$t1, 8
	bgt		$t0, $t1, L8
	li		$t2, 0
	b		L9
L8:
	li		$t2, 1
L9:
	beq		$t2, $0, L14
	la		$t0, L10
	li		$v0, 4
	move		$a0, $t0
	syscall	
L11:
	b		L15
L14:
	la		$t0, L12
	li		$v0, 4
	move		$a0, $t0
	syscall	
L13:
L15:
	li		$t0, 10
	sw		$t0, j
	lw		$t0, j
	li		$t1, 1
	sub		$t2, $t0, $t1
	sw		$t2, j
	lw		$t0, j
	li		$v0, 1
	move		$a0, $t0
	syscall	
L16:
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$t0, 1
	sw		$t0, x
	li		$t0, 6
	sw		$t0, k
	lw		$t0, x
	li		$v0, 4
	beq		$0, $t0, L19
	la		$a0, _tru
	syscall	
	b		L18
L19:
	la		$a0, _fal
	syscall	
L18:
	li		$v0, 4
	la		$a0, _sp
	syscall	
	lw		$t1, k
	li		$v0, 1
	move		$a0, $t1
	syscall	
L17:
	li		$t0, 4
	li		$t1, 5
	move		$t3, $0
	addi		$t4, $0, 1
	beq		$t1, $0, L21
L20:
	mul		$t4, $t4, $t0
	addi		$t3, $t3, 1
	blt		$t3, $t1, L20
L21:
	li		$v0, 1
	move		$a0, $t4
	syscall	
L22:
	li		$t0, 7
	li		$t1, 4
	bgt		$t0, $t1, L23
	li		$t3, 0
	b		L24
L23:
	li		$t3, 1
L24:
	li		$v0, 4
	beq		$0, $t3, L26
	la		$a0, _tru
	syscall	
	b		L25
L26:
	la		$a0, _fal
	syscall	
L25:
	lw		$t0, l
	li		$v0, 4
	beq		$0, $t0, L28
	la		$a0, _tru
	syscall	
	b		L27
L28:
	la		$a0, _fal
	syscall	
L27:
	lw		$t0, i
	li		$v0, 4
	beq		$0, $t0, L31
	la		$a0, _tru
	syscall	
	b		L30
L31:
	la		$a0, _fal
	syscall	
L30:
	li		$v0, 4
	la		$a0, _sp
	syscall	
	lw		$t1, j
	li		$v0, 1
	move		$a0, $t1
	syscall	
L29:
	la		$t0, L32
	li		$v0, 4
	move		$a0, $t0
	syscall	
L35:
	li		$v0, 4
	la		$a0, _sp
	syscall	
	la		$t1, L33
	li		$v0, 4
	move		$a0, $t1
	syscall	
L34:
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
x:	.word		0
	.align		4
L33:	.asciiz		"Nick Sucks"
	.align		4
L32:	.asciiz		"hello world"
	.align		4
L12:	.asciiz		"else if is working"
	.align		4
L10:	.asciiz		"else if not working"
	.align		4
L5:	.asciiz		"if is working"
