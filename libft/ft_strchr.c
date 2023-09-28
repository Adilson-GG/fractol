/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:05:17 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 10:05:21 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i ++;
	}
	if (c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}

/*#include<stdio.h>
int main()
{
	printf("%s\n", ft_strchr("adilson", 'i'));
	return 0;
}*/