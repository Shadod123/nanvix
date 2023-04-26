#include "mips.h"

/**
 * @brief Função principal do programa.
 *
 * @return 0 se a execução for bem-sucedida.
 */
int main()
{
	int size = 5 * sizeof(int);
	int *program = (int *)malloc(size);

	mips_clean();

	// Teste de decodificação de instruções com bytecode implementado
	program[0] = ADD;
	program[1] = ADDI;
	program[2] = SUB;
	program[3] = LW;
	program[4] = SW;

	mips_load(program, size);
	mips_exec();

	return 0;
}
