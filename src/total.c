#include "../includes/ft_printf.h"

void 	total_str(char *s, t_flags *tFlags)
{
	if (!s)
		tFlags->total = 6;
	else if ((ft_strlen(s)) == 0 || tFlags->precision == -1)
		tFlags->total = ft_strlen(s);
	else
		tFlags->total = ft_strlen(s) - (size_t)tFlags->precision;
}

void 	total_dit(intmax_t nb, int size, t_flags *tFlags)
{
	if (tFlags->width == size && size != 0)
		tFlags->total += size + ft_getsize((intmax_t) (nb));
	if (tFlags->width != size && tFlags->width >= 0)
		tFlags->total += size + tFlags->width;
	if (tFlags->width < 0)
		tFlags->total += size;
}
