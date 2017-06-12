/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:01:20 by hdrumus           #+#    #+#             */
/*   Updated: 2017/02/27 15:01:21 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

#define BUFFERSIZE 600

void	readtetri(char **draw, int n)
{
	int o;
	int k;

	o = 1;
	while (o < n + 1)
	{
		k = 1;
		while (k < n + 1)
		{
			if (draw[o][k] == 0)
				ft_putchar('.');
			else
				ft_putchar(draw[o][k]);
			k++;
		}
		ft_putstr("\n");
		o++;
	}
}

int		parametrii(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [file_name]\n");
		return (0);
	}
	return (1);
}

int		fdverif(int fd)
{
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

int		checkbuff(char *buff)
{
	if (buff[0] == '\0')
	{
		ft_putstr("error\n");
		return (0);
	}
	if (check_buff(buff, 0, 0, 0) == 0 || check_pieces(buff, 0, 0, 0) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		**st;
	int		**testboard;
	char	**db;
	char	buf[BUFFERSIZE];

	db = NULL;
	testboard = NULL;
	if (parametrii(argc) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	read(fd, buf, BUFFERSIZE);
	close(fd);
	db = drawdisplayboard(4, -1, db);
	testboard = drawtestboard(4, -1, testboard);
	st = savetetriminos(buf, testboard, 0, 0);
	if (checkbuff(buf) == 0 || fdverif(fd) == 0)
		return (0);
	else
	{
		db = drawdisplayboard(g(numberpieces(st), st, -1), -1, db);
		testboard = drawtestboard(g(numberpieces(st), st, -1), -1, testboard);
		foundsolution(st, db, testboard, g(numberpieces(st), st, -1));
	}
	return (0);
}
