/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:00:18 by hdrumus           #+#    #+#             */
/*   Updated: 2017/02/27 17:06:51 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_buff(char *buff, int diez, int dot, int line)
{
	int i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '#')
			diez++;
		if (buff[i] == '.')
			dot++;
		if (buff[i] == '\n')
			line++;
		if (((i + 1) % 21 == 0 && i != 0) || buff[i + 1] == '\0')
		{
			if (buff[i + 1] == '\0')
				line++;
			if (diez != 4 || dot != 12 || line != 5)
				return (0);
			diez = 0;
			dot = 0;
			line = 0;
		}
		i++;
	}
	return (1);
}

int		vecini(char *buff, int index, int k)
{
	int cnt;

	cnt = 0;
	if (buff[index - 1] == '#' && (index - 1) > k)
		cnt++;
	if (buff[index + 1] == '#' && (index + 1) < k + 21)
		cnt++;
	if (buff[index + 5] == '#' && (index + 5) < k + 21)
		cnt++;
	if (buff[index - 5] == '#' && (index - 5) > k)
		cnt++;
	return (cnt);
}

int		check_pieces(char *b, int k, int max, int i)
{
	int cnt;

	while (b[i] != '\0')
	{
		cnt = 0;
		if (b[i] == '#')
		{
			cnt = vecini(b, i, k);
			if (b[i - 1] != '#' && b[i + 1] != '#' && b[i + 5] != '#'
					&& b[i - 5] != '#')
				return (0);
		}
		if (max < cnt)
			max = cnt;
		if (((i + 1) % 21 == 0 && i != 0) || b[i + 1] == '\0')
		{
			k = i;
			if (max < 2)
				return (0);
			max = 0;
		}
		i++;
	}
	return (1);
}
