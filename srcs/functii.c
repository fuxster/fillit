/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:00:34 by hdrumus           #+#    #+#             */
/*   Updated: 2017/02/27 15:00:36 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		validposition(char **dboard, int *t, int a, int n)
{
	int		o;
	int		k;
	int		c;

	c = 1;
	o = 0;
	while (o < n + 1 && a < 4)
	{
		k = 0;
		while (k < n + 1)
		{
			if (dboard[t[a] / 10][t[a] % 10] == '.')
				return (c = c * validposition(dboard, t, a + 1, n));
			k++;
		}
		o++;
	}
	if (a < 4)
		c = 0;
	return (c);
}

int		checkchar(int **tboard, int *t, int n, int o)
{
	int		p;
	int		l;

	l = 1;
	p = -1;
	while (p++ < 3)
		if (tboard[t[p] / 10][(t[p] % 10) + 1] == 0)
		{
			while (++o < 4)
				t[o] = tboard[t[o] / 10][t[o] % 10];
			resettetriminos(t, tboard, 1, n);
			t = rlcall(tboard, t, n);
			l = 10;
			break ;
		}
	p = -1;
	while (p++ < 3)
	{
		if (((t[p] + l) / 10) > n)
			return (0);
	}
	p = -1;
	while (p++ < 3)
		t[p] = t[p] + l;
	return (1);
}

int		rlc(int **board, int tetrimino, int n)
{
	int		o;
	int		k;

	o = 0;
	while (o < n + 1)
	{
		k = 0;
		while (k < n + 1)
		{
			if (board[o][k] == tetrimino)
			{
				return (o * 10 + k);
			}
			k++;
		}
		o++;
	}
	return (0);
}

int		*rlcall(int **board, int *t, int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		t[i] = rlc(board, t[i], n);
		i++;
	}
	return (t);
}

int		g(int n, int **tetriminos, int p)
{
	int k;
	int u;

	k = 0;
	if (n <= 2)
	{
		while (tetriminos[++p] != '\0')
		{
			u = -1;
			while (++u < 4)
				if (tetriminos[p][u] % 10 > k)
					k = tetriminos[p][u] % 10;
				else if (tetriminos[p][u] / 10 > k)
					k = tetriminos[p][u] / 10;
		}
		return (k);
	}
	u = 2;
	while (k < n * 4)
	{
		k = u;
		k = k * u;
		u++;
	}
	return (u - 1);
}
