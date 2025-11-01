#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "cpu.h"

#define BUS_WIDTH 32

struct cpu {
	uint8_t bus;
};

struct cpu *cpu_create()
{
	struct cpu *cpu = malloc(sizeof(struct cpu));
	if (cpu == NULL)
		return NULL;
	cpu->bus = BUS_WIDTH;
	printf("Creating CPU x86 with bus width %d\n", cpu->bus);
	return cpu;
}


void cpu_setup(struct cpu *cpu)
{
	if (cpu == NULL)
		return;
	puts("Setting up CPU x86");
}

void cpu_destroy(struct cpu *cpu)
{
	if (cpu == NULL)
		return;
	puts("Destroying CPU x86");
	free(cpu);
}
