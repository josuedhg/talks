#include "cpu.h"


int main()
{
	struct cpu *cpu = cpu_create();
	cpu_setup(cpu);
	cpu_destroy(cpu);
	return 0;
}
