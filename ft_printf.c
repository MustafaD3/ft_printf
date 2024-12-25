/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:32:19 by mdalkili          #+#    #+#             */
/*   Updated: 2024/12/25 10:51:32 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	write_hex(unsigned int n, char format, int count)
{
	char	*hex;
	char	chr;

	hex = "0123456789ABCDEF";
	if (n >= 16)
		count += write_hex(n / 16, format, count);
	if (n % 16 > 9)
	{
		if (format == 'x')
			chr = hex[n % 16] + 32;
		else
			chr = hex[n % 16];
		count += write(1, &chr, 1);
	}
	else
		count += write(1, &hex[n % 16], 1);
	return (count);
}

int	write_ptr(unsigned long long ptr, int count)
{
	if (!ptr)
		count += write(1, "(nil)", 5);
	else
	{
		if (ptr >= 16)
			count += write_ptr(ptr / 16, count);
		else
			count += write(1, "0x", 2);
		count += write(1, &"0123456789abcdef"[ptr % 16], 1);
	}
	return (count);
}

int	printf_formats(char format, va_list *list)
{
	int	written_character;

	written_character = 0;
	if (format == 's')
		written_character += write_string(va_arg(*list, char *));
	else if (format == 'd' || format == 'i')
		written_character += write_number(va_arg(*list, int));
	else if (format == 'u')
		written_character += write_number(va_arg(*list, unsigned int));
	else if (format == 'c')
		written_character += write_char(va_arg(*list, int));
	else if (format == 'x' || format == 'X')
		written_character += write_hex(va_arg(*list, unsigned int), format, 0);
	else if (format == 'p')
		written_character += write_ptr(va_arg(*list, unsigned long long), 0);
	return (written_character);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	list;
	int		i;

	i = 0;
	va_start(list, str);
	length = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("sdiucxXp", str[i]))
				length += printf_formats(str[i], &list);
			else
				length += write(1, &str[i], 1);
		}
		else
			length += write(1, &str[i], 1);
		i++;
	}
	return (length);
}
