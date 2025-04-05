/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlu <jinlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:07:24 by jinlu             #+#    #+#             */
/*   Updated: 2025/03/02 17:06:59 by jinlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	get_next_position(int row, int col, int *next_row, int *next_col)
{
	if (col == GRID_SIZE - 1)
	{
		*next_row = row + 1;
		*next_col = 0;
	}
	else
	{
		*next_row = row;
		*next_col = col + 1;
	}
	return (0);
}

int	solve_skyscraper(t_puzzle *puzzle, int row, int col)
{
	int	next_row;
	int	next_col;
	int	height;

	if (row == GRID_SIZE)
		return (1);
	get_next_position(row, col, &next_row, &next_col);
	if (puzzle->grid[row][col] != 0)
	{
		return (solve_skyscraper(puzzle, next_row, next_col));
	}
	height = 1;
	while (height <= GRID_SIZE)
	{
		if (is_safe(puzzle, row, col, height))
		{
			puzzle -> grid[row][col] = height;
			if (solve_skyscraper(puzzle, next_row, next_col))
				return (1);
			puzzle -> grid[row][col] = 0;
		}
		height++;
	}
	return (0);
}
