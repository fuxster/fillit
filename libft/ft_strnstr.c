/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:43:25 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/07 20:30:06 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t ft_len;

	ft_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && len >= ft_len)
	{
		if (ft_strncmp(big, little, ft_len) == 0)
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}
