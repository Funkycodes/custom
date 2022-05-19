#include "main.h"

void _puts(const char *p)
{
	while (*(p))
	{
		_putchar(*(p++));
	}
}

