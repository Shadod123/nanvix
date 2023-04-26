#pragma once

#include "types.h"

/**
 * @brief Executa as instruções armazenadas na memória.
 */
void mips_exec();

/**
 * @brief Lê o valor de memória no endereço especificado.
 *
 * @param addr Endereço de memória a ser lido.
 * @return Valor lido da memória.
 */
int mips_read_mem(int addr);

/**
 * @brief Escreve um valor na memória no endereço especificado.
 *
 * @param addr Endereço de memória a ser escrito.
 * @param val Valor a ser escrito na memória.
 */
void mips_write_mem(int addr, int val);

/**
 * @brief Carrega o programa na memória.
 *
 * @param program O programa a ser carregado na memória.
 * @param size O tamanho do programa em bytes.
 */
void mips_load(int *program, int size);

/**
 * @brief Limpa a memória.
 */
void mips_clean();
