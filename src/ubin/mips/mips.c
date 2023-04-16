#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define REGISTER_LEN 16
#define MEMORY_LEN 256

enum MipsOperation
{
	NOP = 0x00000000,
	ADD = 0x00000020,
	SUB = 0x00000022,
};

int counter;
int zero = 0;
int registers[REGISTER_LEN];
int memory[MEMORY_LEN];
int lenght;

/**
 * @brief Retorna o valor do registrador especificado.
 *
 * @param reg O registrador para o qual o valor é desejado.
 * @return O valor do registrador especificado.
 */
int mips_get_reg(int reg)
{
	return registers[reg];
}

/**
 * @brief Define o valor do registrador especificado.
 *
 * @param reg O registrador a ser definido.
 * @param val O valor a ser atribuído ao registrador.
 * @return O valor atribuído ao registrador.
 */
int mips_set_reg(int reg, int val)
{
	return registers[reg] = val;
}

/**
 * @brief Carrega o programa na memória.
 *
 * @param program O programa a ser carregado na memória.
 * @param size O tamanho do programa em bytes.
 */
void mips_load(int *program, int size)
{
	lenght = size / sizeof(int);

	for (int i = 0; i < lenght; i++)
	{
		memory[i] = program[i];
	}
}

/**
 * @brief Limpa a memória.
 */
void mips_clean()
{
	memset(memory, 0, sizeof(memory));
}

/**
 * @brief Executa as instruções armazenadas na memória.
 */
void mips_exec()
{
	int instr = 0;

	while (counter < lenght)
	{
		instr = memory[counter];

		// Os 6 bits mais significativos da instrução contêm o opcode, que identifica a operação a ser executada.
		int opcode = instr >> 26;
		opcode = opcode << 26;

		// Os 6 bits menos significativos contêm o funct, que especifica a função a ser executada.
		int funct = instr << 25;
		funct = funct >> 25;

		// A combinação dos valores de opcode e funct representa a operação completa.
		opcode = opcode | funct;
		printf("opcode: %x\n", opcode);

		switch (opcode)
		{
		case NOP:
			printf("NOP\n");
			break;
		case ADD:
			printf("ADD\n");
			break;
		case SUB:
			printf("SUB\n");
			break;
		}

		counter++;
	}

	mips_clean();
}

/**
 * @brief Função principal do programa.
 *
 * @return 0 se a execução for bem-sucedida.
 */
int main()
{
	int size = 2 * sizeof(int);
	int *program = (int *)malloc(size);

	program[0] = ADD;
	program[1] = SUB;

	mips_load(program, size);
	mips_exec();

	return 0;
}
