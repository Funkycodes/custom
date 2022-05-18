#include "main.h"
#include <stdio.h>

int numlen(unsigned int i, int base)
{
	int digit = 0;
	if (i == 0)
		digit++;
	while (i >= 1)
	{
		i = i / base;
		digit++;
	}
	return (digit);
}
