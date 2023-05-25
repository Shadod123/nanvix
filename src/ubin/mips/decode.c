#include "decode.h"
#include "consts.h"
#include "instr.h"
#include "reg.h"

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
		fprintf(log_file, "ADD %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		mips_add(rd, rs, rt);
		break;
	case ADDU:
		fprintf(log_file, "ADDU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SUB:
		fprintf(log_file, "SUB %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		mips_sub(rd, rs, rt);
		break;
	case SUBU:
		fprintf(log_file, "SUBU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case AND:
		fprintf(log_file, "AND %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case OR:
		fprintf(log_file, "OR %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLT:
		fprintf(log_file, "SLT %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLTU:
		fprintf(log_file, "SLTU %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rs), mips_get_reg_name(rt));
		break;
	case SLL:
		fprintf(log_file, "SLL %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rt), shamt);
		break;
	case SRL:
		fprintf(log_file, "SRL %s, %s, %s\n", mips_get_reg_name(rd), mips_get_reg_name(rt), shamt);
		break;
	case JR:
		fprintf(log_file, "JR %d\n", rs);
		break;
	default:
		fprintf(log_file, "Instrucao tipo R nao reconhecida\n");
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
		fprintf(log_file, "J %x\n", target);
		mips_j(target);
		break;
	case JAL:
		fprintf(log_file, "JAL %x\n", target);
		break;
	default:
		fprintf(log_file, "Instrucao tipo J nao reconhecida\n");
		break;
	}
}

void mips_typeI_inst(int inst, int opcode)
{
	int rs = (inst >> 21) & 0x1F;
	int rt = (inst >> 16) & 0x1F;
	int imm = (int16_t) (inst & 0xFFFF);

	opcode = opcode << 26;

	switch (opcode)
	{
	case ADDI:
		fprintf(log_file, "ADDI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		mips_addi(rt, rs, imm);
		break;
	case ADDIU:
		fprintf(log_file, "ADDIU %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case ANDI:
		fprintf(log_file, "ANDI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case ORI:
		fprintf(log_file, "ORI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case SLTI:
		fprintf(log_file, "SLTI %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case SLTIU:
		fprintf(log_file, "SLTIU %s, %s, %d\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case LUI:
		fprintf(log_file, "LUI %s, %x\n", mips_get_reg_name(rt), imm);
		break;
	case LW:
		fprintf(log_file, "LW %s, %d(%s)\n", mips_get_reg_name(rt), imm, mips_get_reg_name(rs));
		mips_lw(rt, imm, rs);
		break;
	case SW:
		fprintf(log_file, "SW %s, %d(%s)\n", mips_get_reg_name(rt), imm, mips_get_reg_name(rs));
		mips_sw(rt, imm, rs);
		break;
	case BEQ:
		fprintf(log_file, "BEQ %s, %d, %x\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	case BNE:
		fprintf(log_file, "BNE %s, %d, %x\n", mips_get_reg_name(rt), mips_get_reg_name(rs), imm);
		break;
	default:
		fprintf(log_file, "Instrucao tipo I nao reconhecida\n");
		break;
	}
}

void mips_decode_inst(int inst)
{
	// Os 6 bits mais significativos da instrução contêm o opcode, que identifica a operação a ser executada.
	int opcode = inst >> 26;

	log_file = fopen("log.txt", "a");

    if (log_file == NULL) {
        fprintf(log_file, "Erro ao abrir o arquivo de log\n");
        return;
    }

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

	fclose(log_file);
}
