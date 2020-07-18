#include "ft_printf.h"

void 	ft_display_f(char *nb, t_flags *tFlags)
{
	int width;

	width = 0;
	if (tFlags->plus == 1 || tFlags->space == 1)
		tFlags->width--;
	if (tFlags->zero == 0)
		ft_print_sign(tFlags);
	if (tFlags->minus == 0)
		ft_print_width(width, tFlags);
	if (tFlags->zero == 1)
		ft_print_sign(tFlags);
	if (tFlags->width > 0)
		tFlags->total -= tFlags->width;
	ft_write(nb, tFlags->total);
	if (tFlags->minus == 1 && tFlags->width > 0)
		ft_print_width(width, tFlags);
}

void 	ft_display_d(intmax_t nb, int size, t_flags *tFlags)
{
	int width;

	width = 0;
	if (tFlags->plus == 1 || tFlags->space == 1)
		tFlags->width--;
	if (tFlags->zero == 0)
		ft_print_sign(tFlags);
	if (tFlags->minus == 0)
		width = ft_print_width(width, tFlags);
	if (tFlags->zero == 1)
		ft_print_sign(tFlags);
	if (size > 0)
		ft_putnbr_base((uintmax_t) (nb < 0 ? -nb : nb), "0123456789", 10);
	if (tFlags->minus == 1 && tFlags->width > 0)
		width = ft_print_width(width, tFlags);
	tFlags->total = (width == size ? size + ft_getsize((intmax_t)(nb)) : \
						size + width);
}

int 		ft_print_str(char **format)
{
	int		len;

	if (ft_strchr(*format, '%'))
		len = (int)(ft_strchr(*format, '%') - *format);
	else
		len = (int)(ft_strlen(*format));
	ft_write(*format, len);
	(*format) += len;
	return (len);
}

void 	ft_write_char(char c, int size)
{
	ft_write(&c, size);
}
int 	ft_write(void *s, int size)
{
	char 	*str;
	int 	i;

	i = 0;
	str = s;
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (size);
}
