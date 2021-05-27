.data
LC0:
	.asciiz	"%d"

.text
	.globl	main
main:
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	li	$2,131			# 0x83
	sw	$2,24($fp)      # save
	lw	$5,24($fp)      # arg
	la $4, LC0          # addr of LC0
	jal	printf

	move	$2,$0       # return 0
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	jr	$ra

