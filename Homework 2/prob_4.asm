################################################################################
# Russell Folk
# Computer Architecture I
# Homework 2
# Question 4
# Modulus Calculator
#
# Write a program that asks for input of a value and a divisor then generates
# the modulus of the numbers.
################################################################################

.data
value:    .word   17                # value input integer
divisor:  .word   17                # divisor input integer
gvalue:   .asciiz "Enter value: "   # value input string
gdivisor: .asciiz "Enter divisor: " # divisor input string
str_mod:  .asciiz " mod "           # output string part 1
str_eql:  .asciiz " = "             # output string part 2

.text
.globl main

main:
################################################################################
# Get the value
# Print the instructions
	la $a0, gvalue   # load the instruction text
	li $v0, 4        # load the system call to print string
	syscall          # invoke the system call and print
# Get the input
	li $v0, 5        # load the system call to read an integer
	syscall          # invoke the system call and read integer
	sw $v0, value    # store the integer in value
################################################################################
# Get the divisor
# Print the instructions
	la $a0, gdivisor # load the instruction text
	li $v0, 4        # load the system call to print string
	syscall          # invoke the system call and print
# Get the input
	li $v0, 5        # load the system call to read an integer
	syscall          # invoke the system call and read integer
	sw $v0, divisor  # store the integer in divisor
################################################################################

################################################################################
# Setup the call to modulus
	la   $t0, value   # load address of value
	lw   $s0, 0($t0)  # load the value of value
	la   $t0, divisor # load address of divisor
	lw   $s1, 0($t0)  # load the value of divisor
	sub  $sp, $sp, 12 # increase the stack for two arguments and one return value
	sw   $s0, 0($sp)  # push value to the stack
	sw   $s1, 4($sp)  # push divisor to the stack
	jal  modulus      # call modulus
	add  $s2, $v0, $0 # load the return of modulus
	addi $sp, $sp, 12 # shrink stack to what's needed
################################################################################

################################################################################
# Print the output to the screen
   li $v0, 1 # load system call to print integer
   la $t0, value #load address of value
   lw $t1, 0($t0) #load value of value to $t2
   add $a0, $t1, $0 # move integer to be printed into $a0
   syscall #print the number entered again

   la $a0, str_mod #load address of mod string
   li $v0, 4 #load system call to print str
   syscall # print part of the answer sentence

   li $v0, 1 # load system call to print integer
   la $t0, divisor #load address of divisor
   lw $t1, 0($t0) #load value of divisor to $t2
   add $a0, $t1, $0 # move integer to be printed into $a0
   syscall #print the number entered again

   la $a0, str_eql #load address of equal string
   li $v0, 4 #load system call to print str
   syscall # print part of the answer sentence

   li $v0, 1 #load system call to print integer
   add $a0, $s2, $0 #load address of answer
   syscall #print the number entered again
   j exit
################################################################################

################################################################################
# Modulus function
modulus:
	sub   $sp, $sp,   12   # increase the stack for two arguments and one return value
	sw    $ra, 8($sp)      # reserve return value
	sw    $s1, 4($sp)      # assign the second argument
	sw    $s0, 0($sp)      # assign the first argument
	slt   $t0, $s0,   $s1  # if value < divisor
	beq   $t0, $0,    cont # continue finding modulus
	add   $v0, $s0,   $0   # return value
	addi  $sp, $sp,   12
	jr    $ra              # address of return value
	cont:
		sub $s0, $s0,   $s1
		jal modulus
	lw    $s0, 0($sp)
	lw    $ra, 8($sp)
	addi  $sp, $sp,   12
	jr    $ra
################################################################################

################################################################################
# exit program subroutine
exit:
	li $v0, 10
	syscall
################################################################################
