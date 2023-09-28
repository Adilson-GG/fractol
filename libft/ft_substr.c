/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:01:00 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 13:01:02 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	if (start > (unsigned int)ft_strlen(s) - 1)
		dest = malloc(sizeof(char));
	else if (len >= ft_strlen(s) - start)
		dest = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) - 1 >= start)
	{
		while (i < len && s[start + i])
		{
			dest[i] = s[start + i];
			i ++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

/*int main()
{
	printf("[%s]\n", ft_substr("tripouille", 100, 1));
	return 0;
}*/