#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) ({                      \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

//#define container_of(ptr, type, member) (type *)( (char *)(ptr) - offsetof(type,member) )

struct swimmer {
};

struct flyer {
};

struct runner {
};

struct duck {
	struct swimmer s;
	struct flyer f;
	struct runner r;
	char sound[10];
};

void swim(struct swimmer *s)
{
	if (s == NULL)
		return;
	struct duck *d = container_of(s, struct duck, s);
	printf("swimming %s\n", d->sound);
}

void fly(struct flyer *f)
{
	if (f == NULL)
		return;
	struct duck *d = container_of(f, struct duck, f);
	printf("flying %s\n", d->sound);
}

void run(struct runner *r)
{
	if (r == NULL)
		return;
	struct duck *d = container_of(r, struct duck, r);
	printf("running %s\n", d->sound);
}

int main()
{
	struct duck d = {.sound="quack", };

	swim((struct swimmer *)&d);

	fly(&d.f);
	run(&d.r);

	return 0;
}
