#include "includes/ft_printf.h"

int main(void)
{
	int a = 0;
	int b = 0;

	a = printf("unix l %ld", 2147483648);
        printf("\n");
        b = ft_printf("ma l %ld", 2147483648);
        printf("\n %d %d\n", a, b);

	a = printf("unix l %ld", -2147483649);
        printf("\n");
        b = ft_printf("ma l %ld", -2147483649);
        printf("\n %d %d\n", a, b);
        
        a = printf("unix ll %lld", 9223372036854775807);
        printf("\n");
        b = ft_printf("ma ll %lld", 9223372036854775807);
        printf("\n %d %d\n", a, b);
        
        a = printf("unix ll %lld", -9223372036854775808);
        printf("\n");
        b = ft_printf("ma ll %lld", -9223372036854775808);
        printf("\n %d %d\n", a, b);
        
        return (0);
}
