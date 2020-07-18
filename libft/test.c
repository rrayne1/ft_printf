#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include <string.h>

void ft_printf_str(va_list *my_list)
{
	char *src = va_arg(*my_list, char *);

	write(1, src, strlen(src));
}

void ft_printf_char(va_list *my_list)
{
	char c = va_arg(*my_list, int);

	write(1, &c, 1);
}

void ft_printf_nbr(va_list *my_list)
{
	int num = va_arg(*my_list, int);
	char buffer[20];

	sprintf(buffer, "%d", num);
	write(1, buffer, strlen(buffer));
}

int findIndex(char *tab, char element)
{
	int index = 0;

	while (tab[index] != 0)
	{
		if (tab[index] == element)
			return index;
		index++;
	}
	return (-1);
}

void ft_printf(char *src, ...)
{
	void (*tabFunc[3])(va_list *) = {ft_printf_str, ft_printf_char, ft_printf_nbr};
	char tabIndex[4] = {'s', 'c', 'd', 0};
	va_list my_list;
	int i = 0;
	int tmpIndex = 0;

	va_start(my_list, src);
	while (src[i] != 0)
	{
		if (i != 0 && src[i - 1] == '%')
		{
			tmpIndex = findIndex(tabIndex, src[i]);
			if (tmpIndex != -1)
				(*tabFunc[tmpIndex])(&my_list);
		} else if (src[i] != '%')
			write(1, &src[i], 1);
		i++;
	}
}

int main()
{
	ft_printf("%s %c", "Sergey", "#");
	return 0;
}
