
#include "includes/ft_printf.h"

int main(void)
{
	int a = 0;
	int b = 0;

	a = printf("%+d\n", 42);
	b = ft_printf("%+d\n", 42);
	printf("%d %d", a, b);
	
	return (0);
}
