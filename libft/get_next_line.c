/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:35:46 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/16 21:24:54 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					check(int fd, char **txt, char **line)
{
	int				i;
	char			*tmp;

	i = 0;
	while (txt[fd][i] != '\n' && txt[fd][i] != '\0')
		i++;
	if (txt[fd][i] == '\n')
	{
		*line = ft_strsub(txt[fd], 0, i);
		tmp = ft_strdup(&txt[fd][i + 1]);
		ft_strdel(&txt[fd]);
		txt[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(txt[fd]);
		ft_strdel(&txt[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*txt[MAX_FD];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				printed;

	if (fd < 0 || fd > MAX_FD || !line || BUFF_SIZE <= 0 || \
			(read(fd, buff, 0) < 0))
		return (-1);
	(!txt[fd] ? txt[fd] = ft_strnew(1) : 0);
	while ((printed = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[printed] = '\0';
		tmp = ft_strjoin(txt[fd], buff);
		ft_strdel(&txt[fd]);
		txt[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (txt[fd][0] == '\0')
		return (0);
	return (check(fd, txt, line));
}
