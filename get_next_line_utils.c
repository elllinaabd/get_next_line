/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radan <radan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:37:25 by radan             #+#    #+#             */
/*   Updated: 2021/12/22 00:51:37 by radan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sum_s;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[i] = '\0';
	}
	sum_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!sum_s || !s2)
		return (NULL);
	while (s1[c])
		sum_s[i++] = s1[c++];
	c = 0;
	while (s2[c])
		sum_s[i++] = s2[c++];
	sum_s[i] = '\0';
	free(s1);
	return (sum_s);
}
