/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:17:54 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 11:17:56 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big)
		return (NULL);
	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j ++;
			if (little[j] == '\0')
				return (&((char *)big)[i]);
		}
		i ++;
	}
	return (NULL);
}

// #include<bsd/string.h>
// int main()
// {
// 	printf("%s\n", ft_strnstr("coucou comment", "com", 9));
// 	return 0;
// }