/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:27:21 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/04 12:27:23 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*dest;

	if (!s || !f)
		return (NULL);
	i = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		dest[i] = (*f)(i, s[i]);
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

/*char	f(unsigned int i, char s)
{
	s = '-';
	return s;
}

int main()
{
	char const s[6]="coucou";
	char *d;
	d=ft_strmapi(s, &f);
	printf("%s\n", d);
	return 0;
}*/