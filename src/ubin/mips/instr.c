#include "consts.h"
#include "instr.h"
#include "mem.h"
#include "reg.h"

void mips_add(int rd, int rs, int rt)
{
	int s = mips_get_reg(rs);
	int t = mips_get_reg(rt);
	int d = s + t;
	printf("%d + %d = %d\n\n", s, t, d);
	mips_set_reg(rd, d);
}

void mips_addi(int rt, int rs, int imm)
{
	mips_set_reg(rt, mips_get_reg(rs) + imm);
}

void mips_sub(int rd, int rs, int rt)
{
	int s = mips_get_reg(rs);
	int t = mips_get_reg(rt);
	int d = s - t;
	printf("%d - %d = %d\n\n", s, t, d);
	mips_set_reg(rd, d);
}

void mips_lw(int rt, int imm, int rs)
{
	printf("%s = mem[%d]\n\n", mips_get_reg_name(rt), mips_get_reg(rs) + imm);
	mips_set_reg(rt, mips_read_mem(imm + mips_get_reg(rs)));
}

void mips_sw(int rt, int imm, int rs)
{
	printf("mem[%d] = %d\n\n", mips_get_reg(rs) + imm, mips_get_reg(rt));
	mips_write_mem(imm + mips_get_reg(rs), mips_get_reg(rt));
}

void mips_j(int target)
{
	counter = target;
}
