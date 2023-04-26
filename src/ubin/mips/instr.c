#include "consts.h"
#include "instr.h"
#include "mem.h"
#include "reg.h"

void mips_add(int rd, int rs, int rt)
{
	int s = mips_get_reg(rs);
	int t = mips_get_reg(rt);
	int d = s + t;
	mips_set_reg(rd, d);
}

void mips_sub(int rd, int rs, int rt)
{
	int s = mips_get_reg(rs);
	int t = mips_get_reg(rt);
	int d = s - t;
	mips_set_reg(rd, d);
}

void mips_lw(int rd, int imm, int rs)
{
	mips_set_reg(rd, mips_read_mem(imm + mips_get_reg(rs)));
}

void mips_sw(int rd, int imm, int rs)
{
	mips_write_mem(imm + mips_get_reg(rs), mips_get_reg(rd));
}
