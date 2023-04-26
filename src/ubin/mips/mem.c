#include "consts.h"
#include "decode.h"
#include "mem.h"

int mips_read_mem(int addr)
{
	return memory[addr];
}

void mips_write_mem(int addr, int val)
{
	memory[addr] = val;
}

void mips_load(int *program, int size)
{
	lenght = size / sizeof(int);

	for (int i = 0; i < lenght; i++)
	{
		memory[i] = program[i];
	}
}

void mips_clean()
{
	memset(memory, 0, sizeof(memory));
}

void mips_exec()
{
	int inst = 0;

	while (counter < lenght)
	{
		inst = memory[counter];

		mips_decode_inst(inst);

		counter++;
	}

	mips_clean();
}
