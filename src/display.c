#include "../includes/ft_printf.h"

void 	ft_display_f(char *nb, t_flags *tFlags)
{
	if (tFlags->plus == 1 || tFlags->space == 1)
		tFlags->width--;
	if (tFlags->zero == 0)
		ft_print_sign(tFlags);
	if (tFlags->minus == 0)
		ft_print_width(tFlags);
	if (tFlags->zero == 1)
		ft_print_sign(tFlags);
	if (tFlags->width > 0)
		tFlags->total -= tFlags->width;
	ft_write(nb, tFlags->total);
	if (tFlags->minus == 1 && tFlags->width > 0)
		ft_print_width(tFlags);
}

void 	ft_display_d(intmax_t nb, int size, t_flags *tFlags)
{
	if (check_zero((uintmax_t)nb, &size, tFlags) == -1)
		tFlags->count = 1;
	if (nb > 0 && (tFlags->plus == 1 || tFlags->space == 1))
		tFlags->width--;
	ft_precision(tFlags, size);
	if (tFlags->zero == 0)
		ft_print_sign(tFlags);
	if (tFlags->minus == 0 && tFlags->width > 0)
		ft_print_width(tFlags);
	if (tFlags->zero == 1)
		ft_print_sign(tFlags);
	while (--tFlags->precision >= 0)
		ft_write("0", 1);
	if (size > 0 && tFlags->count != 1)
		ft_putnbr_base((uintmax_t) (nb < 0 ? -nb : nb), "0123456789", 10);
	if (tFlags->minus == 1 && tFlags->width > 0)
		ft_print_width(tFlags);
	total_dit((intmax_t)nb, size, tFlags);
}

void 	ft_display_o(intmax_t nb, int size, t_flags *tFlags)
{
	if (check_zero((uintmax_t)nb, &size, tFlags) == -1)
		tFlags->count = 1;
	if (nb > 0 && (tFlags->plus == 1 || tFlags->space == 1))
		tFlags->width--;
	ft_precision(tFlags, size);
	if (tFlags->zero == 0)
		ft_print_sign(tFlags);
	if (tFlags->minus == 0 && tFlags->width > 0)
		ft_print_width(tFlags);
	if (tFlags->zero == 1)
		ft_print_sign(tFlags);
	if (tFlags->hash && (nb > 0 || tFlags->width < 0))
		ft_write("0", 1);
	while (--tFlags->precision >= 0)
		ft_write("0", 1);
	if (size > 0 && tFlags->count != 1)
		ft_putnbr_base((uintmax_t) (nb < 0 ? -nb : nb),  "01234567", 8);
	if (tFlags->minus == 1 && tFlags->width > 0)
		ft_print_width(tFlags);
	total_dit((intmax_t)nb, size, tFlags);
}

void 	ft_display_u(uintmax_t nb, int size, t_flags *tFlags)
{
	if (check_zero((uintmax_t)nb, &size, tFlags) == -1)
		tFlags->count = 1;
	ft_precision(tFlags, size);
	if (tFlags->minus == 0 && tFlags->width > 0)
		ft_print_width(tFlags);
	while (--tFlags->precision >= 0)
		ft_write("0", 1);
	if (size > 0 && tFlags->count != 1)
		ft_putnbr_base((uintmax_t)nb, "0123456789", 10);
	if (tFlags->minus == 1 && tFlags->width > 0)
		ft_print_width(tFlags);
	total_dit((intmax_t)nb, size, tFlags);
}

void 	ft_display_x(uintmax_t nb, int size, t_flags *tFlags)
{
	if (check_zero((uintmax_t)nb, &size, tFlags) == -1)
		tFlags->count = 1;
	ft_precision(tFlags, size);
	if (tFlags->minus == 0 && tFlags->width > 0)
		ft_print_width(tFlags);
	while (--tFlags->precision >= 0)
		ft_write("0", 1);
	if (size > 0 && tFlags->count != 1)
		ft_putnbr_base((uintmax_t)nb, "0123456789", "0x");
	if (tFlags->minus == 1 && tFlags->width > 0)
		ft_print_width(tFlags);
	total_dit((intmax_t)nb, size, tFlags);
}