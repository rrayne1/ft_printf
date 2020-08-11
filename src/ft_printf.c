/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:45:28 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 14:54:23 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		start(va_list args, char **format)
{
	t_flags		*flag;
	int			tres;

	flag = (t_flags *)malloc(sizeof(t_flags));
	init_flags(flag);
	while (flag->count == 0)
	{
		check_flags(format, flag);
		check_types(format, flag);
		check_format(args, format, flag);
		(*format)++;
	}
	tres = flag->total;
	free(flag);
	return (tres);
}

int		check_val(char *str)
{
	if (ft_strchr(str, 'd'))
		return (1);
	else if (ft_strchr(str, 'i'))
		return (1);
	else if (ft_strchr(str, 'o'))
		return (1);
	else if (ft_strchr(str, 'u'))
		return (1);
	else if (ft_strchr(str, 'x'))
		return (1);
	else if (ft_strchr(str, 'X'))
		return (1);
	else if (ft_strchr(str, 's'))
		return (1);
	else if (ft_strchr(str, 'c'))
		return (1);
	else if (ft_strchr(str, 'p'))
		return (1);
	else if (ft_strchr(str, 'f'))
		return (1);
	else if (ft_strchr(str, '%'))
		return (1);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			res;
	char		*str;

	res = 0;
	va_start(args, format);
	str = (char *)format;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			if (!(check_val(str)))
				return (0);
			res += start(args, &str);
		}
		else
			res += ft_print_str(&str);
	}
	va_end(args);
	return (res);
}
