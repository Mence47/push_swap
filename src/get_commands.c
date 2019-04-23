/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:45:17 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 13:10:27 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_get_commands(char **line)
{
	char	*tmp;
	char	*tmp2;

	*line = ft_strnew(0);
	while (get_next_line(0, &tmp))
	{
		if (ft_check_command(tmp, line))
			return (-1);
		tmp2 = *line;
		*line = ft_strjoin(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		tmp = *line;
		*line = ft_strjoin(tmp, " ");
		ft_strdel(&tmp);
	}
	return (1);
}
