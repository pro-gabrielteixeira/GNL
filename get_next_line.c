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

char *ft_strcat(char *s1, char *temp)
{
    char    *cat;
    int     i;
    int     c;

    c = -1;
    cat = (char*)malloc((ft_strlen(s1) + 2) * sizeof(char));
    if (!cat)
        return (0);
    while (s1 && s1[++c] != '\0')
        cat[c] = s1[c];
    cat[c++] = temp[0];
    cat[c] = '\0';
    return (cat);
}

void ft_strcpy(char *str)
{
    char    *ptr;
    int     i;

    i = 0;
    ptr = &str[1];
    while (str[i] != '\0' && str)
    {
        str[i] = ptr[i];
        i++; 
    }
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char    *line;

    line = (char*)malloc(BUFFER_SIZE * sizeof(char));
    while (TRUE)
    {
        if (!buf || buf[0] == '\0')
            if ((!read(fd, buf, BUFFER_SIZE)))
                if (line[0] != '\0')
                    return (line);
                else
                    return (NULL);
        if (buf[0] != '\0' && buf[0] != '\n' && buf)
            line = ft_strcat(line, buf);
        if (buf[0] == '\n')
        {
            line = ft_strcat(line, buf);
            ft_strcpy(buf);
            return (line);
        }
        ft_strcpy(buf);
    }
}

// char *get_next_line(int fd)
// {
    // static char buf[BUFFER_SIZE + 1];
    // static char *temp;
    // char    *line;
// 
    // line = (char*)malloc(BUFFER_SIZE * sizeof(char));
    // while (TRUE)
    // {
        // if (!temp || temp[0] == '\0')
        // {
            // if (read(fd, buf, BUFFER_SIZE))
                // temp = &buf[0];
            // else if (line[0] != '\0')
                // return (line);
            // else
                // return (NULL);
        // }
        // while (temp[0] != '\0' && temp[0] != '\n' && temp)
        // {
            // line = ft_strcat(line, temp);
            // temp++;
        // }
        // if (temp[0] == '\n')
        // {
            // line = ft_strcat(line, temp);
            // temp++;
            // return (line);
        // }
    // }
// }


// char *get_next_line(int fd)
// {
//     static char *buf;
//     char    *line;
//     int     i;

//     i = 1;
//     line = (char*)malloc(BUFFER_SIZE * sizeof(char));
//     if (!buf)
//         buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
//     while (fd > 0 && BUFFER_SIZE > 0)
//     {
//         if (!buf || buf[0] == '\0')
//             i = read(fd, buf, BUFFER_SIZE);
//         if (buf[0] != '\0' && buf)
//             line = ft_strcat(line, buf);
//         if (buf++[0] == '\n')
//             return (line);
//         // if (i <= 0 && (ine[0] != '\0' && line))
//             // return (line);
//     }
//     line = 0;
//     return line;
// }