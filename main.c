#include "includes/ft_printf.h"

int main(void)
{
	int a = 0;
	int b = 0;

	a = printf("%0+5d", 42);
        printf("\n");
        b = ft_printf("%0+5d", 42);
        printf("\n %d %d\n", a, b);

	a = printf("%0+5d", -42);
        printf("\n");
        b = ft_printf("%0+5d", -42);
        printf("\n %d %d\n", a, b);
        
        a = printf("%-05d", 42);
        printf("\n");
        b = ft_printf("%-05d", 42);
        printf("\n %d %d\n", a, b);
        
        a = printf("%-05d", -42);
        printf("\n");
        b = ft_printf("%-05d", -42);
        printf("\n %d %d\n", a, b);
        
        return (0);
}
