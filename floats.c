#include "ft_printf.h"

int 	ft_infinity(char **s)
{
	if (!(s = malloc(sizeof(char) * 4)))
		return (0);
	*s = "inf";
	return (3);
}

double 	ft_modulo(double nb, int *size)
{
	double modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	(*size)++;
	return (modulo);
}

void 	ft_full_before(char **s, int *i, double modulo, double *nb)
{
	char *str;

	str = *s;
	while ((int)*nb != 0)
	{
		str[(*i)++] = ((char)(*nb / modulo) + 48);
		*nb -= (int)(*nb / modulo) * modulo;
		modulo /= 10;
	}
}

int		ft_full_after(char **s, int *i, t_flags *tFlags, double nb)
{
	int		j;
	int		tmp;

	if (tFlags->precision == 0)
		return (0);
	nb *= 10;
	j = 0;
	(*s)[(*i)++] = '.';
	tFlags->width --;
	while (j++ < tFlags->precision)
	{
		if ((int)nb == 0)
		{
			(*s)[(*i)++] = '0';
			continue ;
		}
		tmp = ((int)nb != 9) ? (int)(nb + 0.01) : (int)nb;
		(*s)[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
	return (1);
}

void 	check_precision(double *nb, int *size, t_flags *tFlags, double modulo)
{
	double tmp;

	tmp = (*nb);
	if ((*nb) < 0 && (*size)++ && (tFlags->neg = 1) == 1)
	{
		(*nb) = -(*nb);
		tmp *= -1;
		tFlags->width--;
	}
	while ((int)tmp != 0)
	{
		tmp -= (int) (tmp / modulo) * modulo;
		modulo /= 10;
	}
	if (tmp >= 0.5)
		(*nb) += (1.0 - tmp);
	else
		(*nb) -= tmp;
}

int 	ft_float_to_string(double nb, char **s, t_flags *tFlags)
{
	char 	*str;
	int 	size;
	int 	i;
	double	modulo;

	if (nb == INFINITY)
		return (ft_infinity(&str));
	size = 1;
	i = 0;
	modulo = ft_modulo(nb, &size);
	check_precision(&nb, &size, tFlags, modulo);
	size = size > tFlags->width ? size : tFlags->width;
	size += tFlags->precision;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (-1);
	ft_full_before(&str, &i, modulo, &nb);
	tFlags->width -= i;
	ft_full_after(&str, &i, tFlags, nb);
	str[i] = '\0';
	*s = str;
	return (size);
}