/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:30:53 by ititkov           #+#    #+#             */
/*   Updated: 2019/03/20 11:08:11 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		new_line(char **line, char **str, int fd)
{
	int		len;
	char	*temp;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		temp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = temp;
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	static char		*str[MAX_FD];
	int				read_char;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || \
			read(fd, buf, 0) < 0 || fd > MAX_FD)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	while ((read_char = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_char] = '\0';
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (str[fd][0] == '\0')
		return (0);
	return (new_line(line, str, fd));
}
