/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlu <jinlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:55:01 by jinlu             #+#    #+#             */
/*   Updated: 2025/03/02 17:55:09 by jinlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdio.h>

# define GRID_SIZE 4

typedef struct s_puzzle
{
	int	grid[GRID_SIZE][GRID_SIZE];
	int	clues[16];
}	t_puzzle;

int		parse_input(char *str, int *clues);

void	fill_grid(int grid[GRID_SIZE][GRID_SIZE]);
void	print_grid(int grid[GRID_SIZE][GRID_SIZE]);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);

int		count_visible_left(int *line);
int		count_visible_right(int *line);
int		check_clues(t_puzzle *puzzle, int row, int col);

int		is_safe(t_puzzle *puzzle, int row, int col, int height);
int		get_next_position(int row, int col, int *next_row, int *next_col);
int		solve_skyscraper(t_puzzle *puzzle, int row, int col);

#endif
