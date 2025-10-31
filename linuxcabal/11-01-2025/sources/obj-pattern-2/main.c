#include <stdio.h>

#include "square.h"

int main()
{
	struct square s;
	square_init(&s, 10);
	printf("Area of square is %d\n", square_area(&s));
	return 0;
}
