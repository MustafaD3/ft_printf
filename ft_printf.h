/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:31:22 by mdalkili          #+#    #+#             */
/*   Updated: 2024/12/17 03:16:27 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf(const char *, ...);
int		write_char(int chr);
int		write_string(char *str);
int		write_number(int n);
int		write_unumber(unsigned int n);
int		write_hex(unsigned int n,char format, int count);
int		write_ptr(unsigned long long ptr, int count);

#endif