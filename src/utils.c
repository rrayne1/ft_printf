/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:47:08 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 14:47:10 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_write_char(char c, int size)
{
	ft_write(&c, size);
}

int			ft_write(void *s, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = s;
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (size);
}

char		*ft_ditoa(intmax_t n)
{
	int				len;
	char			*num;
	int				i;
	uintmax_t		nb;

	((n > 0) ? (nb = (uintmax_t)n) :\
	(nb = (uintmax_t)(-n)));
	len = ft_getlen(nb);
	i = len - 1;
	if (!(num = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
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

char		*ft_strjoin_free(char *s1, char *s2)
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
	free(s1);
	return (str);
}
