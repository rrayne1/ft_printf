#include "../includes/ft_printf.h"
void	null_str(char *s, size_t *len, t_flags *tFlags)
{
	if (tFlags->prec == -2 || tFlags->prec == 0 || \
		(tFlags->prec >= 0 && !s))
	{
		if (tFlags->prec >= 6)
		{
			*len = 6;
		}
		else
		{
			*len = 0;
		}
	}
}

int		type_s(va_list ft_print_list, t_flags *tFlags)
{
	char 	*s;
	int		width;
	size_t 		len;

	width = 0;
	tFlags->total = 0;
	s = va_arg(ft_print_list, char *);
	total_str(s, &len, tFlags);
	null_str(s, &len, tFlags);
	if (tFlags->width != 0)
	{
		if (tFlags->minus == 1)
			ft_write((s) ? s : ("(null)"), len);
		while (width++ < tFlags->width)
		{
			ft_write(" ", 1);
		}
	}
	if (!tFlags->width || !tFlags->minus)
		ft_write((s) ? s : ("(null)"), len);
	tFlags->total = (len > 0 ? tFlags->total + (int)len : tFlags->total + 0);
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

int		type_p(va_list ft_printf_list, t_flags *tFlags, char *base)
{
	unsigned long int	nb;
	int			size;

	nb = va_arg(ft_printf_list, unsigned long int);
	if (!nb)
	{
		ft_write("(nil)", 5);
		tFlags->total = 5;
		tFlags->count = 1;
		return (tFlags->total);
	}
	size = 0;
	tFlags->hash = 1;
	tFlags->type = 6;
	ft_get_size_u((uintmax_t)nb, ft_strlen(base), &size);
	tFlags->width -= size;
	tFlags->width -= 2;
	ft_display_x(nb, &size, tFlags, base);
	if (tFlags->prec <= 0)
		total_dit(nb, size, tFlags);
	tFlags->total += 2;
	tFlags->count += 1;
	return (tFlags->total);
}