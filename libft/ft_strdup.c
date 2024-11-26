/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 03:49:18 by mdalkili          #+#    #+#             */
/*   Updated: 2024/11/18 03:51:08 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(char *str)
{
	int	i;
	char *newstr;
	
	i = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while(str && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	return (newstr);
}