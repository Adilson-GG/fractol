/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:51:50 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/04 12:51:52 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i ++;
	}
}

/*void	f(unsigned int i, char *s)
{
	s[i] = 'o';
}

int main()
{
	char s[6]="coucou";
	ft_striteri(s, &f);
	printf("%s\n", s);
	return 0;
}*/