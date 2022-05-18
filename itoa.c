#include <stdlib.h>
#include "main.h"

char *itoa(unsigned int num, int base)
{
	int len;
	char *p = malloc(sizeof(char) * numlen(num, base) + 1);
	int i;
	len = numlen(num, base);

	for (i = 0; i < len; i++)
	{
		char ch = (num % base);
		if(ch>= 0 && ch <= 9)
		{
			ch += '0';
		}
		else
		{
			ch += 87;
		}
		num /= base;
		*(p + i) = ch;
	}
	return p;
}

void ftoa(double n)
{
	int ipart = (int)n;
	double fpart = n - (double)ipart;

	_printd(ipart, 10);
	fpart = fpart * 1000000;
	putchar('.');
	_printd((int)fpart, 10);
}

void _printd(int num, int base)
{
	if (num < 0)
		putchar('-');
	if (num < 0)
		num *= -1;
	_printrev(itoa(num, base));
}
void _printu(unsigned long int num)
{
	_printrev(itoa(num, 10));
}

void _printx(int num)
{
	if (num < 0)
	{
		num *= -1;
		putchar('-');
	}
	_printrev(itoa(num, 16));
}

