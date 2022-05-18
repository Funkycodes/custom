#include "main.h"
#include <stdio.h>

void _printrev(char *s)
{
	if (!*s)
		return;
	s++;
	_printrev(s);
	s--;
	putchar(*s);
}

