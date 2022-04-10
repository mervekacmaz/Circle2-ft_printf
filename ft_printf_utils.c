#include "ft_printf.h"

/*
1. Handle the min value.
2. Handle the negative.
3. Handle >=10.
4. Handle numbers.
*/

int	print_nbr(int nb)
{
	long	n;
	int		len;

	n = nb;
	len = 0;

	if (n == -2147483648)
		len += write(1, "-2147483648", 50);
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if(n >= 10)
	{
		len += print_nbr(n / 10);
		len += print_nbr(n % 10);
	}
	if (n < 10)
		len += print_char(n + 48);
	return(len);
}

int	print_unsigned_integer(unsigned long int nb)
{
	unsigned int maxvalue;
	int	len;

	len = 0;

	maxvalue = 4294967295;
	if (nb < 0)
	{
		nb *= -1;
		len = maxvalue - nb;
		print_unsigned_integer(len);
	}

	else
	{
	if(nb >= 10)
	{
		len += print_unsigned_integer(nb / 10);
		nb = nb % 10;
	}
	if(nb < 10)
		print_char(nb + 48);
	}
	return (len);
}

int	print_hex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_hex(nb / 16, s);
		len += print_hex(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + 48);
		else
		{
			if (s == 1)
				len += print_char(nb + 87);
			else
				len += print_char(nb + 55);
		}
	}
	return (len);
}


