#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

#include "get_next_line.c"
#include "get_next_line_utils.c"

int main ()
{
	char *str = NULL;

	do
	{
		str = get_next_line(1);
		printf("%s", str);
	}
	while (str);
	return (0);
}
