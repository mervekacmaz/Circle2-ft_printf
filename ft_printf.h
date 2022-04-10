#ifndef FT_PRINT_H
#define FT_PRINT_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *s, ...);
int print_char(char c);
int ft_check(char c, va_list *safe);
int print_nbr(int nb);

#endif
