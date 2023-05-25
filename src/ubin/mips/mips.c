#include "mips.h"

/**
 * @brief Função principal do programa.
 *
 * @return 0 se a execução for bem-sucedida.
 */
int main()
{
	int size = 9 * sizeof(int);
	int *program = (int *)malloc(size);

	mips_clean();

	program[0] = mips_typeR_bytecode(ADD, t0, s0, s1); // add $t0, $s0, $s1
	program[1] = mips_typeR_bytecode(SUB, s4, t0, t1); // sub $s4, $t0, $t1
	program[2] = mips_typeI_bytecode(ADDI, t7, t0, 7); // addi $t7, $t0, 7
	program[3] = mips_typeI_bytecode(SW, t0, s4, 0);   // sw $t0, 0($s4)
	program[4] = mips_typeI_bytecode(SW, t0, s4, 23);  // sw $t0, 23($s4)
	program[5] = mips_typeI_bytecode(LW, s2, s4, 0);   // lw $s2, 0($s4)
	program[6] = mips_typeI_bytecode(LW, s2, s4, 23);  // lw $s2, 23($s4)
	program[7] = mips_typeI_bytecode(SW, t0, s4, -4);  // sw $t0, -4($s4)
	program[8] = mips_typeI_bytecode(LW, s2, s4, -4);  // lw $s2, -4($s4)

	mips_load(program, size);
	mips_exec();

	return 0;
}
