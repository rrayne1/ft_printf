#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include "libft/libft.h"

#define TYPE_H 1
#define TYPE_HH 2
#define TYPE_L 3
#define TYPE_LL 4

typedef struct 		s_flags
{
	int				count;
	int				width;
	char			space;
	char 			plus;
	char 			minus;
	char 			hash;
	char 			zero;
	char 			type;
	int 			precision;
	int 			neg;
	int 			total;
}					t_flags;

int					ft_printf(const char *format, ...);
int 				start(va_list ft_printf_list, char **format, \
							t_flags *tFlags);

void 				init_flags(t_flags *tFlags);
int					check_flags(char **format, t_flags *tFlags);
void 				check_types(char **format, t_flags *tFlags);
int					check_format(va_list ft_printf_list, char **format, \
									t_flags *tFlags);

int					type_s(va_list ft_print_list, t_flags *tFlags);
int 				type_c(va_list ft_printf_list, t_flags *tFlags);
int 				type_d(va_list ft_printf_list, t_flags *tFlags);
int 				type_f(va_list ft_printf_list, t_flags *tFlags);

int 				ft_get_nb(va_list ft_printf_list, t_flags *tFlags);
int					ft_getsize(intmax_t n);
int 				ft_print_width(int width, t_flags *tFlags);
void 				ft_print_sign(t_flags *tFlags);
void 				ft_putnbr_base(uintmax_t nb, char *str, uintmax_t length);

int					ft_infinity(char **s);
double				ft_modulo(double nb, int *size);
void				ft_full_before(char **s, int *i, double modulo, double *nb);
int 				ft_full_after(char **s, int *i, t_flags *tFlags, double nb);
int 				ft_float_to_string(double nb, char **s, t_flags *tFlags);

void				ft_display_f(char *nb, t_flags *tFlags);
void 				ft_display_d(intmax_t nb, int size, t_flags *tFlags);
int 				ft_write(void *s, int size);
void 				ft_write_char(char c, int size);
int 				ft_print_str(char **format);

#endif
