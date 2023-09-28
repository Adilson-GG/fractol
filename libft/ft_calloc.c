/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:24:49 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/09 12:12:36 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	int		over;

	over = (int)(size * nmemb);
	if (size)
	{
		if (nmemb != ((size_t)over / size))
			return (NULL);
	}
	mem = malloc(nmemb * size * sizeof(char));
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

/*#include<stdio.h>
#include <stdint.h>
int main()
{
	int i = 0;
	ft_calloc(SIZE_MAX,SIZE_MAX);
	while(i<5120)
	{
		printf("%d ",((int*)ft_calloc(SIZE_MAX, SIZE_MAX))[i]);
		i ++;
	}
	printf("\n%ld\n", SIZE_MAX);
	return 0;
}*/
