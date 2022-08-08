#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int print_char(va_list ap);
int print_str(va_list ap);
int _printf(const char *format, ...);


typedef struct PrintMap
	{
	char *type;
	int (*printer)(va_list);
} printmap;

#endif
