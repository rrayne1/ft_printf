/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <rrayne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:24:28 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 13:24:28 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <inttypes.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define TYPE_H 1
# define TYPE_HH 2
# define TYPE_L 3
# define TYPE_LL 4
# define TYPE_LF 5
# define P 6
# define DEC 1
# define LDEC 2

typedef struct		s_flags
{
	int				count;
	int				width;
	char			space;
	char			plus;
	char			minus;
	char			hash;
	char			zero;
	int				type;
	int				prec;
	int				neg;
	int				total;
}					t_flags;

typedef struct		s_float
{
	long double		nb;
	long double		mod;
	intmax_t		first;
	intmax_t		last;
	intmax_t		size;
	int				type;
	int				add;
}					t_float;

int					ft_printf(const char *format, ...);
int					start(va_list args, char **format);

void				init_flags(t_flags *flag);
void				check_flags(char **format, t_flags *flag);
void				check_types(char **format, t_flags *flag);
void				check_format(va_list args, char **format, \
									t_flags *flag);

int					type_s(va_list args, t_flags *flag);
int					type_c(va_list args, t_flags *flag);
int					type_d(va_list args, t_flags *flag);
int					type_f(va_list args, t_flags *flag);
int					type_o(va_list args, t_flags *flag);
int					type_u(va_list args, t_flags *flag);
int					type_x(va_list args, t_flags *flag, char *base);
int					type_p(va_list args, t_flags *flag, char *base);

void				ft_get_nb_u(va_list args, uintmax_t *nb, \
									t_flags *flag);
void				ft_get_nb(va_list args, intmax_t *nb, \
									t_flags *flag);

int					ft_getsize(intmax_t n);
void				ft_get_size_u(uintmax_t nb, uintmax_t length, int *size);
void				ft_putnbr_base(uintmax_t nb, char *str, uintmax_t length);
void				ft_precision(t_flags *flag, int size);
int					check_zero(uintmax_t nb, int *size, t_flags *flag);

int					ft_infinity(char **s, t_float *f);
double				ft_modulo(long double nb, int *size);
int					ft_full(t_float *f, t_flags *flag);
void				ft_check_str(char **str, int add);
void				ft_full_after(char **af, t_flags *flag, t_float *f);
int					check_precision(t_float *f, t_flags *flag);
void				init_float(t_float *f);
void				check_size(int *size, t_float *f, t_flags *flag);

void				ft_print_width(t_flags *flag);
void				ft_print_sign(t_flags *flag);
int					ft_print_percent(t_flags *flag);
int					ft_print_str(char **format);

void				ft_display_f(char *nb, t_flags *flag);
void				ft_display_d(intmax_t nb, int size, t_flags *flag);
void				ft_display_o(uintmax_t nb, int size, t_flags *flag);
void				ft_display_u(uintmax_t nb, int size, t_flags *flag);
void				ft_display_x(uintmax_t nb, int *size, t_flags *flag, \
									char *base);

int					ft_write(void *s, int size);
void				ft_write_char(char c, int size);
char				*ft_ditoa(intmax_t n);
char				*ft_strjoin_free(char *s1, char *s2);

void				total_str(char *s, size_t *len, t_flags *flag);
void				total_dit(intmax_t nb, int size, t_flags *flags);

#endif