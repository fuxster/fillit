/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetare.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:00:50 by hdrumus           #+#    #+#             */
/*   Updated: 2017/02/27 15:00:52 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	resettetriminos(int *t, int **b, int l, int n)
{
	int		o;
	int		y;

	y = 1;
	while (y > 0)
	{
		o = 0;
		while (o++ < 4)
			if ((helpreset(t[o], n, 1, n + 1) || t[o] == 1) && l == 1)
				return ;
		o = -1;
		while (++o < 4)
		{
			t[o] = t[o] - l;
			if ((t[o] <= 0) || (helpreset(t[0], n, 0, 7)))
			{
				t[o] = t[o] + l;
				return ;
			}
			if (b[(rlc(b, t[o], n) - l) / 10][(rlc(b, t[o], n) - l) % 10] == 0)
				y = 0;
		}
		if (t[0] > n && l == n)
			y = 1;
	}
}

int		helpreset(int t, int n, int m, int k)
{
	int		l;

	l = n;
	n = m;
	while (n < l * l - k)
	{
		n = n + l;
		if (t == n)
			return (1);
	}
	return (0);
}

void	resetandremove(int **tboard, int **t, int *nio, char **dboard)
{
	int		o;

	o = 0;
	while (o < 4)
	{
		t[nio[1] + 1][o] = tboard[t[nio[1] + 1][o] / 10][t[nio[1] + 1][o] % 10];
		o++;
	}
	resettetriminos(t[nio[1] + 1], tboard, 1, nio[0]);
	resettetriminos(t[nio[1] + 1], tboard, nio[0], nio[0]);
	t[nio[1] + 1] = rlcall(tboard, t[nio[1] + 1], nio[0]);
	removetetri(t[nio[1]], dboard);
}

void	removetetri(int *t, char **dboard)
{
	int		o;

	o = 0;
	while (o < 4)
	{
		dboard[t[o] / 10][t[o] % 10] = '.';
		o++;
	}
}
