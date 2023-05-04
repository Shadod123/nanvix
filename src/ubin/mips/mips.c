#include "mips.h"

/**
 * @brief Função principal do programa.
 *
 * @return 0 se a execução for bem-sucedida.
 */
int main()
{
	int size = 13 * sizeof(int);
	int *program = (int *)malloc(size);

	mips_clean();

	program[0] = 0x02114020;  // add $t0, $s0, $s1
	program[1] = 0x02534820;  // add $t1, $s2, $s3
	program[2] = 0x0109a022;  // sub $s4, $t0, $t1
	program[3] = 0x02115822;  // sub $t3, $s0, $s1
	program[4] = 0x0174a820;  // add $s5, $t3, $s4
	program[5] = 0x02958822;  // sub $s1, $s4, $s5
    program[6] = 0x210F0007;  // addi $t7, $t0, 7
    program[7] = 0xAE910000;  // sw $s1, 0($s4)
    program[8] = 0xAE950017;  // sw $s5, 23($s4)
    program[9] = 0xAE8B0004;  // sw $t3, 4($s4)
    program[10] = 0x8E920000; // lw $s2, 0($s4)
    program[11] = 0x8E920017; // lw $s2, 23($s4)
	program[12] = 0x8E920004; // lw $s2, 4($s4)

	mips_load(program, size);
	mips_exec();

	return 0;
}
