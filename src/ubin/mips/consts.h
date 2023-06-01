#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define REGISTER_LEN 16
#define MEMORY_LEN 1024

int mips_counter;
int mips_reg_bank[REGISTER_LEN];
int mips_memory_buffer[MEMORY_LEN];
int mips_memory_len;
int mips_cycles;
