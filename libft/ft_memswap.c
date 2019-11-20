/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:19:38 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/16 12:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *a, void *b, size_t n)
{
	unsigned char	x;

	while (n--)
		if (a == NULL || b == NULL)
			return ;
		else
		{
			x = *((unsigned char *)a);
			*((unsigned char *)a) = *((unsigned char *)b);
			*((unsigned char *)b) = x;
			a++;
			b++;
		}
}
