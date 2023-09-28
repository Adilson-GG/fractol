/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:34:59 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/20 12:35:00 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i ++;
	return (i);
}

int	ft_findend(const char *s, int len, int fin)
{
	int			i;
	int			l_reste;
	static int	entree = 0;

	i = 0;
	l_reste = ft_strlen(s);
	if (!s)
		return (0);
	if (entree)
		i = len + 1;
	entree ++;
	while (i < l_reste)
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	if (fin)
		return (i);
	return (0);
}

char	*ft_strdup2gnl(char const *s, int len)
{
	static int		k = 0;
	char			*dup;
	int				j;

	j = 0;
	if (!s || k > len)
		return (NULL);
	dup = malloc(sizeof(char) * (len - k + 2));
	if (dup == NULL)
		return (NULL);
	while (s[k] && k <= len)
	{
		dup[j] = s[k];
		k ++;
		j ++;
	}
	dup[j] = '\0';
	if (j == 0)
	{
		free (dup);
		return (NULL);
	}
	return (dup);
}

char	*ft_strdup(char const *s, int lu)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (lu + 1));
	if (dup == NULL)
		return (NULL);
	if (s)
	{
		while (i < lu)
		{
			dup[i] = s[i];
			i ++;
		}
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoingnl(char const *s1, char const *s2, int lu)
{
	int		i;
	char	*result;
	int		l_s1;

	if (!s1)
		return (ft_strdup(s2, lu));
	i = 0;
	l_s1 = ft_strlen(s1);
	result = malloc((l_s1 + lu + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i ++;
	}
	i = 0;
	while (i < lu)
	{
		result[i + l_s1] = s2[i];
		i ++;
	}
	result[i + l_s1] = '\0';
	free((char *)s1);
	return (result);
}
