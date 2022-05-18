#include "main.h"
#include <stdio.h>

void _puts(const char *p)
{
	while (*(p))
	{
		putchar(*(p++));
	}
}
