/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:32:52 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/08 22:09:54 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s)
	{
		sub = ft_strnew(len);
		if (sub == NULL)
			return (NULL);
		s = s + start;
		i = 0;
		while (i < len)
		{
			sub[i] = s[i];
			i++;
		}
		return (sub);
	}
	return (NULL);
}
