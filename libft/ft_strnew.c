/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:44:32 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/07 20:40:10 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
