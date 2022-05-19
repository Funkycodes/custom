#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *fmt, ...)
{
	va_list list;
	int printed = 0, count = 0;
	int num;
	char *s;
	char c;
	double f;

	if (!fmt)
		return -1;

	va_start(list, fmt);

	while (fmt[count])
	{
		if (fmt[count] == '%')
		{
			if (fmt[count + 1] == '\0')
				return -1;
			switch (fmt[count + 1])
			{
			case 'd':
			case 'i':
				num = va_arg(list, int);
				_printd(num, 10);
				printed += numlen(num, 10);
				count += 2;
				break;
			case 's':
				s = va_arg(list, char *);
				_puts(s);
				printed += _strlen(s);
				count += 2;
				break;
			case 'b':
				num = va_arg(list, int);
				printed += numlen(num, 2);
				count += 2;
				_printd(num, 2);
				break;
			case 'c':
				c = va_arg(list, int);
				_putchar(c);
				count += 2;
				printed += 1;
				break;
			case 'f':
				f = va_arg(list, double);
				ftoa(f);
				count += 2;
				printed += numlen((int)f, 10) + 7;
				break;
			case 'r':
				s = va_arg(list, char *);
				_printrev(s);
				count += 2;
				printed += _strlen(s);
				break;
			case 'u':
				num = va_arg(list, unsigned int);
				_printu((num));
				printed += numlen(num, 10);
				count += 2;
				break;
			case 'o':
				num = va_arg(list, unsigned int);
				_printd(num, 8);
				count += 2;
				printed += numlen(num, 8);
				break;
			case 'x':
			case 'X':
				num = va_arg(list, int);
				_printx(num);
				count += 2;
				printed += numlen(num, 16);
				break;
			case '%':
				_putchar('%');
				printed += 1;
				count += 1;
				break;
			default:
				count += 1;
				break;
			}
		}
		else
		{
			_putchar(fmt[count]);
			printed += 1;
			count += 1;
		}
	}
	va_end(list);
	return printed;
}

int main(void)
{

	printf("Lift is %x\n", 67894677);
	_printf("Lift is %r %b\n", "Habib",64);
	_printu(4294967295);
	_putchar(10);
}
