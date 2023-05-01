#pragma once

#include "types.h"

/**
 * @brief Retorna o valor do registrador especificado.
 *
 * @param reg O registrador para o qual o valor é desejado.
 * @return O valor do registrador especificado.
 */
int mips_get_reg(int reg);

/**
 * @brief Define o valor do registrador especificado.
 *
 * @param reg O registrador a ser definido.
 * @param val O valor a ser atribuído ao registrador.
 * @return O valor atribuído ao registrador.
 */
void mips_set_reg(int reg, int val);

/**
 * @brief Retorna o nome do registrador especificado.
 *
 * @param reg O registrador para o qual o nome é desejado.
 * @return O nome do registrador especificado.
 */
char *mips_get_reg_name(int reg);
