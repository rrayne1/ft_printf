#include "../includes/ft_printf.h"

int main(void)
{
	int a = 0;
	int b = 0;

	a = printf("%.2s is a string", "");
        printf("\n");
        b = ft_printf("%.2s is a string", "");
        printf("\n %d %d\n", a, b);
        
	
        a = printf("%5.2s is a string", "");
        printf("\n");
        b = ft_printf("%5.2s is a string", "");
        printf("\n %d %d\n", a, b);
        
        a = printf("%-.2s is a string", "");
        printf("\n");
        b = ft_printf("%-.2s is a string", "");
        printf("\n %d %d\n", a, b);
        
        a = printf("%-5.2s is a string", "");
        printf("\n");
        b = ft_printf("%-5.2s is a string", "");
        printf("\n %d %d\n", a, b);
        
        a = printf("%s %s", "this", "is");
        printf("\n");
        b = ft_printf("%s %s", "this", "is");
        printf("\n %d %d\n", a, b);
        
        a = printf("%s %s %s", "this", "is", "a");
        printf("\n");
        b = ft_printf("%s %s %s", "this", "is", "a");
        printf("\n %d %d\n", a, b);
        
        a = printf("%s %s %s %s", "this", "is", "a", "multi");
        printf("\n");
        b = ft_printf("%s %s %s %s", "this", "is", "a", "multi");
        printf("\n %d %d\n", a, b);
        
        a = printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
        printf("\n");
        b = ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
        printf("\n %d %d\n", a, b);
        
        a = printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
        printf("\n");
        b = ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
        printf("\n %d %d\n", a, b);
        
        return (0);
}
