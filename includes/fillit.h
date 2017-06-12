/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 21:59:23 by ptoma             #+#    #+#             */
/*   Updated: 2017/02/26 21:59:25 by ptoma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		check_buff(char *a, int b, int c, int d);
int		check_pieces(char *a, int b, int c, int d);
void	readtetri(char **a, int b);
int		rlc(int **a, int b, int c);
int		*rlcall(int **a, int *b, int c);
int		g(int a, int **b, int c);
int		validposition(char **a, int *b, int c, int d);
int		helpreset(int a, int b, int c, int d);
void	resettetriminos(int *a, int **b, int c, int d);
int		checkchar(int **a, int *b, int c, int d);
int		drawtetrimino(int **a, int *b, char **c, int *d);
void	removetetri(int *a, char **b);
char	**drawdisplayboard(int a, int b, char **c);
int		numberpieces(int **a);
void	resetandremove(int **a, int **b, int *c, char **d);
int		tryy(int **a, char **b, int **c, int *d);
int		drawtetriminoseachposition(int **a, char **b, int **c, int *d);
void	foundsolution(int **a, char **b, int **c, int d);
int		**savetetriminos(char *a, int **b, int c, int d);
int		**drawtestboard(int a, int b, int **c);

#endif
