#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>

#ifndef BUFF_SIZE
#define BUFFER_SIZE 1024
#endif

int get_next_line(int const fd, char **line);

#endif