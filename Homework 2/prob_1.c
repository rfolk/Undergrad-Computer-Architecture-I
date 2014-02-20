/*******************************************************************************
	* Russell Folk
	* Computer Architecture I
	* Homework 2
	* Question 1
	* Loop Program
	*
	*       addi $t1, $0,    $0
	* LOOP: lw   $s1, 0($s0)
	*       add  $s2, $s2,   $s1
	*       addi $s0, $s0,   4
	*       addi $t1, $t1,   1
	*       slti $t2, $t1,   100
	*       bne  $t2, $0,    LOOP
	*****************************************************************************/
int i = 0 ;
do
{
	result = result + MemArray[ i ] ;
	i ++ ;
}
while ( i < 100 ) ;
