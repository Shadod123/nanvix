#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define REGISTER_LEN 16
#define MEMORY_LEN 256

int counter;
int registers[REGISTER_LEN];
int memory[MEMORY_LEN];
int lenght;
