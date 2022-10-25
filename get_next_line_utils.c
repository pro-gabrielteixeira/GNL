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
	int		n;
	int		c;
	int		p;

	i = 0;
	c = 0;
	p = 0;
	if (!s1 || !s2)
		return (0);
	n = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *) malloc((n + 1) * (sizeof(char)));
	if (!new_str)
		return (0);
	while (s1[c] != '\0')
		new_str[p++] = s1[c++];
	while (s2[i] != '\0')
		new_str[p++] = s2[i++];
	s1[p] = '\0';
    //free(s2);
	return (new_str);
}

// int ft_endline(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i] != '\n')
//         str[i++];
//     return (i);
// }
