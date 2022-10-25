/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:09:53 by gateixei          #+#    #+#             */
/*   Updated: 2022/10/26 00:13:25 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    char *str;
    int fd;
    
    fd = open("texto.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("Linha - %s - FIM\n", str);
    str = get_next_line(fd);
    printf("Linha - %s - FIM\n", str);
    str = get_next_line(fd);
    printf("Linha - %s - FIM\n", str);
    return (0);
}