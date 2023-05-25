#include "instr.h"
#include "consts.h"
#include "mem.h"
#include "reg.h"

void mips_add(int rd, int rs, int rt)
{
	mips_set_reg(rd, mips_get_reg(rs) + mips_get_reg(rt));
	printf("%d + %d = %d\n\n", mips_get_reg(rs) , mips_get_reg(rt), mips_get_reg(rd));
}

void mips_addi(int rt, int rs, int imm)
{
	mips_set_reg(rt, mips_get_reg(rs) + imm);
	printf("%d + %d = %d\n\n", mips_get_reg(rs) , imm, mips_get_reg(rt));
}

void mips_sub(int rd, int rs, int rt)
{
	mips_set_reg(rd, mips_get_reg(rs) - mips_get_reg(rt));
	printf("%d - %d = %d\n\n", mips_get_reg(rs) , mips_get_reg(rt), mips_get_reg(rd));
}

void mips_lw(int rt, int imm, int rs)
{
	mips_set_reg(rt, mips_read_mem(imm + mips_get_reg(rs)));
	printf("%s = mem[%d]\n\n", mips_get_reg_name(rt), mips_get_reg(rs) + imm);
}

void mips_sw(int rt, int imm, int rs)
{
	mips_write_mem(imm + mips_get_reg(rs), mips_get_reg(rt));
	printf("mem[%d] = %d\n\n", mips_get_reg(rs) + imm, mips_get_reg(rt));
}

void mips_j(int target)
{
	counter = target;
}
