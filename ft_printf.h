/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:26:27 by mustafa           #+#    #+#             */
/*   Updated: 2024/10/22 20:40:18 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

void	write_char(char chr);
void	write_string(char *str);
void	write_number(int n);
void	write_unumber(unsigned int n);
void	write_hex(unsigned int n,char format);
void	write_ptr(unsigned long long ptr);
void	ft_printf(char *format,...);

#endif