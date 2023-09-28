/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:34:43 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/20 12:34:44 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_newline(const char *s)
{
	static int	i = 0;
	int			rec;

	rec = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			if (i == 0 || rec > 0)
			{
				if (i == 0)
					i ++;
				return (1);
			}
		}
		i ++;
		rec ++;
	}
	return (0);
}

char	*ft_read(int fd, char *reste, int *fin)
{
	char			*buff;
	static int		lu;
	int				nl;

	nl = ft_newline(reste);
	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return (NULL);
	if (!nl)
		lu = read(fd, buff, BUFFER_SIZE);
	while (!nl)
	{
		if (lu > 0)
			reste = ft_strjoingnl(reste, buff, lu);
		else
			break ;
		nl = ft_newline(reste);
		if (!nl)
			lu = read(fd, buff, BUFFER_SIZE);
	}
	if (lu < BUFFER_SIZE && nl == 0)
		*fin = 1;
	free (buff);
	return (reste);
}

char	*ft_get(char *reste, int fin)
{
	static int	len = 0;
	int			i;
	char		*res;

	i = ft_findend(reste, len, fin);
	len = i;
	res = ft_strdup2gnl(reste, i);
	if (res == NULL && fin)
		return (NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*ligne;
	static char	*reste = NULL;
	int			fin;

	fin = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	reste = ft_read(fd, reste, &fin);
	if (!reste)
		return (NULL);
	ligne = ft_get(reste, fin);
	if (ligne == NULL)
		free(reste);
	return (ligne);
}

// #include"stdio.h"
// #include <fcntl.h>
// int main()
// {
// 	int fd;
// 	char *s;
// 	int i = 1;
// 	fd = open("1-brouette.txt", O_RDONLY);
// 	while (i < 82)
// 	{
// 		s = get_next_line(fd);
// 		printf("%d :%s", i, s);
// 		free(s);
// 		i ++;
// 	}
// 	close(fd);
// 	return 0;
// }
