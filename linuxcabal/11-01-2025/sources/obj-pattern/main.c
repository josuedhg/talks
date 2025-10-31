#include <stdio.h>


struct square {
	int side;
};

void square_init(struct square *s, int side)
{
	s->side = side;
}

int square_area(struct square *s)
{
	return s->side * s->side;
}

int main()
{
	struct square s;
	square_init(&s, 10);
	printf("Area of square is %d\n", square_area(&s));
	return 0;
}
