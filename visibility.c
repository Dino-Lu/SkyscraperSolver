/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlu <jinlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:02:43 by jinlu             #+#    #+#             */
/*   Updated: 2025/03/02 18:02:55 by jinlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_visible_left(int *line)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < GRID_SIZE)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_right(int *line)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = GRID_SIZE - 1;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i--;
	}
	return (count);
}

int	check_row_clues(t_puzzle *puzzle, int row)
{
	int	line[GRID_SIZE];
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		line[i] = puzzle->grid[row][i];
		i++;
	}
	if (count_visible_left(line) != puzzle->clues[8 + row]
		|| count_visible_right(line) != puzzle->clues[12 + row])
		return (0);
	return (1);
}

int	check_column_clues(t_puzzle *puzzle, int col)
{
	int	line[GRID_SIZE];
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		line[i] = puzzle->grid[i][col];
		i++;
	}
	if (count_visible_left(line) != puzzle->clues[col]
		|| count_visible_right(line) != puzzle->clues[4 + col])
		return (0);
	return (1);
}

int	check_clues(t_puzzle *puzzle, int row, int col)
{
	if (col == GRID_SIZE - 1 && !check_row_clues(puzzle, row))
		return (0);
	if (row == GRID_SIZE - 1 && !check_column_clues(puzzle, col))
		return (0);
	return (1);
}
