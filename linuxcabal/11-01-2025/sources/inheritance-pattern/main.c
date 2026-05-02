#include <stdio.h>
#include <stddef.h>

struct flyer {
};

void fly(struct flyer *f)
{
	puts("flying");
}

struct runner {
};

void run(struct runner *r)
{
	puts("running");
}

struct swimmer {
	char style[20];
};

void swim(struct swimmer *s)
{
	printf("swimming %s\n", s->style);
}

struct duck {
	struct flyer f;
	struct runner r;
	struct swimmer s;
};

int main()
{
	struct duck d = { .s = { .style = "floating" }};


	fly((struct flyer *)&d);
	run(&d.r);
	swim(&d.s);

	return 0;
}
