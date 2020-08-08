#include "../includes/ft_printf.h"

int 	ft_infinity(char **s, t_float *f)
{

	if (!(*s = ft_strnew((f->nb == INFINITY || f->nb == NAN ? 4 : 5))))
		return (0);
	if (f->nb == INFINITY)
		*s = "inf";
	if (f->nb == -INFINITY)
		*s = "-inf";
	if (f->nb == NAN)
		*s = "nan";
	return (ft_strlen(*s));

}

double 	ft_modulo(long double nb, int *size)
{
	double modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	(*size)++;
	return (modulo);
}

char*	ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = (int)(s2 ? ft_strlen(s1) + ft_strlen(s2) : ft_strlen(s1) + 0);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	if (s2)
	{
		ft_strcat(str, s2);
		free(s2);
	}
	free (s1);
	return (str);
}

#include "libft.h"

char	*ft_ditoa(int n, t_flags *tFlags)
{
	int				len;
	char			*num;
	int				i;
	unsigned int	nb;

	((n > 0) ? (nb = (unsigned int)n) :\
	(nb = (unsigned int)(-n)));
	len = ft_getlen(nb);
	i = len - 1;
	if (!(num = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (nb >= 0 && tFlags->neg == 1)
		num[0] = '-';
	if (n == 0)
		num[0] = '0';
	while (nb != 0)
	{
		num[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	num[len] = 0;
	return (num);
}

int	ft_full(t_float *f, t_flags *tFlags)
{
	char	*bf;
	char	*af;
	char 	*s;
	intmax_t tmp;

//	if (f->nb == INFINITY || f->nb == -INFINITY || f->nb == NAN)
	//	return (ft_infinity(&s, f));
	tmp = (intmax_t)f->nb;
	bf = ft_ditoa(tmp, tFlags);
	f->nb -= tmp;
	if (tFlags->prec > 0)
	{
		if (!(af = ft_strnew(tFlags->prec + 1)))
			return (0);
		ft_full_after(&af, tFlags, f);
	}
	else
		af = 0;
	if (!(s = ft_strjoin_free(bf, af)))
		return (0);
	tFlags->neg = 0;
	ft_display_f(s, tFlags);
	free(s);
	return (tFlags->total);
}

void 	get_prec(t_float *f, long double nb, t_flags *tFlags)
{
	long double		tmp;
	int 			tprec;
	int 			tsize;

	if (tFlags->prec == 0 || (tFlags->prec == 1 && !f->type))
		f->size = 1;
	tprec = tFlags->prec;
	tsize = 0;
	while (tprec-- + 1)
	{
		tmp = (intmax_t)(nb * 10);
		nb = nb * 10;
		if ((int)tmp == 0)
			tsize ++;
	}

	if ((f->size = ft_getsize((intmax_t)tmp)) > 1)
	{
		while ((intmax_t)(tmp / 10) % 10 == 0 && (intmax_t)tmp % 10 == 0)
			tmp /= 10;
		f->size = ft_getsize((intmax_t) tmp);
	}
	f->size += tsize;
}

void 	ft_get_fal(t_float *f, long double nb, t_flags *tFlags)
{
	int i;

	nb *= 10;
	f->first = (int)nb;
	i = (int)f->size - 1;
	while (i-- > 0)
		nb *= 10;
	if ((intmax_t)nb % 10 == 9)
	{
		f->last = (intmax_t)nb % 10;
		while ((intmax_t)nb % 10 == 9 && (intmax_t)nb != 0)
			nb /= 10;
		if ((intmax_t)nb % 10 == 0)
		{
			if ((((intmax_t)(nb / 10) % 10) % 2) == 0 && ((intmax_t)(nb / 10) % 10) != 0)
			f->first = ((intmax_t)nb / 10) % 10;
		}
		else
			f->first = (intmax_t)nb % 10;
	}
	else if (((intmax_t)nb % 10) == 5)
	{
		f->last = (intmax_t)nb % 10;
		if (f->type > 0)
		{
			if (f->size > 1)
				f->first = (intmax_t) (nb / 10) % 10;
			if (f->size > tFlags->prec)
				f->first = f->last;
		}
	}
	if (f->last == 0)
	{
		f->last = (intmax_t) nb % 10;
		if (f->first == 9 && f->last == 8 && !f->type)
			f->first = (intmax_t) (nb / 10) % 10;
		if (f->type == LDEC) {
			nb /= 10;
			f->last = (intmax_t) nb % 10;
			f->first = (intmax_t) (nb / 10) % 10;
		}
	}
}

int 	check_precision(t_float *f, t_flags *tFlags)
{
	long double		tmp;
	int 			tsize;

	tsize = 1;
	tmp = f->nb;
	f->mod = ft_modulo(tmp, &tsize);
	if ((((int)tmp / (int)f->mod) % 10) == 9)
		tFlags->count = 1;
	tmp -= (int)tmp;
	get_prec(f, tmp, tFlags);
	ft_get_fal(f, tmp, tFlags);
	if (f->type == LDEC)
		return (0);
	if (!f->type)
	{
		if (tFlags->prec == 0 && f->first >= 5 && ((int)f->nb % 2) != 0)
			return (1);
		if (f->first <= 5)
			return (0);
		if (f->first == 9 && !f->last)
			return (tFlags->prec == 0 ? 1 : 0);
		if (f->first == 9)
			return (f->last == 8 || f->last == 9 ? 1 : 0);
		if (f->last == 9)
			return (0);
	}
	if (f->type > 0)
	{
		if (!f->last && f->type == DEC)
			return (0);
		if (!f->last && f->type == LDEC)
			return ((f->first % 2) == 0 ? 1 : 0);
		if ((f->first % 2) == 0 && (f->last % 2) == 0 && f->type == LDEC)
			return (1);
		if (f->first == f->last)
			return (f->first >= 5 ? 1 : 0);
		if (f->last == 9)
			return (((f->first % 2) == 0) || f->first <= 5 ? 1 : 0);
		if (((f->last % 2) == 0 && f->last > 5) || (f->last > 5 && f->last != 9))
			return (1);
		if (f->last == 5)
			return ((((f->first % 2) == 0) || f->first == 9) ? 1 : 0);
		if (f->last < 5 || ((f->last % 2) == 0))
			return (0);
	}
	else
		return (!f->type && (f->first != 9 || (f->last % 2) == 0) ? 0 : 1);
	return (0);
}

void	ft_check_str(char **str, int add)
{
	int i;
	int nb;
	char 	*s;
	int		mod;

	s = *str;
	i = (int)ft_strlen(&(**str)) - 1;
	if (add == 1)
	{
		while (s[i] == '9')
		{
			s[i] = '0';
			i--;
		}
		if (s[i] != '.')
		{
			nb = ft_atoi(&(s[i]));
			mod = (int)ft_modulo(nb, &add);
			nb = (nb / mod) + 1;
			s[i] = (char) (nb + '0');
		}
	}
}

void	ft_full_after(char **af, t_flags *tFlags, t_float *f)
{
	int j;
	int tmp;
	int i;
	int add;

	i = 0;
	if (f->nb < 0)
		f->nb = -f->nb;
	if (tFlags->prec > 0)
		(*af)[i++] = '.';
	tFlags->total += 1;
	j = 0;
	tFlags->type = 7;
	add = check_precision(f, tFlags);
	while (j++ < tFlags->prec) {
		tmp = (intmax_t)(f->nb * 10);
		(*af)[i++] = (char) (tmp + '0');
		f->nb = f->nb * 10 - tmp;
	}
	ft_check_str(af, add);
}