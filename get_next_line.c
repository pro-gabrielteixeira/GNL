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
    if (!line)
    {
        line = (char*)malloc(BUFFER_SIZE * sizeof(char));
        line = buf;
        return (line);
    }
    line = ft_strjoin(line, buf);
    return (line);
}

char *get_next_line(int fd)
{
    static char *buf;
    char    *line;

    buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
    while (TRUE)
    {
    read(fd, buf, BUFFER_SIZE);
    line = malloc_line(buf, line);
    if (verify_next_line(buf))
        break;
    }
    return (line); //beware from EOF exception, infinite loop
}