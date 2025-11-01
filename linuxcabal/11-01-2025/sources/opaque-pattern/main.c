#include <stdio.h>

#include "cpu.h"


int main()
{
	struct cpu *cpu = cpu_create();
	if (!cpu) {
		printf("Error creating CPU\n");
		return 1;
	}
	cpu_setup(cpu);
	cpu_destroy(cpu);
	return 0;
}
