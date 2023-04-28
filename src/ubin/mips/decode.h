#pragma once

#include "types.h"

char *mips_get_reg_name(int reg);

/**
 * @brief Decodifica e executa instruções do tipo R (registrador) do MIPS.
 *
 * @param inst Instrução a ser decodificada e executada.
 * @param opcode Código da operação a ser executada.
 */
void mips_typeR_inst(int inst, int opcode);

/**
 * @brief Decodifica e executa instruções do tipo J (jump) do MIPS.
 *
 * @param inst Instrução a ser decodificada e executada.
 * @param opcode Código da operação a ser executada.
 */
void mips_typeJ_inst(int inst, int opcode);

/**
 * @brief Decodifica e executa instruções do tipo I (imediato) do MIPS.
 *
 * @param inst Instrução a ser decodificada e executada.
 * @param opcode Código da operação a ser executada.
 */
void mips_typeI_inst(int inst, int opcode);

/**
 * @brief Decodifica a instrução MIPS de 32 bits passada como parâmetro e executa a operação correspondente.
 *
 * @param inst a instrução MIPS de 32 bits a ser decodificada e executada
 */
void mips_decode_inst(int inst);
