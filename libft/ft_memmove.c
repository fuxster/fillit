/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:14:09 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/07 20:20:45 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s2;
	char		*s1;

	s2 = src;
	s1 = dest;
	if (s2 < s1)
	{
		s2 = s2 + n - 1;
		s1 = s1 + n - 1;
		while (n > 0)
		{
			*s1-- = *s2--;
			n--;
		}
	}
	else
		while (n > 0)
		{
			*s1 = *s2;
			s1++;
			s2++;
			n--;
		}
	return (dest);
}
