#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0
#define byte unsigned char

#define MAX_REGISTERS 16
#define MAX_PROGRAM 65535

enum OpCode
{
	NOP = 0x00,
	ADD = 0x01,
	HLT = 0xFF,
};

int counter = 0;
byte registers[MAX_REGISTERS];
byte program[MAX_PROGRAM];

byte example[] = {
	NOP,
	NOP,
	NOP,
	HLT,
};

void mips_load(const byte *prog, int prog_len)
{
	for (int i = 0; i < prog_len; i++)
	{
		program[i] = prog[i];
	}
}

void mips_halt()
{
	memset(program, 0, sizeof(program));
}

void mips_exec()
{
	byte opcode = 0;
	bool halt = false;
	
	printf("-- OPCODES --\n");

	while (!halt)
	{
		opcode = program[counter];

		printf("%x\n", opcode);

		switch (opcode)
		{
		case NOP:
			break;
		case HLT:
			halt = true;
			break;
		default:
			break;
		}

		counter++;
	}

	mips_halt();
}

int main()
{
	printf("%d\n", 1.2);
	mips_load(example, sizeof(example) / sizeof(byte));
	mips_exec();

	return 0;
}
