#include "../includes/ft_printf.h"

int 		start(va_list ft_printf_list, char **format, t_flags *tFlags)
{
	init_flags(tFlags);
	while(tFlags->count == -1)
	{
        check_flags(&(*format), tFlags);
        check_types(&(*format), tFlags);
        check_format(ft_printf_list, &(*format), tFlags);
        ++(*format);
    }
	return (tFlags->total);
}

int			ft_printf(const char *format, ...)
{
	va_list 	ft_printf_list;
	t_flags		*tFlags;
	int 		res;
	char 		*str;

	res = 0;
	tFlags = (t_flags *)malloc(sizeof(t_flags));
	tFlags->count = -1;
	va_start(ft_printf_list, format);
	str = (char *)format;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			res += start(ft_printf_list, &str, tFlags);
		}
		else
			res += ft_print_str(&str);
	}
	va_end(ft_printf_list);
	free(tFlags);
	return (res);
}

int     main(void)
{
    int a = 0;
    int b = 0;

    a = printf("%.2s is a string", "");
    printf("\n");
    b = ft_printf("%.2s is a string", "");
    printf("\n %d %d\n", a, b);

    return (0);
}