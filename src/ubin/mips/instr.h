#pragma once

#include "types.h"

/**
 * @brief Realiza a operação de adição entre os registradores rs e rt, e armazena o resultado no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_add(int rd, int rs, int rt);

/**
 * @brief Realiza a operação de subtração entre os registradores rs e rt, e armazena o resultado no registrador rd.
 *
 * @param rd Registrador de destino da operação.
 * @param rs Registrador de origem 1 da operação.
 * @param rt Registrador de origem 2 da operação.
 */
void mips_sub(int rd, int rs, int rt);

/**
 * @brief Carrega uma palavra (word) da memória na registrador rd.
 *
 * @param rd Registrador destino para armazenar a palavra carregada.
 * @param imm Deslocamento com sinal de 16 bits que é adicionado ao registrador rs para obter o endereço da memória.
 * @param rs Registrador fonte que contém o endereço base da memória.
 */
void mips_lw(int rd, int imm, int rs);

/**
 * @brief Armazena uma palavra (word) do registrador rd na memória.
 *
 * @param rd Registrador fonte que contém a palavra a ser armazenada.
 * @param imm Deslocamento com sinal de 16 bits que é adicionado ao registrador rs para obter o endereço da memória.
 * @param rs Registrador fonte que contém o endereço base da memória.
 */
void mips_sw(int rd, int imm, int rs);
