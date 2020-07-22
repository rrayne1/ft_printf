#include "../includes/ft_printf.h"

int		type_s(va_list ft_print_list, t_flags *tFlags)
{
	char 	*s;
	int		width;

	width = 0;
	tFlags->total = 0;
	s = va_arg(ft_print_list, char *);
	total_str(s, tFlags);
	if (tFlags->width != 0)
	{
		if (tFlags->minus == 1)
			ft_write(s, tFlags->total);
		while (width < (tFlags->width - tFlags->total))
		{
            ft_write(" ", 1);
            ++width;
        }
	}
	if (!tFlags->width || !tFlags->minus)
		ft_write((s) ? s : ("(null)"), tFlags->total);
	tFlags->total += width;
	tFlags->count += 1;
	return(tFlags->total);
}

int 	type_c(va_list ft_printf_list, t_flags *tFlags)
{
	char 	c;
	int		width;

	width = 0;
	c = va_arg(ft_printf_list, int);
	tFlags->total = 1;
	if (tFlags->width != 0)
	{
		if (tFlags->minus == 1)
			ft_write(&c, tFlags->total);
		while (width < (tFlags->width - tFlags->total))
		{
            ft_write(" ", 1);
            width++;
        }
	}
	if (!tFlags->width || !tFlags->minus)
		ft_write(&c, tFlags->total);
	tFlags->total += width;
    tFlags->count += 1;
	return(tFlags->total);
}

int 	type_d(va_list ft_printf_list, t_flags *tFlags)
{
	intmax_t 	nb;
	int			size;

	ft_get_nb(ft_printf_list, &nb, tFlags);
	size = ft_getsize((intmax_t)nb);
	if (tFlags->width != 0)
		tFlags->width -= size;
	size += (nb >= 0 && (tFlags->plus || tFlags->space));
	if (nb < 0)
		tFlags->neg = 1;
	if (tFlags->plus && tFlags->space)
		tFlags->space = 0;
	if (tFlags->minus && tFlags->zero == 0)
		tFlags->zero = 1;
	ft_display_d(nb, size, tFlags);
    tFlags->count += 1;
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
    tFlags->count += 1;
	return (tFlags->total);
}

int		type_o(va_list ft_print_list, t_flags *tFlags)
{
	uintmax_t	nb;
	int 		size;

	ft_get_nb_u(ft_print_list, &nb, tFlags);
	size = 0;
	ft_get_size_u(nb, 8, &size);
	if (tFlags->minus && tFlags->zero == 0)
		tFlags->zero = 1;
	if (tFlags->hash && (nb > 0 || tFlags->width < 0))
		size += 1;
	tFlags->width -= size;
	ft_display_o(nb, size, tFlags);
	if (tFlags->hash && nb == 0)
		tFlags->total = 1;
	tFlags->count += 1;
	return (tFlags->total);
}

int		type_u(va_list ft_printf_list, t_flags *tFlags)
{
	uintmax_t 	nb;
	int			size;

	ft_get_nb_u(ft_printf_list, &nb, tFlags);
	size = 0;
	ft_get_size_u((uintmax_t)nb, 10, &size);
	if (tFlags->width != 0)
		tFlags->width -= size;
	ft_display_u(nb, size, tFlags);
	tFlags->count += 1;
	return (tFlags->total);
}

int		type_x(va_list ft_printf_list, t_flags *tFlags)
{
	uintmax_t 	nb;
	int			size;

	ft_get_nb_u(ft_printf_list, &nb, tFlags);
	size = 0;
	ft_get_size_u((uintmax_t)nb, 10, &size);
	if (tFlags->width != 0)
		tFlags->width -= size;
	ft_display_x(nb, size, tFlags);
	tFlags->count += 1;
	return (tFlags->total);
}