/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:15:51 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 13:15:54 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i ++;
	}
	i = 0;
	while (s2[i])
	{
		result[i + ft_strlen(s1)] = s2[i];
		i ++;
	}
	result[i + ft_strlen(s1)] = '\0';
	return (result);
}

/*int main()
{
	printf("%s\n", ft_strjoin("coucou", " comment"));
	return 0;
}*/