/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:45:18 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 08:45:20 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i ++;
	}
	return (s);
}

/*int main()
{
	int i = 0;
	char str[20] = {0};
	memset(str,4,3);
	while (i < 20)
	{
		printf("%d ",str[i]);
		i ++;
	}
	printf("\n");
	// while (str[i])
	// {
	// 	printf("%d\n", str[i]);
	// 	i ++;
	// }
	return 0;
}*/