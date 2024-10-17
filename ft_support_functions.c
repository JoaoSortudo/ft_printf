/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-16 12:56:25 by jpires-n          #+#    #+#             */
/*   Updated: 2024-10-16 12:56:25 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//aqui faremos funções para lidar com print de:
//caracteres %c, strings %s, void pointer %p, decimais %d, ints %i
//unsigned decimals %u, e outros casos como %x, %X e %%

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
		count++;
	write (1, str, count);
	return (count);
}

int	ft_print_void(void *ptr)
{
	unsigned long long	adress;
	int					count;

	adress = (unsigned long long)ptr;
	if (adress == 0)
		return (ft_print_string("(nil)"));
	count = ft_print_string("0x");
	if (!ptr)
		return (count + ft_print_char('0'));
	count += ft_print_hex(adress, 0);
	return (count);
}