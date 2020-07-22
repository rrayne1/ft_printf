#include "../includes/ft_printf.h"

void	ft_get_nb(va_list ft_printf_list, intmax_t *nb, t_flags *tFlags)
{
	*nb = va_arg(ft_printf_list, intmax_t);
	if (tFlags->type == TYPE_H)
		*nb = (short int)*nb;
	else if (tFlags->type == TYPE_HH)
		*nb = (char)*nb;
	else if(tFlags->type == 3)
		*nb = (long int)*nb;
	else if (tFlags->type == TYPE_LL)
		*nb = (long long int)*nb;
	else if (tFlags->type == 0)
		*nb = (int)*nb;
}

void	ft_get_nb_u(va_list ft_printf_list, uintmax_t *nb, t_flags *tFlags)
{
	*nb = va_arg(ft_printf_list, uintmax_t);
	if (tFlags->type == TYPE_H)
		*nb = (unsigned short int)*nb;
	else if (tFlags->type == TYPE_HH)
		*nb = (unsigned char)*nb;
	else if(tFlags->type == 3)
		*nb = (unsigned long int)*nb;
	else if (tFlags->type == TYPE_LL)
		*nb = (unsigned long long int)*nb;
	else if (tFlags->type == 0)
		*nb = (unsigned int)*nb;
}

int		ft_getsize(intmax_t n)
{
	intmax_t	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_get_size_u(uintmax_t nb, uintmax_t length, int *size)
{
	*size += 1;
	while (nb >= length)
	{
		nb /= length;
		*size += 1;
	}
}

void 	ft_putnbr_base(uintmax_t nb, char *str, uintmax_t length)
{
	if (nb >= length)
		ft_putnbr_base(nb / length, str, length);
	ft_write_char(str[nb % length], 1);
}

void 	ft_precision(t_flags *tFlags, int size)
{
	if (tFlags->precision > 0)
	{
		if (tFlags->plus || tFlags->space || tFlags->neg == 1)
			tFlags->precision -= (size - 1);
		else
			tFlags->precision -= size;
	}
	if (tFlags->width > 0 && tFlags->precision > 0)
		tFlags->width -= tFlags->precision;
	if (tFlags->precision > 0)
		tFlags->total += tFlags->precision;
}

int 	check_zero(uintmax_t nb, int *size, t_flags *tFlags)
{
	if (nb == 0 && (tFlags->precision == -2 || tFlags->precision == 0))
	{
		if (tFlags->width > 0)
			tFlags->width += *size;
		*size = 0;
		return (-1);
	}
	return (0);
}