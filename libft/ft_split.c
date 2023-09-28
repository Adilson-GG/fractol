/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:42:46 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 14:42:49 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	comp;

	comp = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i ++;
		if (s[i] && s[i] != c)
			comp ++;
		while (s[i] && s[i] != c)
			i ++;
	}
	return (comp);
}

static int	ft_long(char const *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] && s[i] != c)
	{	
		l ++;
		i ++;
	}
	return (l);
}

static char	*ft_strdup2(const char *s, char c, int i)
{
	int		j;
	char	*dup;

	j = 0;
	dup = malloc ((sizeof(char) * (ft_long(s, c, i)) + 1));
	if (dup == NULL)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		dup[j] = s[i];
		i ++;
		j ++;
	}
	dup[j] = '\0';
	return (dup);
}

static char	**ft_free(char **tab, int comp)
{
	int	i;
	int	lib;

	i = 0;
	lib = 0;
	while (i < comp - 1 && lib == 0)
	{
		if (tab[i] == NULL)
			lib = 1;
		i ++;
	}
	if (lib)
	{
		while (comp >= 0)
		{
			free(tab[comp]);
			comp --;
		}
		free(tab);
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		comp;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	comp = 0;
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (comp < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i ++;
		tab[comp] = ft_strdup2(s, c, i);
		i = i + ft_long(s, c, i);
		comp ++;
	}
	tab[comp] = NULL;
	return (ft_free(tab, comp));
}

/*int main()
{
	int i = 0;
	const char str[18]="cnd ckd cld f   f ";
	char c = ' ';
	char **tab;
	tab = ft_split(str,c);
	while(tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i ++;
	}
	free(tab[i]);
	free(tab);
	return 0;
}*/