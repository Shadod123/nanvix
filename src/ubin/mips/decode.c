#include "consts.h"
#include "decode.h"
#include "instr.h"

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

void mips_typeR_inst(int inst, int opcode)
{
	int rs = (inst >> 21) & 0x1F;
	int rt = (inst >> 16) & 0x1F;
	int rd = (inst >> 11) & 0x1F;
	int shamt = (inst >> 6) & 0x1F;
	int funct = inst & 0x3F;

	opcode = opcode << 26;
	opcode = opcode | funct;

	switch (opcode)
	{
	case ADD:
		printf("ADD %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		mips_add(rt, rs, rd);
		break;
	case ADDU:
		printf("ADDU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SUB:
		printf("SUB %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		mips_sub(rt, rs, rd);
		break;
	case SUBU:
		printf("SUBU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case AND:
		printf("AND %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case OR:
		printf("OR %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLT:
		printf("SLT %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLTU:
		printf("SLTU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLL:
		printf("SLL %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rt), shamt);
		break;
	case SRL:
		printf("SRL %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rt), shamt);
		break;
	case JR:
		printf("JR %d\n", rs);
		break;
	default:
		printf("Instrução R não reconhecida\n");
		break;
	}
}

void mips_typeJ_inst(int inst, int opcode)
{
	int target = inst & 0x03FFFFFF;

	opcode = opcode << 26;

	switch (opcode)
	{
	case J:
		printf("J 0x%x\n", target);
		break;
	case JAL:
		printf("JAL 0x%x\n", target);
		break;
	default:
		printf("Instrução J não reconhecida\n");
		break;
	}
}

void mips_typeI_inst(int inst, int opcode)
{
	int rs = (inst >> 21) & 0x1F;
	int rt = (inst >> 16) & 0x1F;
	int imm = inst & 0xFFFF;

	opcode = opcode << 26;

	switch (opcode)
	{
	case ADDI:
		printf("ADDI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case ADDIU:
		printf("ADDIU %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case ANDI:
		printf("ANDI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case ORI:
		printf("ORI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case SLTI:
		printf("SLTI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case SLTIU:
		printf("SLTIU %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case LUI:
		printf("LUI %s, 0x%x\n", mips_get_reg_name(rs), imm);
		break;
	case LW:
		printf("LW %s, %d(%d)\n", mips_get_reg_name(rs), imm, rs);
		mips_lw(rt, imm, rs);
		break;
	case SW:
		printf("SW %s, %d(%d)\n", mips_get_reg_name(rs), imm, rs);
		mips_sw(rt, imm, rs);
		break;
	case BEQ:
		printf("BEQ %s, %s, 0x%x\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case BNE:
		printf("BNE %s, %s, 0x%x\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	default:
		printf("Instrução I não reconhecida\n");
		break;
	}
}

void mips_decode_inst(int inst)
{
	// Os 6 bits mais significativos da instrução contêm o opcode, que identifica a operação a ser executada.
	int opcode = inst >> 26;

	// Determina o tipo da instrução com base no opcode.
	if (opcode == 0)
	{
		mips_typeR_inst(inst, opcode);
	}
	else if (opcode == 2 || opcode == 3)
	{
		mips_typeJ_inst(inst, opcode);
	}
	else
	{
		mips_typeI_inst(inst, opcode);
	}
}
