#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "cpu.h"

#define CPU_BRAND "Qualcomm"

struct cpu {
	uint8_t bus;
	char brand[20];
};

struct cpu *cpu_create() {
	struct cpu *cpu = malloc(sizeof(struct cpu));
	if (cpu == NULL)
		return NULL;
	cpu->bus = 32;
	strcpy(cpu->brand, CPU_BRAND);

	printf("Created CPU ARM bus %d and brand %s\n", cpu->bus, cpu->brand);
	return cpu;
}

void cpu_setup(struct cpu *cpu) {
	if (cpu == NULL)
		return;
	printf("Setting up CPU ARM bus %d and brand %s\n", cpu->bus, cpu->brand);
}

void cpu_destroy(struct cpu *cpu) {
	if (cpu == NULL)
		return;
	printf("Destroying CPU ARM bus %d and brand %s\n", cpu->bus, cpu->brand);
	free(cpu);
}
