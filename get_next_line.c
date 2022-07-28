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

char *fix_buffer(char *buf, int i)
{

}

int ft_endline(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n' && (i + 1) <= BUFFER_SIZE)
        str[i++];
    return (i);
}

char *get_next_line(int fd, static char *str)
{
    char *buf;
    int i;

    buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
    read(fd, buf, BUFFER_SIZE);
    i = ft_endline(buf);
    if (i < (int) BUFFER_SIZE)
    {
        //buf = ;

       // printf("%s", buf);
        return (buf);
    }
    else {
	str = 
        get_next_line(fd);
    }
}

int main(void)
{
    static char *str;
    int fd;
    int i;
    
    fd = open("texto.txt", O_RDONLY);
    str = get_next_line(fd);
    //str = get_next_line(fd);
    //str = get_next_line(fd);
    printf("%s", str);
    return 0;
}
