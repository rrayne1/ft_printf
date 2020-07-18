#include "../includes/ft_printf.h"

void 	init_flags(t_flags *tFlags)
{
	tFlags->width = 0;
	tFlags->zero = 1;
	tFlags->hash = 0;
	tFlags->minus = 0;
	tFlags->plus = 0;
	tFlags->precision = -1;
	tFlags->neg = 0;
	tFlags->space = 0;
}
void 	check_width(char **format, t_flags *tFlags)
{
	if (*(*format - 1) == 46)
	{
		tFlags->precision = ft_atoi(&(*(*format)));
		(*format) += (ft_getlen(tFlags->precision) - 1);
	}
	if(*(*format - 1) != 46)
	{
		tFlags->width = ft_atoi(&(*(*format)));
		(*format) += (ft_getlen(tFlags->width));
	}
}
int		check_flags(char **format, t_flags *tFlags)
{
	if (*(*format) == 32)
		tFlags->space = 1;
	else if (*(*format) == 43)
		tFlags->plus = 1;
	else if (*(*format) == 45)
		tFlags->minus = 1;
	else if (*(*format) == '0' && *(*format - 1) != 46)
		tFlags->zero = 0;
	else if (*(*format) == 35)
		tFlags->hash = 1;
	if ((ft_isdigit(*(*format))) == 1)
		check_width(format, tFlags);
	return (0);
}

void 	check_types(char **format, t_flags *tFlags)
{
	if (*(*format) == 'h' && *(*format - 1) != 'h')
		tFlags->type = TYPE_H;
	if (*(*format) == 'h' && *(*format + 1) == 'h')
		tFlags->type = TYPE_HH;
	if (*(*format) == 'l' && *(*format + 1) != 'h')
		tFlags->type = TYPE_L;
	if (*(*format) == 'l' && *(*format + 1) == 'l')
		tFlags->type = TYPE_LL;
}


int		check_format(va_list ft_printf_list, char **format, t_flags *tFlags)
{
	if (*(*format) == 's')
		type_s(ft_printf_list, tFlags);
	if (*(*format) == 'c')
		type_c(ft_printf_list, tFlags);
	if (*(*format) == 'd')
		type_d(ft_printf_list, tFlags);
	if (*(*format) == 'f')
		type_f(ft_printf_list, tFlags);
	return (tFlags->total);
}
