/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creare.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:01:10 by hdrumus           #+#    #+#             */
/*   Updated: 2017/02/27 15:01:12 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		**drawtestboard(int n, int j, int **testboard)
{
	int contor;
	int i;

	contor = -n;
	testboard = (int **)malloc(sizeof(int *) * (n + 2) + 1);
	while (j++ < n + 2)
	{
		i = -1;
		testboard[j] = (int *)malloc(sizeof(int) * (n + 2) + 1);
		while (i++ < n + 2)
		{
			if (j == n + 1 || j == 0 || i == 0 || i == n + 1)
				testboard[j][i] = 0;
			else
				testboard[j][i] = contor;
			contor++;
		}
		contor = contor - 3;
	}
	return (testboard);
}

char	**drawdisplayboard(int n, int j, char **displayboard)
{
	int i;

	displayboard = (char **)malloc(sizeof(char *) * (n + 100));
	while (j++ < n + 2)
	{
		i = -1;
		displayboard[j] = (char *)malloc(sizeof(char) * (n + 100));
		while (i++ < n + 2)
		{
			if (j == n + 1 || j == 0 || i == 0 || i == n + 1)
				displayboard[j][i] = '0';
			else
				displayboard[j][i] = '.';
		}
	}
	return (displayboard);
}

int		numberpieces(int **tetr)
{
	int i;

	i = 0;
	while (tetr[i] != '\0')
		i++;
	return (i);
}

int		**savetetriminos(char *buf, int **board, int i, int j)
{
	int **tetriminosinfo;
	int contor;

	tetriminosinfo = (int **)malloc(sizeof(int *) * 27);
	while (*(buf + 1) != '\0')
	{
		j = 0;
		contor = 1;
		tetriminosinfo[i] = (int *)malloc(sizeof(int) * 5);
		while (contor < 17)
		{
			if (*buf == '#')
				tetriminosinfo[i][j++] = contor;
			if (*buf != '\n')
				contor++;
			buf++;
		}
		tetriminosinfo[i][j] = i + 65;
		resettetriminos(tetriminosinfo[i], board, 1, 4);
		resettetriminos(tetriminosinfo[i], board, 4, 4);
		tetriminosinfo[i] = rlcall(board, tetriminosinfo[i], 4);
		i++;
	}
	tetriminosinfo[i] = NULL;
	return (tetriminosinfo);
}
