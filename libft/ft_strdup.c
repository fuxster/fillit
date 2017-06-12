/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuciu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:13:03 by psuciu            #+#    #+#             */
/*   Updated: 2017/01/07 20:50:45 by psuciu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char *aux;

	aux = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (aux == NULL)
		return (NULL);
	else
		return (ft_strcpy(aux, s));
}
