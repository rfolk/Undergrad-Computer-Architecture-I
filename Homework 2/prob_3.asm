################################################################################
# Russell Folk
# Computer Architecture I
# Homework 2
# Question 3
# Bit Counter
#
# Take a decimal number as input and count the number of bits that are set to 1
# Print that result
################################################################################

.data
number: .word   17                          # dedicate space for an integer
start:  .asciiz "Enter a decimal integer: " # starting instruction text
ansr1:  .asciiz " has "                     # answer text part 1
ansr2:  .asciiz " bit(s) for 1.\n"          # answer text part 2

.text

.globl main

main:
################################################################################
# Print the instructions
	la $a0, start # load the instruction text
	li $v0, 4     # load the system call to print string
	syscall       # invoke the system call and print
################################################################################

################################################################################
# Get the input
	li $v0, 5      # load the system call to read an integer
	syscall        # invoke the system call and read integer
	sw $v0, number # store the integer in number
################################################################################

################################################################################
# Calculate the bits
	add      $s0, $0,     $0   # set number of 1's seen to 0
	add      $t0, $0,     $0   # bit incrementer
	la       $t1, number       # load address of number
	lw       $t2, 0($t1)       # load the value of number
	loop:
		slti   $t3, $t0,    32   # check bit incrementer < 32
		beq    $t3, $0,     out  # if no more bits left to check, stop
		andi   $t4, $t2,    1    # number & 1 for least significant bit
		beq    $t4, $0,     nope # if lsb == 0 don't count it
		addi   $s0, $s0,    1    # found another 1 bit
		nope:
			srl  $t2, $t2,    1    # number = number >> 1
			addi $t0, $t0,    1    # bit incrementer ++
			j    loop
################################################################################

################################################################################
# Print the result
	out:
		li   $v0, 1      # load the system call to print an integer
		la   $t0, number # load the address of the number
		lw   $t1, 0($t0) # load the value of $t0
		add $a0, $t1, $0 # prime integer for printing by moving to $a0
		syscall          # print the integer

		la   $a0, ansr1  # load the address of the "has" string
		li   $v0, 4      # load the system call to print a string
		syscall          # print the string

		li   $v0, 1      # load the system call to print an integer
		#lw   $t0, $s0    # load the value of the number of 1 bits
		add $a0, $s0, $0 # prime the integer for printing by moving to $a0
		syscall          # print the integer

		la   $a0, ansr2  # load the address of the "bit(s) for 1." string
		li   $v0, 4      # load the system call to print a string
		syscall          # print the string
################################################################################

################################################################################
# exit program subroutine
exit:
	li $v0, 10
	syscall
################################################################################
