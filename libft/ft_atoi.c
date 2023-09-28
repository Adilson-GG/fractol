/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:45:07 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/03 11:45:10 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	conv;

	i = 0;
	conv = 0;
	s = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i ++;
	if (nptr[i] != '-' && !(nptr[i] >= 48 && nptr[i] <= 57) && nptr[i] != '+')
		return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i ++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		conv = (conv * 10) + (nptr[i] - '0');
		i ++;
	}
	return (s * conv);
}

/*int main()
{
	const char nb[]="+42";
	printf("%d\n", atoi(nb));
	printf("%d\n", ft_atoi(nb));
	return 0;
}*/