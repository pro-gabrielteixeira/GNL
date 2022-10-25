/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:55:24 by gateixei          #+#    #+#             */
/*   Updated: 2022/07/28 01:55:24 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE
# define GET_NEXT_LINE
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 3
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd);
int	    ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif

// int ft_endline(char *str);