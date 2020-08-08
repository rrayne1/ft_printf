#include "../includes/ft_printf.h"

int 	type_d(va_list ft_printf_list, t_flags *tFlags)
{
	intmax_t 	nb;
	int			size;

	ft_get_nb(ft_printf_list, &nb, tFlags);
	size = ft_getsize(nb);
	if (tFlags->width != 0)
		tFlags->width -= size;
	if (nb < 0 && (tFlags->neg = 1) == 1)
	{
		tFlags->width--;
		tFlags->total += 1;
	}
	if ((tFlags->plus || tFlags->space) && nb >= 0)
		tFlags->total += 1;
	if (tFlags->plus && tFlags->space)
		tFlags->space = 0;
	if (tFlags->minus && tFlags->zero == 0)
		tFlags->zero = 1;
	if (tFlags->prec > 0)
		tFlags->zero = 1;
	ft_display_d(nb, size, tFlags);
    tFlags->count += 1;
	return (tFlags->total);
}

void 	check_size(int *size, t_float *f, t_flags *tFlags)
{
	long double tmp;

	tmp = f->nb;
	if (tFlags->prec == -1)
		tFlags->prec = 6;
	if (tFlags->prec >= 0)
	{
		tmp += check_precision(f, tFlags);
		if ((int)tmp > (int)f->nb)
			f->nb += 1;
		f->type = (tFlags->type == TYPE_LF ? LDEC : DEC);
	}
	*size = *size > tFlags->width ? *size : tFlags->width;
	*size += tFlags->prec;
	if (f->nb < 0 && (tFlags->neg = 1) == 1)
		*size += 1;

}

void 	init_float(t_float *f)
{
	f->size = 0;
	f->type = 0;
	f->last = 0;
	f->first = 0;
	f->mod = 0;
	f->add = 0;
}



int 	type_f(va_list ft_printf_list, t_flags *tFlags)
{
	t_float 	*f;
	int 		size;

	if (!(f = (t_float *)malloc(sizeof(t_float))))
		return (0);
	init_float(f);
	f->nb = (tFlags->type == TYPE_LF ? \
									va_arg(ft_printf_list, long double) :\
									va_arg(ft_printf_list, double));
	size = 1;
	if (1.0 / f->nb == -1.0 / 0.0&& size--) {
		tFlags->neg = 1;
		f->nb = -f->nb;
	}
	check_size(&size, f, tFlags);
	if (tFlags->prec == 0)
		size = (ft_getsize((intmax_t)f->nb));
	ft_full(f, tFlags);
	free(f);
	tFlags->total = size;
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
	if ((tFlags->minus && tFlags->zero == 0) || tFlags->prec > 0 )
		tFlags->zero = 1;
	if (tFlags->prec > 0 && nb == 0)
		tFlags->hash = 0;
	if (tFlags->hash)
	{
		if (nb != 0)
			size += 1;
		else
			tFlags->width -= 1;
	}
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
	if ((tFlags->prec > 0 && tFlags->width) || \
			(!tFlags->zero && tFlags->minus))
		tFlags->zero = 1;
	ft_display_u(nb, size, tFlags);
	tFlags->count += 1;
	return (tFlags->total);
}