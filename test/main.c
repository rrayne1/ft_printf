#include "../includes/ft_printf.h"

int main(void)
{
	int a = 0;
	int b = 0;

        a = printf("%c", 42);
        printf("\n");
        b = ft_printf("%c", 42);
        printf("\n %d %d\n", a, b);
        
        a = printf("@moulitest: %c", 0);
        printf("\n");
        b = ft_printf("@moulitest: %c", 0);
        printf("\n %d %d\n", a, b);
        
        a = printf("%2c", 0);
        printf("\n");
        b = ft_printf("%2c", 0);
        printf("\n %d %d\n", a, b);
        
        a = printf("null %c and text", 0);
        printf("\n");
        b = ft_printf("null %c and text", 0);
        printf("\n %d %d\n", a, b);
        
        a = printf("% c", 0);
        printf("\n");
        b = ft_printf("% c", 0);
        printf("\n %d %d\n", a, b);
        
        return (0);
}
