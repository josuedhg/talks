#ifndef CPU_H
#define CPU_H

struct cpu;

struct cpu *cpu_create();
void cpu_setup(struct cpu*);
void cpu_destroy(struct cpu*);

#endif
