#include "../includes/ft_printf.h"

int 	ft_get_nb(va_list ft_printf_list, t_flags *tFlags)
{
	intmax_t 	nb;

	nb = va_arg(ft_printf_list, intmax_t);
	if (tFlags->type == TYPE_H)
		nb = (short int)nb;
	if (tFlags->type == TYPE_HH)
		nb = (char)nb;
	if(tFlags->type == TYPE_L)
		nb = (long int)nb;
	if (tFlags->type == TYPE_LL)
		nb = (long long int)nb;
	else
		nb = (int)nb;

	return (nb);
}

int		ft_getsize(intmax_t n)
{
	intmax_t	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int 	ft_print_width(int width, t_flags *tFlags)
{
	while (tFlags->width > width)
	{
		if (tFlags->zero == 1)
			ft_write(" ", 1);
		if (tFlags->zero == 0)
			ft_write("0", 1);
		width++;
	}
	return (width);
}

void 		ft_print_sign(t_flags *tFlags)
{
	if (tFlags->neg == 0)
	{
		if (tFlags->plus == 1)
			ft_write("+", 1);
		if (tFlags->space == 1)
			ft_write(" ", 1);
	}
	if (tFlags->neg == 1)
		ft_write("-", 1);

}

void 	ft_putnbr_base(uintmax_t nb, char *str, uintmax_t length)
{
	if (nb >= length)
		ft_putnbr_base(nb / length, str, length);
	ft_write_char(str[nb % length], 1);
}
