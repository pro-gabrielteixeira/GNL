/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:55:34 by gateixei          #+#    #+#             */
/*   Updated: 2022/07/28 17:58:00 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *after_next_line(char *s1, char *s2)
{
    char    *new_str;
    int     n;
	int		i;
	int		p;

	i = 0;
	p = 0;
    n = (ft_strlen(s1) + (ft_strlen(s2) - ft_strlen_next_line(s2)));
	if (!s1 || !s2)
		return (0);
	new_str = (char *)malloc((n + 1) * (sizeof(char)));
	if (!new_str)
		return (0);
	while (s1[i] != '\0')
		new_str[p++] = s1[i++];
    i = ft_strlen_next_line(s2) + 1;
	while (s2[i] != '\0')
		new_str[p++] = s2[i++];
	new_str[p] = '\0';
	return (new_str);
}

char *before_next_line(char *s1, char *s2)
{
    char    *new_str;
    int     n;
	int		i;
	int		p;

	i = 0;
	p = 0;
    n = (ft_strlen(s1) + ft_strlen_next_line(s2) + 1);
	if (!s1 || !s2)
		return (0);
	new_str = (char *)malloc((n + 1) * (sizeof(char)));
	if (!new_str)
		return (0);
	while (s1[i] != '\0')
		new_str[p++] = s1[i++];
    i = 0;
	while (s2[i - 1] != '\n')
		new_str[p++] = s2[i++];
	new_str[p] = '\0';
	return (new_str);
}

int verify_next_line(char *buf)
{
    int i;

    i = 0;
    while (buf[i] != '\0')
    {
        if (buf[i] == '\n')
            return (TRUE);
        i++;
    }
    return (FALSE);
}

char *malloc_line(char *buf, char *line)
{
    if (!verify_next_line(buf))
        line = ft_strjoin(line, buf);
    else
        line = before_next_line(line, buf);
    return (line);
}

char *get_next_line(int fd)
{
    static char *buf;
    char    *line;
    
    line = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (!buf)
        buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
    else
        line = after_next_line(line, buf);
    while (TRUE)
    {
    read(fd, buf, BUFFER_SIZE);
    line = malloc_line(buf, line);
    if (verify_next_line(buf))
        break;
    }
    return (line); //beware from EOF exception, infinite loop
}