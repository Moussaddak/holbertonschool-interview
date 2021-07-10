#ifndef SLIDE_H
#define SLIDE_H

#include <stddef.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT -1


int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_H */