/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-abovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:28:20 by md-abovi          #+#    #+#             */
/*   Updated: 2020/02/11 13:28:31 by md-abovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			reset(char **str)
{
	free(*str);
	*str = NULL;
}

int				eof(char **line)
{
	if (!(*line = malloc(1)))
		return (-1);
	return (0);
}

int				fill(char **str, char **line, int fd, int nb)
{
	int			i;
	char		*temp;

	i = 0;
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\0')
	{
		if (nb == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		reset(&str[fd]);
		return (0);
	}
	else if (str[fd][i] == '\n')
	{
		*line = ft_substr(str[fd], 0, i);
		temp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			reset(&str[fd]);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*str[65536];
	char		buf[BUFFER_SIZE + 1];
	int			nb;
	char		*temp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((nb = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[nb] = 0;
		if (!(str[fd]))
			str[fd] = malloc(1);
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (nb < 0)
		return (-1);
	else if (nb == 0 && (str[fd] == NULL || str[fd][0] == 0))
		return (eof(line));
	return (fill(str, line, fd, nb));
}
