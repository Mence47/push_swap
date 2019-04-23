/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:44:11 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:57 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char*)hay);
	i = 0;
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		if (hay[i] == needle[j])
		{
			while (needle[j] != '\0' && (i + j) < len)
			{
				if (hay[i + j] != needle[j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return ((char*)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
