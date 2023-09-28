/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:39:17 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 08:43:03 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	if ((char *)src <= (char *)dest)
	{
		while (n - i > 0)
		{
			((char *)dest)[n - 1 - i] = ((char *)src)[n - 1 - i];
			i ++;
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}

/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char src[15]="abcdefghijklmno";
	char dest[15];
	printf("src %s\n", src);
	//char dest[15];
	ft_memmove(dest,src+6,4);
	printf("%s\n", dest);
	//printf("dest %s\n", dest);
	return 0;
}*/
