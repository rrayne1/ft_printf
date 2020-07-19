
#include "includes/ft_printf.h"

int main(void)
{
	int b = 0;

	b = ft_printf("%    %", "test");
	printf("\n%d", b);
	
	return (0);
}
