/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenk <bdenk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:03:56 by bdenk             #+#    #+#             */
/*   Updated: 2024/12/20 18:11:57 by bdenk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*byte_ptr;
	size_t				i;

	byte_ptr = (const unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (byte_ptr[i] == (unsigned char)c)
		{
			return ((void *)(byte_ptr + i));
		}
		i++;
	}
	return (0);
}
