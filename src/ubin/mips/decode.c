#include "consts.h"
#include "decode.h"
#include "instr.h"

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
		printf("ADD $%d, $%d, $%d\n", rd, rs, rt);
		mips_add(rt, rs, rd);
		break;
	case ADDU:
		printf("ADDU $%d, $%d, $%d\n", rd, rs, rt);
		break;
	case SUB:
		printf("SUB $%d, $%d, $%d\n", rd, rs, rt);
		mips_sub(rt, rs, rd);
		break;
	case SUBU:
		printf("SUBU $%d, $%d, $%d\n", rd, rs, rt);
		break;
	case AND:
		printf("AND $%d, $%d, $%d\n", rd, rs, rt);
		break;
	case OR:
		printf("OR $%d, $%d, $%d\n", rd, rs, rt);
		break;
	case SLT:
		printf("SLT $%d, $%d, $%d\n", rd, rs, rt);
		break;
	case SLTU:
		printf("SLTU $%d, $%d, $%d\n", rd, rs, rt);
		break;
	case SLL:
		printf("SLL $%d, $%d, %d\n", rd, rt, shamt);
		break;
	case SRL:
		printf("SRL $%d, $%d, %d\n", rd, rt, shamt);
		break;
	case JR:
		printf("JR $%d\n", rs);
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
		printf("ADDI $%d, $%d, %d\n", rt, rs, imm);
		break;
	case ADDIU:
		printf("ADDIU $%d, $%d, %d\n", rt, rs, imm);
		break;
	case ANDI:
		printf("ANDI $%d, $%d, %d\n", rt, rs, imm);
		break;
	case ORI:
		printf("ORI $%d, $%d, %d\n", rt, rs, imm);
		break;
	case SLTI:
		printf("SLTI $%d, $%d, %d\n", rt, rs, imm);
		break;
	case SLTIU:
		printf("SLTIU $%d, $%d, %d\n", rt, rs, imm);
		break;
	case LUI:
		printf("LUI $%d, 0x%x\n", rt, imm);
		break;
	case LW:
		printf("LW $%d, %d($%d)\n", rt, imm, rs);
		mips_lw(rt, imm, rs);
		break;
	case SW:
		printf("SW $%d, %d($%d)\n", rt, imm, rs);
		mips_sw(rt, imm, rs);
		break;
	case BEQ:
		printf("BEQ $%d, %d, 0x%x\n", rt, rs, imm);
		break;
	case BNE:
		printf("BNE $%d, %d, 0x%x\n", rt, rs, imm);
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
