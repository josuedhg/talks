#include <stdlib.h>

#include "square.h"

void square_init(struct square *s, int side)
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


