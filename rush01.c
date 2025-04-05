/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlu <jinlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:28:26 by jinlu             #+#    #+#             */
/*   Updated: 2025/03/02 16:32:07 by jinlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	t_puzzle	puzzle;

	if (argc != 2 || !parse_input(argv[1], puzzle.clues))
	{
		ft_putstr("Error\n");
		return (1);
	}
	fill_grid(puzzle.grid);
	if (solve_skyscraper(&puzzle, 0, 0))
		print_grid(puzzle.grid);
	else
		ft_putstr("Error\n");
	return (0);
}
