#include "../includes/ft_printf.h"

int 		start(va_list ft_printf_list, char **format, t_flags *tFlags)
{
	while(tFlags->flag == 0)
	{
        check_flags(&(*format), tFlags);
        check_types(&(*format), tFlags);
        check_format(ft_printf_list, &(*format), tFlags);
        ++(*format);
    }
	return (tFlags->total);
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

int			ft_printf(const char *format, ...)
{
	va_list 	ft_printf_list;
	t_flags		*tFlags;
	int 		res;
	char 		*str;

	res = 0;
	tFlags = (t_flags *)malloc(sizeof(t_flags));
	va_start(ft_printf_list, format);
	str = (char *)format;
	while (*str != 0)
	{
		init_flags(tFlags);
		if (*str == '%')
		{
			str++;
			if(!(check_val(str)))
				return (0);
			res += start(ft_printf_list, &str, tFlags);
		}
		else if (res != -1)
			res += ft_print_str(&str);
	}
	if (res == -1)
		res = 0;
	va_end(ft_printf_list);
	free(tFlags);
	return (res);
}

/*int 	main(void)
{
	int a = 0;
	int b = 0;
	//int a01, a02, a03, a04, a05, a06, a07, a08, a09, a10, a11, a12;

	a = printf("%", 0);
	printf("\n");
//	printf("%f\n", c);
	b = ft_printf("%", 5);
	printf("\n %d %d \n", a, b);
	return (0);
}*/