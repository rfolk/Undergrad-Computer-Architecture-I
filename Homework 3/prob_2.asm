################################################################################
# Russell Folk
# Computer Architecture I
# Homework 3
# Question 2
# Matrix Transposition
#
# Write a program that transposes a give matrix and prints the transposition.
################################################################################

################################################################################
# Declare the Variables
# Matrix A is the original matrix
# Matrix T will hold the translated matrix
.data
.align            2   # Request alignment on word (4 bytes) boundary
# Define the format character
SPACE: .asciiz    " " # blank space for output spacing
# Declare the 4x3 Matrix, Matrix A
NUM_ROWS_A: .word 4   # number of rows
NUM_COLS_A: .word 3   # number of columns
MATRIX_A: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
# Declare the 3x4 Matrix, Matrix T
MATRIX_T: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
# Begin the Program
.text
.globl main

main:
################################################################################

################################################################################
# Load the constants
lw $s2, NUM_ROWS_A
lw $s3, NUM_COLS_A
la $s0, MATRIX_A
la $s1, MATRIX_T
################################################################################

################################################################################
# Initialize outer for loop
add $t0, $0, $0 # $t0 = i = 0
add $s4, $0, $0 # $s4 = row offset = 0
################################################################################

################################################################################
# Outer for loop
# for (i = 0; i < NUM_ROWS_A; ++i)
read_outer:
	slt $t2, $t0, $s2        # check i < NUM_ROWS_A
	beq $t2, $0,  init_print # if i >= NUM_ROWS_A, start printing
	# Initialize inner for loop
	add $t1, $0,  $0         # j = 0
################################################################################

################################################################################
# Inner for loop
# for (j = 0; j < NUM_COLS_A; ++j)
	read_inner:
		lw   $t2, 0($s0)            # read the value of address A[i][j] into $t2
		sw   $t2, 0($s1)            # store the value of $t5 into T[j][i]
		addi $s0, $s0,   16         # move 5 addresses in A
		addi $s1, $s1,   4          # move to next address of T
		addi $t1, $t1,   1          # ++j
		slt  $t2, $t1,   $s3        # check j < NUM_COLS_A
		bne  $t2, $0,    read_inner # stay in inner loop
################################################################################

################################################################################
# Wrap up outer for loop
	addi $t0, $t0,     1   # ++i
	addi $s4, $s4,     4   # offset counter += 4
	la   $s0, MATRIX_A     # reset address of $s0 to top of Matrix A
	add  $s0, $s0,     $s4 # point to the next row of Matrix A
	j    read_outer        # return to the top of outer loop
################################################################################

################################################################################
# Print Matrix T to the screen
# Initialize the printing
init_print:
	la $s1, MATRIX_T # load the address of T into $s1
# for (int i = 0; i < NUM_COLS_A; ++i)
	add $t0, $0, $0  # i = 0
################################################################################

################################################################################
# Begin iterating through the outer loop
print_outer:
	slt $t2, $t0, $s2  # check if i < NUM_COLS_A
	beq $t2, $0,  exit # if i >= NUM_COLS_A jump to exit
################################################################################

################################################################################
# for (int j = 0; j < NUM_ROWS_A; ++j)
	add $t1, $0, $0  # j = 0
################################################################################

################################################################################
# Begin iterating through the inner loop
	print_inner:
		lw  $t2, 0($s1)    # load the value of T[i][j]
		add $a0, $t2,   $0 # load the value to argument 1
		li  $v0, 1         # load the system call to print an integer
		syscall            # invoke the system call and print
################################################################################

################################################################################
# Print a Space for formatting
		la $a0, SPACE # load the address of the 'space' string
		li $v0, 4     # load the system call to read a string
		syscall       # invoke the system call and print

		addi $t1, $t1, 1           # ++j
		addi $s1, $s1, 4           # progress T to next address
		slt  $t2, $t1, $s3         # check if j < NUM_ROWS_A
		bne  $t2, $0,  print_inner # if $t2 != 0 print_inner
################################################################################

################################################################################
# Wrap up the print loops
	addi $t0, $t0, 1 # ++i
	j print_outer    # return to top of outer loop
################################################################################

################################################################################
# exit program subroutine
exit:
	li $v0, 10 # load the system call to exit the program
	syscall    # invoke the system call and exit
################################################################################
