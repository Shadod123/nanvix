#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define bool int
#define true 1
#define false 0

#define REGISTER_LEN 16
#define MEMORY_LEN 256

enum MipsOperation
{
    //NOP   = 0x00000000,
    ADD   = 0x00000020,
    ADDI  = 0x20000000,
    ADDIU = 0x24000000,
    ADDU  = 0x00000021,
    AND   = 0x00000024,
    ANDI  = 0x30000000,
    BEQ   = 0x10000000,
    BNE   = 0x14000000,
    J     = 0x08000000,
    JAL   = 0x0C000000,
    JR    = 0x00000008,
    LUI   = 0x3C000000,
    LW    = (int32_t)0x8C000000,
    OR    = 0x00000025,
    ORI   = 0x34000000,
    SLT   = 0x0000002A,
    SLTI  = 0x28000000,
    SLTIU = 0x2C000000,
    SLTU  = 0x0000002B,
    SLL   = 0x00000000,
    SRL   = 0x00000002,
    SW    = (int32_t)0xAC000000U,
    SUB   = 0x00000022,
    SUBU  = 0x00000023,
};

int counter;
int zero = 0;
int registers[REGISTER_LEN];
int memory[MEMORY_LEN];
int lenght;

/**
 * @brief Retorna o valor do registrador especificado.
 *
 * @param reg O registrador para o qual o valor é desejado.
 * @return O valor do registrador especificado.
 */
int mips_get_reg(int reg)
{
	return registers[reg];
}

/**
 * @brief Define o valor do registrador especificado.
 *
 * @param reg O registrador a ser definido.
 * @param val O valor a ser atribuído ao registrador.
 * @return O valor atribuído ao registrador.
 */
int mips_set_reg(int reg, int val)
{
	return registers[reg] = val;
}

/**
 * @brief Carrega o programa na memória.
 *
 * @param program O programa a ser carregado na memória.
 * @param size O tamanho do programa em bytes.
 */
void mips_load(int *program, int size)
{
	lenght = size / sizeof(int);

	for (int i = 0; i < lenght; i++)
	{
		memory[i] = program[i];
	}
}

/**
 * @brief Limpa a memória.
 */
void mips_clean()
{
	memset(memory, 0, sizeof(memory));
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
        printf("ADD $%d, $%d, $%d\n", rd, rs, rt);
        break;
    case ADDU:  
        printf("ADDU $%d, $%d, $%d\n", rd, rs, rt);
        break;
    case SUB:
        printf("SUB $%d, $%d, $%d\n", rd, rs, rt);
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
        break;
    case SW:
        printf("SW $%d, %d($%d)\n", rt, imm, rs);
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

/**
 * @brief Executa as instruções armazenadas na memória.
 */
void mips_exec()
{
	int inst = 0;

	while (counter < lenght)
	{
		inst = memory[counter];

		mips_decode_inst(inst);

		counter++;
	}

	mips_clean();
}

/**
 * @brief Função principal do programa.
 *
 * @return 0 se a execução for bem-sucedida.
 */
int main()
{
	int size = 24 * sizeof(int);
	int *program = (int *)malloc(size);

	mips_clean();

	// Teste de decodificação de todas as instruções com bytecode implementado
	program  [0] = ADD;  
	program  [1] = ADDI; 
	program  [2] = ADDIU;
	program  [3] = ADDU;
	program  [4] = AND; 
	program  [5] = ANDI; 
	program  [6] = BEQ;  
	program  [7] = BNE;  
	program  [8] = J;    
	program  [9] = JAL;  
	program [10] = JR;   
	program [11] = LUI;  
	program [12] = LW;   
	program [13] = OR;   
	program [14] = ORI;  
	program [15] = SLT;  
	program [16] = SLTI; 
	program [17] = SLTIU;
	program [18] = SLTU; 
	program [19] = SLL;  
	program [20] = SRL;  
	program [21] = SW;   
	program [22] = SUB;  
	program [23] = SUBU; 

	mips_load(program, size);
	mips_exec();

	return 0;
}
