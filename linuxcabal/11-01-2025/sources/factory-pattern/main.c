#include <stdio.h>
#include <stdlib.h>


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

struct square *square_create(int side)
{
	struct square *s = malloc(sizeof(struct square));
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

int main()
{
	struct square *s = square_create(5);
	printf("Area of square is %d\n", square_area(s));
	square_destroy(s);
	return 0;
}
