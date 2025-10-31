#include <stdio.h>

#include "square.h"


int main()
{
	struct square *s = square_create(5);
	printf("Area of square is %d\n", square_area(s));
	square_destroy(s);
	return 0;
}
