#include "main.h"

void _printrev(char *s)
{
	if (!*s)
		return;
	s++;
	_printrev(s);
	s--;
	_putchar(*s);
}

