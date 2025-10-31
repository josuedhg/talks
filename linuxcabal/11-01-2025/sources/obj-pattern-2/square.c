#include "square.h"

void square_init(struct square *s, int side)
{
	s->side = side;
}

int square_area(struct square *s)
{
	return s->side * s->side;
}


