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

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strcat(char *s1, char *temp);
void	ft_strcpy(char *str);
char	*add_char_to_str(char *line, char *buf);

#endif
