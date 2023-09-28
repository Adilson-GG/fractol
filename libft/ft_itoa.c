/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:11:48 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/04 09:11:51 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_occurence(int n)
{
	int	occ;

	occ = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		occ ++;
	}
	return (occ);
}

static long	ft_puissance(int occ)
{
	int		i;
	long	x;

	i = 1;
	x = 1;
	while (i < occ)
	{
		x = x * 10;
		i ++;
	}
	return (x);
}

static void	ft_negatif(int *i, int *signe, long *nb, int n)
{
	if (n < 0)
	{
		*nb = *nb * (-1);
		*signe = 1;
		*i = 1;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		signe;
	int		occ;
	long	nb;
	char	*result;

	signe = 0;
	i = 0;
	nb = n;
	occ = ft_occurence(n);
	ft_negatif(&i, &signe, &nb, n);
	result = malloc((occ + signe + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (signe)
		result[0] = '-';
	while (occ != 0)
	{
		result[i] = (nb / ft_puissance(occ)) + '0';
		nb = nb % ft_puissance(occ);
		i ++;
		occ --;
	}
	result[i] = '\0';
	return (result);
}

/*int main()
{
	printf("%s\n", ft_itoa(-2147483648));
	return 0;
}*/