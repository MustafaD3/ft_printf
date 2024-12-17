/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:15:52 by mdalkili          #+#    #+#             */
/*   Updated: 2024/12/04 02:18:16 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	write_char(int chr)
{
	return (write(1, &chr, 1));
}

int	write_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
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
