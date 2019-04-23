/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:53:23 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:56 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_replace(char **ptr, char *str, char *copy)
{
	char	*tmp;
	char	*tmp2;

	*str = '\0';
	tmp = ft_strdup(*ptr);
	tmp2 = ft_strdup(str + ft_strlen(copy));
	str = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	free(*ptr);
	*ptr = str;
}

static void	ft_optimaze_r(char **ptr)
{
	char	*str;

	str = ft_strstr(*ptr, "\nrra\nra");
	if (str != NULL)
	{
		ft_replace(ptr, str, "\nra\nrra");
		ft_optimaze_r(ptr);
	}
	str = ft_strstr(*ptr, "\nrb\nrrb");
	if (str != NULL)
	{
		ft_replace(ptr, str, "\nra\nrra");
		ft_optimaze_r(ptr);
	}
	str = ft_strstr(*ptr, "\nrrb\nrb");
	if (str != NULL)
	{
		ft_replace(ptr, str, "\nra\nrra");
		ft_optimaze_r(ptr);
	}
}

void		ft_optimaze(char **ptr)
{
	char	*str;

	str = ft_strstr(*ptr, "\npb\npa");
	if (str != NULL)
	{
		ft_replace(ptr, str, "\npb\npa");
		ft_optimaze(ptr);
	}
	str = ft_strstr(*ptr, "\npa\npb");
	if (str != NULL)
	{
		ft_replace(ptr, str, "\npb\npa");
		ft_optimaze(ptr);
	}
	str = ft_strstr(*ptr, "\nra\nrra");
	if (str != NULL)
	{
		ft_replace(ptr, str, "\nra\nrra");
		ft_optimaze(ptr);
	}
	ft_optimaze_r(ptr);
}
