#include "mem.h"
#include "consts.h"
#include "decode.h"

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
	length = size / sizeof(int);

	for (int i = 0; i < length; i++)
	{
		memory[i] = program[i];
	}

	for (int i = 0; i < REGISTER_LEN; i++)
	{
		registers[i] = 1;
	}
}

void mips_clean()
{
	memset(memory, 0, sizeof(memory));
}

void mips_exec()
{
	cycles = 0;
	int inst, ic = 0;

	while (counter < length)
	{
		inst = memory[counter];

		mips_decode_inst(inst);

		counter++;
		ic++;
	}

	printf("CPI: %d / %d = %d\n", cycles, ic, cycles / ic);

	mips_clean();
}
