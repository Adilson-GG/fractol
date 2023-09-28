/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:46 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 10:46:52 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i ++;
	}
	return (NULL);
}

// int main()
// {
// 	char mem[10]="adicsubctf";
// 	printf("%s\n", (char *)ft_memchr(mem, 'c',10));
// 	return 0;
// }