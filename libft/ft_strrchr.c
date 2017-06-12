/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:29:27 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/07 20:28:10 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char *pnt;

	pnt = NULL;
	while (*s)
	{
		if (*s == (char)c)
			pnt = (char *)s;
		++s;
	}
	if (*s == (char)c)
		pnt = (char *)s;
	return (pnt);
}
