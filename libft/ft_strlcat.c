/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:30:00 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 09:30:02 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	i;

	if (!src || !dst)
		return (0);
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	i = 0;
	if (size == 0 || size <= l_dst)
		return (l_src + size);
	while (src[i] && i < size - l_dst - 1)
	{
		dst[i + l_dst] = src[i];
		i ++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}

/*#include<stdio.h>
#include<bsd/string.h>
int main()
{
	int a;
	char src[6]="coou";
	char dest[7]="adilson";
	a=strlcat(dest,src,0);
	printf("%s\n", dest);
	printf("%d\n", a);
	return 0;
}*/