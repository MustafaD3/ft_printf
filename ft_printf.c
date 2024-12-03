/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:32:19 by mdalkili          #+#    #+#             */
/*   Updated: 2024/11/18 03:39:16 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	write_char(int chr)
{
	write(1,&chr,1);
	return (1);
}

int	write_string(char *str)
{
	int	i;

	i = 0;
	if(!str)
		i += write(1, "(null)", 6);
	else
	{
		while (str && str[i])
			write_char(str[i++]);
	}
	return (i);
}


int	write_number(int n)
{
	return (write_string(ft_itoa(n)));
}

int	write_unumber(unsigned int n)
{
	int				count;
	unsigned int	ncpy;
	char 			*nmbtostr;
	
	count = 0;
	ncpy = n;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	nmbtostr = (char *)malloc(sizeof(char) * count + 1);
	nmbtostr[count] = '\0';
	while (ncpy > 9)
	{
		count--;
		nmbtostr[count] = ncpy % 10 + '0';
		ncpy /= 10;
		
	}
	count = write_char(ncpy % 10 + '0') + write_string(nmbtostr);
	free(nmbtostr);
	return count;
}

int	write_hex(unsigned int n, char format, int count)
{
	char *hex = "0123456789ABCDEF";
	char chr;
	if(n >= 16)
	{
		count += write_hex(n / 16,format,count);
	}
	if (n % 16 > 9 && n % 16 < 17)
	{
		if (format == 'x')
		{
			chr = hex[n % 16] + 32;
			count += write(1, &chr, 1);
		}
		else
			count += write(1, &hex[n % 16], 1);
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
		if (ptr > 16)
			count += write_ptr(ptr / 16, count);
		else
			count += write(1, "0x", 2);
		count += write(1, &"0123456789abcdef"[ptr % 16], 1);//Warrrninggg
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
		written_character += write_unumber(va_arg(*list, unsigned int));
	else if (format == 'c')
		written_character += write_char(va_arg(*list, int));
	else if (format == 'x' || format == 'X')
		written_character += write_hex(va_arg(*list, unsigned int), format, 0);
	else if (format == 'p')
		written_character += write_ptr(va_arg(*list, unsigned long long), 0);
	return (written_character);
}

int	ft_printf(char *format, ...)
{
	int		length;
	va_list	list;
	char	*str;

	va_start(list, format);
	str = ft_strdup("sdiucxXp");
	length = 0;
	while (format && *format)
	{
		if (*format == '%')
		{
			++format;
			if (!ft_strchr(str, *format))
				length += printf_formats(*format, &list);
			else
				length += write(1, format, 1);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (length);
}
