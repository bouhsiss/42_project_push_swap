/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:46:17 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/03/26 11:46:21 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_calc_line(char *line, char buf)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof (char) * ft_strlen(line) + 2);
	while (line[i])
	{
		res[i] = line[i];
		i++;
	}
	res[i] = buf;
	i++;
	res[i] = 0;
	free(line);
	return (res);
}

char	*get_next_line(int fd)
{
	int		bytes_count;
	char	*line;
	char	buf;

	if (fd < 0)
		return (0);
	bytes_count = 1;
	line = malloc(1);
	line[0] = '\0';
	while (ft_find_newline(line) == -1 && bytes_count)
	{
		bytes_count = read(fd, &buf, 1);
		if (bytes_count <= 0)
		{
			if (!line[0])
			{
				free(line);
				return (0);
			}
			return (line);
		}
		line = ft_calc_line(line, buf);
	}
	return (line);
}
