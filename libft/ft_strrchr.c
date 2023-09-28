/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:21:12 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 10:21:19 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			tmp = &((char *)s)[i];
		i ++;
	}
	if (c == '\0')
		return (&((char *)s)[i]);
	return (tmp);
}

/*#include<stdio.h>
#include<string.h>
int main()
{
	int c = 't' + 256;
	printf("%s\n", ft_strrchr("coucoucomup", c));
	return 0;
}*/
