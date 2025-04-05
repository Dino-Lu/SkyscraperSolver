/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isSafe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlu <jinlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:36:07 by jinlu             #+#    #+#             */
/*   Updated: 2025/03/02 16:55:14 by jinlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_safe(t_puzzle *puzzle, int row, int col, int height)
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (puzzle -> grid[row][i] == height)
			return (0);
		i++;
	}
	i = 0;
	while (i < GRID_SIZE)
	{
		if (puzzle -> grid[i][col] == height)
			return (0);
		i++;
	}
	puzzle -> grid[row][col] = height;
	if (!check_clues(puzzle, row, col))
	{
		puzzle -> grid[row][col] = 0;
		return (0);
	}
	puzzle -> grid[row][col] = 0;
	return (1);
}
