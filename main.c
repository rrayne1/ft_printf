#include "ft_printf.h"

int main(void)
{
	int a = 0;
	int b = 0;

	a = printf("%s %d, Enjoy!\n", "Hello", 42);
	b = ft_printf("%s %d, Enjoy!\n", "Hello", 42);
	printf("%d %d", a, b);
	
	return (0);
}
