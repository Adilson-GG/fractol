/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:35:12 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 13:35:14 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	check(char char_s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == char_s1)
			return (1);
		i ++;
	}
	return (0);
}

static int	trim_debut(char const *s1, char const *set)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (check(s1[i], set) == 1)
	{
		i ++;
		comp ++;
	}
	return (comp);
}

static int	trim_fin(char const *s1, char const *set)
{
	int	i;
	int	comp;

	i = trim_debut(s1, set);
	comp = 0;
	while (s1[i])
	{
		if (check(s1[i], set) == 0)
			comp = 0;
		else
			comp ++;
		i ++;
	}
	return (comp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*trim;

	if (!s1)
		return (NULL);
	trim = malloc((ft_strlen(s1) - trim_debut(s1, set)
				- trim_fin(s1, set) + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1) - trim_debut(s1, set) - trim_fin(s1, set))
	{
		trim[i] = s1[trim_debut(s1, set) + i];
		i ++;
	}
	trim[i] = '\0';
	return (trim);
}

/*int main()
{
	char *trim;
	trim = ft_strtrim("tripouille   xxx", " x");
	printf("%s\n", trim);
	free(trim);
	return 0;
}*/