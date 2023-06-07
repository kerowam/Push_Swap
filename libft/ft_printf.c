/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:50:36 by gfredes-          #+#    #+#             */
/*   Updated: 2023/02/01 23:08:46 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_print_c(char c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
}

static void ft_print_s(char *str, size_t *len)
{
	if (!str)
		str = "(null)";
	while (*str != '\0')
	{
		ft_print_c(*str, len);
		str++;
	}
}

static void ft_print_px(unsigned long int nb, size_t *len)
{
	char *hex_base;
	char hex[42];
	int i;

	hex_base = "0123456789abcdef";
	i = 0;
	if (nb == 0)
	{
		ft_print_c('0', len);
		return;
	}
	while (nb != 0)
	{
		hex[i] = hex_base[nb % 16];
		nb /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_print_c(hex[i], len);
	}
}

static void ft_print_p(unsigned long int nb, size_t *len)
{
	ft_print_c('0', len);
	ft_print_c('x', len);
	ft_print_px(nb, len);
}

static void ft_divorprint(int nb, size_t *len)
{
	if (nb >= 10)
	{
		nb = nb / 10;
		ft_divorprint(nb, len);
		ft_print_c(nb % 10 + '0', len);
	}
}

static void ft_print_d_i(int nb, size_t *len)
{
	if (nb < 0)
	{
		ft_print_c('-', len);
		if (nb == -2147483648)
		{
			ft_print_c('2', len);
			nb = -147483648;
		}
		nb = nb * -1;
	}
	ft_divorprint(nb, len);
	ft_print_c(nb % 10 + '0', len);
}

static void ft_print_u(unsigned int nb, size_t *len)
{
	long n;

	n = nb;
	if (n < 0)
	{
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_u(n / 10, len);
		ft_print_c(n % 10 + '0', len);
	}
	else
		ft_print_c(n % 10 + '0', len);
}

static void ft_print_x(unsigned int nb, size_t *len)
{
	char *hex_base;
	char hex[42];
	int i;

	hex_base = "0123456789abcdef";
	i = 0;
	if (nb == 0)
	{
		ft_print_c('0', len);
		return;
	}
	while (nb != 0)
	{
		hex[i] = hex_base[nb % 16];
		nb /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_print_c(hex[i], len);
	}
}

static void ft_print_upx(unsigned int nb, size_t *len)
{
	char *hex_base;
	char hex[42];
	int i;

	hex_base = "0123456789ABCDEF";
	i = 0;
	if (nb == 0)
	{
		ft_print_c('0', len);
		return;
	}
	while (nb != 0)
	{
		hex[i] = hex_base[nb % 16];
		nb /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_print_c(hex[i], len);
	}
}

static void	ft_printer(char str, va_list arg, size_t *len)
{
	if (str == 'c')
		ft_print_c(va_arg(arg, int), len);
	else if (str == 's')
		ft_print_s(va_arg(arg, char *), len);
	else if (str == 'p')
		ft_print_p(va_arg(arg, unsigned long int), len);
	else if (str == 'd' || str == 'i')
		ft_print_d_i(va_arg(arg, int), len);
	else if (str == 'u')
		ft_print_u(va_arg(arg, unsigned int), len);
	else if (str == 'x')
		ft_print_x(va_arg(arg, unsigned int), len);
	else if (str == 'X')
		ft_print_upx(va_arg(arg, unsigned long int), len);
	else if (str == '%')
		ft_print_c('%', len);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	size_t	len;

	len = 0;
	va_start(arg, str);
	if (!str)
	{
		str = "(null)";
		va_end(arg);
	}
	if ((write (1, "", 0) == -1))
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_printer(*str, arg, &len);
		}
		else
			ft_print_c(*str, &len);
		str++;
	}
	va_end(arg);
	return (len);
}
