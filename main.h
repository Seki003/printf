#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_string(char *str_char);
int format_c(const char *format);
int print_char(int a, int c, int b);
int print_int(va_list arg);
int print_number(int num, int len);

#endif
