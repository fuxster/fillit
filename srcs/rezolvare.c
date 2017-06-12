/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rezolvare.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:01:30 by hdrumus           #+#    #+#             */
/*   Updated: 2017/02/27 15:01:31 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	foundsolution(int **tetriminos, char **dboard, int **tboard, int n)
{
	int		o;
	int		i;
	int		nio[3];

	nio[0] = n;
	nio[1] = 0;
	nio[2] = 0;
	tboard = drawtestboard(n, -1, tboard);
	dboard = drawdisplayboard(n, -1, dboard);
	i = 0;
	while (tetriminos[i] != NULL)
	{
		o = 0;
		if (validposition(dboard, tetriminos[i], 0, nio[0]))
			while (o < 4)
			{
				tetriminos[i][o] = tetriminos[i][o] - 1;
				o++;
			}
		i++;
	}
	if (!drawtetriminoseachposition(tetriminos, dboard, tboard, nio))
		foundsolution(tetriminos, dboard, tboard, n + 1);
}

void	functieresetare(int **t, int n, int o, int **tboard)
{
	o = 0;
	while (o < 4)
	{
		t[0][o] = tboard[t[0][o] / 10][t[0][o] % 10];
		o = o + 1;
	}
	resettetriminos(t[0], tboard, 1, n);
	resettetriminos(t[0], tboard, n, n);
	t[0] = rlcall(tboard, t[0], n);
}

int		drawtetriminoseachposition(int **t, char **db, int **tboard, int *nio)
{
	if (t[nio[1]] != NULL)
		if (!tryy(t, db, tboard, nio))
		{
			if (nio[1] == 0)
			{
				functieresetare(t, nio[0], nio[2], tboard);
				return (0);
			}
			else
			{
				nio[1] = nio[1] - 1;
				resetandremove(tboard, t, nio, db);
				nio[1] = nio[1] + 1;
				nio[2] = 0;
				while (nio[2] < 4)
				{
					t[nio[1]][nio[2]] = t[nio[1]][nio[2]] - 1;
					nio[2] = nio[2] + 1;
				}
				return (0);
			}
		}
	readtetri(db, nio[0]);
	exit(1);
}

int		tryy(int **tetriminos, char **dboard, int **tboard, int *nio)
{
	int	k;

	k = 0;
	while (checkchar(tboard, tetriminos[nio[1]], nio[0], -1))
	{
		if (validposition(dboard, tetriminos[nio[1]], 0, nio[0]))
		{
			drawtetrimino(tboard, tetriminos[nio[1]], dboard, nio);
			nio[1] = nio[1] + 1;
			drawtetriminoseachposition(tetriminos, dboard, tboard, nio);
			nio[1] = nio[1] - 1;
		}
	}
	return (0);
}

int		drawtetrimino(int **tboard, int *t, char **dboard, int *nio)
{
	int		p;
	char	k;

	k = t[4];
	p = -1;
	if (validposition(dboard, t, 0, nio[0]))
		while (p++ < 3)
		{
			dboard[t[p] / 10][t[p] % 10] = k;
		}
	else
	{
		if (!(checkchar(tboard, t, nio[0], -1)))
			return (0);
		return (drawtetrimino(tboard, t, dboard, nio));
	}
	return (1);
}
