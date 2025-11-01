#include <stdlib.h>

#include "square.h"

static void square_init(struct square *s, int side)
{
	if (s == NULL)
		return;
	s->side = side;
}

int square_area(struct square *s)
{
	if (s == NULL)
		return 0;
	return s->side * s->side;
}

struct square *square_create(int side)
{
	struct square *s = malloc(sizeof(struct square));
	if (s == NULL)
		return NULL;
	square_init(s, side);
	return s;
}

void square_destroy(struct square *s)
{
	if (s == NULL)
		return;
	free(s);
	s = NULL;
}
