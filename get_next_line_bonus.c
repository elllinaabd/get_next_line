/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:13:06 by radan             #+#    #+#             */
/*   Updated: 2022/06/26 17:59:16 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *saved_str)
{
	int		i;
	char	*ret_str;

	i = 0;
	if (!saved_str[i])
		return (NULL);
	while (saved_str[i] && saved_str[i] != '\n')
		i++;
	ret_str = (char *)malloc(sizeof(char) * (i + 2));
	if (!ret_str)
		return (NULL);
	i = 0;
	while (saved_str[i] && saved_str[i] != '\n')
	{
		ret_str[i] = saved_str[i];
		i++;
	}
	if (saved_str[i] == '\n')
	{
		ret_str[i] = saved_str[i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}

char	*ft_save(char *saved_str)
{
	int		i;
	int		c;
	char	*ret_str;

	i = 0;
	while (saved_str[i] && saved_str[i] != '\n')
		i++;
	if (!saved_str[i])
	{
		free(saved_str);
		return (NULL);
	}
	ret_str = (char *)malloc(sizeof(char) * (ft_strlen(saved_str) - i + 1));
	if (!ret_str)
		return (NULL);
	i++;
	c = 0;
	while (saved_str[i])
		ret_str[c++] = saved_str[i++];
	ret_str[c] = '\0';
	free(saved_str);
	return (ret_str);
}

char	*ft_read_and_save(int fd, char *saved_str)
{
	char	*buf;
	int		rd;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd = 1;
	while (!ft_strchr(saved_str, '\n') && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		saved_str = ft_strjoin(saved_str, buf);
	}
	free(buf);
	return (saved_str);
}

char	*get_next_line(int fd)
{
	char		*printbl_str;
	static char	*saved_str[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	saved_str[fd] = ft_read_and_save(fd, saved_str[fd]);
	if (!saved_str[fd])
		return (NULL);
	printbl_str = ft_get_line(saved_str[fd]);
	saved_str[fd] = ft_save(saved_str[fd]);
	return (printbl_str);
}
