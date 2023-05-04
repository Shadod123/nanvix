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

char *mips_get_reg_name(int reg)
{
	switch (reg)
	{
	case 8:
		return "$t0";
	case 9:
		return "$t1";
	case 10:
		return "$t2";
	case 11:
		return "$t3";
	case 12:
		return "$t4";
	case 13:
		return "$t5";
	case 14:
		return "$t6";
	case 15:
		return "$t7";
	case 16:
		return "$s0";
	case 17:
		return "$s1";
	case 18:
		return "$s2";
	case 19:
		return "$s3";
	case 20:
		return "$s4";
	case 21:
		return "$s5";
	case 22:
		return "$s6";
	case 23:
		return "$s7";
	default:
		printf("Registrador não reconhecido\n");
		return "";
	}
}