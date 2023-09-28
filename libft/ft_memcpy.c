/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:44:59 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 08:45:01 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i ++;
	}
	return (dest);
}

/*int main()
{
	int i = 0;
	char src[6]="coucou";
	char dest[6];
	memcpy(dest,src,6);
	while (dest[i])
	{
		printf("src %d, ", src[i]);
		printf("dest %d\n", dest[i]);
		i ++;
	}
	return 0;
}*/
