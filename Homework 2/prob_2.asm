################################################################################
# Russell Folk
# Computer Architecture I
# Homework 2
# Question 2
# Optimize the Loop Program
#
#       addi $t1, $0,    $0
# LOOP: lw   $s1, 0($s0)
#       add  $s2, $s2,   $s1
#       addi $s0, $s0,   4
#       addi $t1, $t1,   1
#       slti $t2, $t1,   100
#       bne  $t2, $0,    LOOP
################################################################################

# integers are 4 so each increment is by 4
			add  $s2, $0,    $0   # initialize result to 0
			addi $t1, $s0,   400  # compute the cap for the loop
LOOP:	lw   $s1, 0($s0)      # load element at current address
			add  $s2, $s2,   $s1  # add current int to result
			addi $s0, $s0,   4    # increment pointer to next int
			bne  $s0, $t1,   LOOP # if current pointer != cap then LOOP
