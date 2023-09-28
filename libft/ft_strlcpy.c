/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:46:46 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 08:46:48 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*#include<stdio.h>
#include<bsd/string.h>
int main()
{
	int a;
	char src[6]="coou";
	char dest[6]="sdf";
	a=ft_strlcpy(dest,src,6);
	printf("%s\n", dest);
	printf("%d\n", a);
	return 0;
}*/