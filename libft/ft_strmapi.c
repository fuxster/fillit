/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:47:08 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/08 22:09:25 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (s && f)
	{
		new = ft_strnew(ft_strlen(s));
		if (new == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			new[i] = f(i, s[i]);
			i++;
		}
		return (new);
	}
	return (NULL);
}
