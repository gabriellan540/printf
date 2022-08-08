#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _print - utility function for choosing printer function
 *	    varies with different format types
 *
 * @ap: va_list - current list of variadic variables
 * @format: the format to be printed
 *
 * Return: the number of characters printed
 *	   actual value is returned by the printer function
 */
int _print(va_list ap, char format)
{
	int iter;

	printmap printer[] = {
		{"c", print_char},
		{"s", print_str},
		{NULL, NULL}
	};

	for (iter = 0; printer[iter].type != NULL; iter++)
	{
		if (format == printer[iter].type[0])
		{
			return (printer[iter].printer(ap));
		}
	}
	return (0);
}

/**
 * _printf - implementation of the standard printf function
 *
 * @format: formatted string to be printed
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int i, count, chars_printed;
	va_list ap;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	count = 0;
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			continue;
		}
		if (format[i + 1] == '%')
		{
			count += _putchar('%');
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		chars_printed = _print(ap, format[i + 1]);
		if (chars_printed == 0)
		{
			_putchar('%');
			count++;
		}
		if (chars_printed > 0)
		{
			count += chars_printed;
			i++;
		}
		if (chars_printed == -1)
			i++;
	}
	va_end(ap);
	return (count);
}
