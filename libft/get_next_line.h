/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:34:50 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/20 12:34:51 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include"stdlib.h"
# include"unistd.h"
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_findend(const char *s, int len, int fin);
size_t	ft_strlen(const char *s);
char	*ft_strdup2gnl(char const *s, int len);
char	*ft_strjoingnl(char const *s1, char const *s2, int lu);
int		ft_newline(const char *s);

#endif
