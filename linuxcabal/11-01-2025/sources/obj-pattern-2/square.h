#ifndef SQUARE_H
#define SQUARE_H

struct square {
	int side;
};

void square_init(struct square *, int);
int square_area(struct square *);

#endif
