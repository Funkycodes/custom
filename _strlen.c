#include "main.h"

int _strlen(const char *p)
{
	int i = 0;

	while (*(p++))
		i++;
	return i;
}

