#ifndef SQUARE_H
#define SQUARE_H

struct square {
	int side;
};

int square_area(struct square *s);
struct square *square_create(int side);
void square_destroy(struct square *s);

#endif
