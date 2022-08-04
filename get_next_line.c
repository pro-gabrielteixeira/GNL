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
	char	*new_str;
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
	new_str[p] = '\0';
    //free(s2);
	return (new_str);
}


int next_line_char(char *buf)
{
    int i;

    i = 0;
    while (i <= (BUFFER_SIZE + 1) && buf[i] != '\0')
    {
        if (buf[i] == '\n')
            return (i);
        i++;
    }
    return (0);
}

char *get_buffer(char *buf, int i)
{
    int c;
    int n;
    char    *temp;

    n = 0;
    c = BUFFER_SIZE - i;
    temp = (char*)malloc(sizeof(char) * c);
    while (c < BUFFER_SIZE)
        temp[n++] = buf[c++];
    temp[n] = '\0';
    return (temp);
}

char *fix_buf(char *buf,int i)
{
    int c;

    c = BUFFER_SIZE - i;
    while (c < BUFFER_SIZE)
        buf[c++] = '\0';
    return (buf);
}

char *get_full_line(char *temp, char *line, char *buf, int i, int fd)
{
    buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
    read(fd, buf, BUFFER_SIZE);
    line = (char*)malloc(sizeof(char));
    line[0] = '\0';
    i = next_line_char(buf);
    if (!i) //beware from EOF exception, infinite loop
        line = get_full_line(temp, line, buf, i, fd);
    else if (buf[i] != '\n' || BUFFER_SIZE > (i + 1))
    {
        temp = get_buffer(buf, i);
        buf = fix_buf(buf, i);
    }
    line = ft_strjoin(buf, line);
    return (line);
}

char *get_next_line(int fd)
{
    static char *temp;
    char    *line;
    char    *buf;
    int i;

    buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
    read(fd, buf, BUFFER_SIZE);
    line = (char*)malloc(sizeof(char));
    line[0] = '\0';
    i = next_line_char(buf);
    if (line[0] == '\0' && temp)
    {
        line = get_full_line(temp, line, buf, i, fd);
        line = ft_strjoin(buf, line);
        line = ft_strjoin(temp, line);
        return (line);
    }
    if (!i) //beware from EOF exception, infinite loop
        line = get_next_line(fd);
    else if (buf[i] != '\n' || BUFFER_SIZE > (i + 1))
    {
        temp = get_buffer(buf, i);
        buf = fix_buf(buf, i);
    }
    line = ft_strjoin(buf, line);
    return (line);
}

int main(void)
{
    char *str;
    int fd;
    
    fd = open("texto.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("Linha - %sFIM/", str);
    str = get_next_line(fd);
    printf("Linha - %sFIM/", str);
    str = get_next_line(fd);
    printf("Linha - %sFIM/", str);
    str = get_next_line(fd);
    printf("Linha - %sFIM/", str);
    
    return 0;
}
