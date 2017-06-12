/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:03:35 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/05 21:00:03 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *val;

	val = malloc(size);
	if (val == NULL)
		return (NULL);
	else
		return (ft_memset(val, '\0', size));
}
