#include "consts.h"
#include "instr.h"
#include "mem.h"
#include "reg.h"

void mips_add(int rd, int rs, int rt)
{
	mips_set_reg(rd, mips_get_reg(rs) + mips_get_reg(rt));
}

void mips_addi(int rt, int rs, int imm)
{
	mips_set_reg(rt, mips_get_reg(rs) + imm);
}

void mips_sub(int rd, int rs, int rt)
{
	mips_set_reg(rd, mips_get_reg(rs) - mips_get_reg(rt));
}

void mips_lw(int rd, int imm, int rs)
{
	mips_set_reg(rd, mips_read_mem(imm + mips_get_reg(rs)));
}

void mips_sw(int rd, int imm, int rs)
{
	mips_write_mem(imm + mips_get_reg(rs), mips_get_reg(rd));
}

void mips_j(int target)
{
	counter = target;
}
