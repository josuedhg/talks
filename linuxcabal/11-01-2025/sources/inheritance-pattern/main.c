#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) ({                      \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

//#define container_of(ptr, type, member) (type *)( (char *)(ptr) - offsetof(type,member) )

struct swimmer {
};

struct duck;

void swim(struct swimmer *s)
{
	printf("swimming\n");
}

struct flyer {
};

void fly(struct flyer *f)
{
	printf("flying\n");
}

struct runner {
};

void run(struct runner *r)
{
	printf("running\n");
}

struct duck {
	char sound[10];
	struct swimmer s;
	struct flyer f;
	struct runner r;
};

void swim2(struct swimmer *s)
{
	if (s == NULL)
		return;
	struct duck *d = container_of(s, struct duck, s);
	printf("swimming %s\n", d->sound);
}

int main()
{
	struct duck d = {"quack", };

	swim((struct swimmer *)&d);

	fly(&d.f);
	run(&d.r);

	swim2(&d.s);

	return 0;
}
