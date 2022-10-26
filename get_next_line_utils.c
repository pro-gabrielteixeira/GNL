/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:55:15 by gateixei          #+#    #+#             */
/*   Updated: 2022/07/28 01:55:15 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_next_line(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n')
		len++;
	return (len);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
    char    *new_str;
	int		i;
	int		p;

	i = 0;
	p = 0;
	if (!s1 || !s2)
		return (0);
	new_str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * (sizeof(char)));
	if (!new_str)
		return (0);
	while (s1[i] != '\0')
		new_str[p++] = s1[i++];
    i = 0;
	while (s2[i] != '\0')
		new_str[p++] = s2[i++];
	new_str[p] = '\0';
	return (new_str);
}
