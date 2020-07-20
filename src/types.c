#include "../includes/ft_printf.h"

void 	check_total(char *s, t_flags *tFlags)
{
	if (!s)
		tFlags->total = 6;
	else if ((ft_strlen(s)) == 0 || tFlags->precision == -1)
		tFlags->total = ft_strlen(s);
	else
		tFlags->total = ft_strlen(s) - (size_t)tFlags->precision;
}

int		type_s(va_list ft_print_list, t_flags *tFlags)
{
	char 	*s;
	int		width;

	width = 0;
	tFlags->total = 0;
	s = va_arg(ft_print_list, char *);
	check_total(s, tFlags);
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

	nb = ft_get_nb(ft_printf_list, tFlags);
	size = ft_getsize((intmax_t)nb);
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
