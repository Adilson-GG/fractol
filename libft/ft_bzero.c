/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:43:39 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 08:43:58 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) s)[i] = 0;
		i ++;
	}
}

/*#include<stdio.h>
#include<strings.h>
int main()
{
	int i = 0;
	char str[6]="coucou";
	ft_bzero(str,2);
	while (str[i])
	{
		printf("%d\n", str[i]);
		i ++;
	}
	return 0;
}*/
