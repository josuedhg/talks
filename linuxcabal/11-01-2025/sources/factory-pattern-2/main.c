#include <stdio.h>

#include "square.h"


//extern void square_init(struct square *s, int side);

int main()
{
	struct square *s = square_create(5);
	printf("Area of square is %d\n", square_area(s));

//	square_init(s, 15);
	printf("side length is %d\n", s->side);
	square_destroy(s);
	return 0;
}
