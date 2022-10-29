/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:09:53 by gateixei          #+#    #+#             */
/*   Updated: 2022/10/29 13:45:00 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    char *str;
    int fd;
    int i;
    
    i = 0;
    fd = open("texto.txt", O_RDONLY);
    // while (i < 1)
    // {
    // str = get_next_line(fd);
    // printf("Linha:%sFIM\n", str);
    // i++;
    // }
    while (str = get_next_line(fd))
        printf("Linha:%sFIM\n", str);
    free(str);
    return (0);
}