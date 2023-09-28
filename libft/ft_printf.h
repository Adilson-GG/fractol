/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:11:15 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/11 08:11:17 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
char	*ft_conv_base(int nb, int base);
int		ft_longueur(int nb, int base);
void	ft_putunsigned_nbr_fd(unsigned int n, int fd);
int		ft_convunsigned(unsigned int n, int base);
char	*ft_unsigned_conv_base(unsigned int nb, int base);
char	*ft_unsigned_conv_baseup(unsigned int nb, int base);
int		ft_unsigned_longueur(unsigned int nb, int base);
char	*ft_rev_tab(char *dest, int len);
int		ft_putadd(void *s);
int		ft_param_len(const char *str);
int		ft_casnull(void);
void	ft_putstr_free_fd(char *s, int fd);

#endif