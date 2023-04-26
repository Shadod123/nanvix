#include "consts.h"
#include "reg.h"

int mips_get_reg(int reg)
{
	return registers[reg];
}

void mips_set_reg(int reg, int val)
{
	registers[reg] = val;
}
