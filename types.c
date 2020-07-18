#include "ft_printf.h"

int		type_s(va_list ft_print_list, t_flags *tFlags)
{
	char 	*s;
	int		width;

	width = -1;
	tFlags->total = 0;
	s = va_arg(ft_print_list, char *);
	tFlags->total = ft_strlen(s);
	if (tFlags->width != 0)
	{
		if (tFlags->minus == 1)
			ft_write(s, tFlags->total);
		while (++width < (tFlags->width - tFlags->total))
			ft_write(" ", 1);
	}
	if (!tFlags->width || !tFlags->minus)
		ft_write((s) ? s : ("null"), tFlags->total);
	tFlags->total += width;
	return(tFlags->total);
}

int 	type_c(va_list ft_printf_list, t_flags *tFlags)
{
	char 	c;
	int		width;

	width = -1;
	c = va_arg(ft_printf_list, int);
	tFlags->total = 1;
	if (tFlags->width != 0)
	{
		if (tFlags->minus == 1)
			ft_write(&c, tFlags->total);
		while (++width < (tFlags->width - tFlags->total))
			ft_write(" ", 1);
	}
	if (!tFlags->width || !tFlags->minus)
		ft_write((c) ? &c : ("null"),tFlags->total);
	tFlags->total += width;
	return(tFlags->total);
}

int 	type_d(va_list ft_printf_list, t_flags *tFlags)
{
	intmax_t 	nb;
	int			size;

	nb = ft_get_nb(ft_printf_list, tFlags);
	size = ft_getsize((intmax_t)nb);
	tFlags->width -= size;
	size = (tFlags->width > size ? tFlags->width : size);
	size += (nb > 0 && (tFlags->plus || tFlags->space));
	if (nb < 0)
	{
		size += 1;
		tFlags->neg = 1;
	}
	ft_display_d(nb, size, tFlags);
	return (tFlags->total);
}

int 	type_f(va_list ft_printf_list, t_flags *tFlags)
{
	char	*nb;

	if (tFlags->precision == -1)
		tFlags->precision = 6;
	tFlags->width -= tFlags->precision;
	tFlags->total = ft_float_to_string(va_arg(ft_printf_list, double), &nb, tFlags);
	ft_display_f(nb, tFlags);
	free(nb);
	return (tFlags->total);
}