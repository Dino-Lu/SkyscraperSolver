/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlu <jinlu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:40:32 by jinlu             #+#    #+#             */
/*   Updated: 2025/03/04 13:22:27 by jinlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	parse_input(char *str, int *clues)
{
	int	i;
	int	prev_digit;
	int	has_space;

	i = 0;
	prev_digit = 0;
	has_space = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= '4')
		{
			if (i >= 16)
				return (0);
			clues[i++] = *str - '0';
			prev_digit = 1;
			
			if(*(str + 1) && *(str + 1) != ' ')
				return (0);
		}
		else if (*str == ' ')
		{
			if (prev_digit == 0)
				return (0);
			prev_digit = 0;
			has_space = 1;
		}
		else
			return (0);
		str++;
	}
	return (i == 16 && prev_digit == 1 && has_space);
}
