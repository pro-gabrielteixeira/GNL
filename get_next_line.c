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

int ft_endline(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n' && (i) < BUFFER_SIZE)
        str[i++];
    return (i);
}

char *get_next_line(int fd)
{
    char *buf;
    static char *rtn;
    int i;
    int c;
    int r;

    c = 0;
    i = BUFFER_SIZE;
    while (i >= BUFFER_SIZE)
    {         
        buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
        read(fd, buf, BUFFER_SIZE);
        i = ft_endline(buf);
        c++;
    }
    printf("%i", c);
    r = (BUFFER_SIZE * c) - (BUFFER_SIZE - i);
    rtn = (char*)malloc(r * sizeof(char));
    read(fd, rtn, r);
    //free = buf;
    return (rtn);
}


int main(void)
{
    char *str;
    int fd;
    
    fd = open("texto.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("%s", str);
    return 0;
}
