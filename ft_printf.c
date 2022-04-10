/*
1. Write a function that handles the char
2. Write a function that checks the sign
3. Write your implementation of printf
*/

#include "ft_printf.h"

int	print_char(char c)
{
	int len;

	len = write(1, &c, 1);
	return(len);
}

int	print_str(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_check(char c, va_list *safe)
{
	int len;

	len = 0;

	if (c == 'c')
		len += print_char(va_arg(*safe, int));
	if(c == 'd' || c == 'i')
		len += print_nbr(va_arg(*safe, int));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int	len;
	int i;
	va_list safe;

	len = 0;
	i = 0;
	va_start(safe, s);
	while(s[i])
	{
		if(s[i] != '%')
			len += write(1, &s[i], 1);
		if(s[i] == '%')
		{
			len += ft_check(s[i + 1], &safe);
			i++;
		}
		i++;
	}
	va_end(safe);
	return(len);
}
