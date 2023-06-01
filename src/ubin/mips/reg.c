#include "reg.h"
#include "consts.h"

int mips_get_reg(int reg)
{
	return mips_reg_bank[reg];
}

void mips_set_reg(int reg, int val)
{
	mips_reg_bank[reg] = val;
}

void mips_set_reg_unsigned(int reg, unsigned int val)
{
	mips_reg_bank[reg] = val;
}

char *mips_get_reg_name(int reg)
{
	switch (reg)
	{
	case t0:
		return "$t0";
	case t1:
		return "$t1";
	case t2:
		return "$t2";
	case t3:
		return "$t3";
	case t4:
		return "$t4";
	case t5:
		return "$t5";
	case t6:
		return "$t6";
	case t7:
		return "$t7";
	case s0:
		return "$s0";
	case s1:
		return "$s1";
	case s2:
		return "$s2";
	case s3:
		return "$s3";
	case s4:
		return "$s4";
	case s5:
		return "$s5";
	case s6:
		return "$s6";
	case s7:
		return "$s7";
	default:
		printf("Registrador nao reconhecido\n");
		return "";
	}
}