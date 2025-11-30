/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 01:17:31 by mechrist          #+#    #+#             */
/*   Updated: 2025/11/30 06:05:50 by mechrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistr.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{	
	int *numbers;
	int count;
	int i;
	char	*str;
	int top[4];
	int bottom[4];
	int left[4];
	int right[4];
	int **grid;
	int r;
	int c;

	if (argc !=2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	str = argv[1];
	numbers = malloc(16 * sizeof(int));
	if (!numbers)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] -'4')
		{
			if (count >= 16)
			{
				write(1, "Error\n", 6);
				free(numbers);
				return (0);
			}
			numbers[count] = str[i] - '0';
			count++;
		}
		else if (str[i] != ' ')
		{
			write(1, "Error\n", 6);
			free(numbers);
			return (0);
		}
		i++;

	}
	if (count != 16)
	{
		write(1, "Error\n", 6);
		free(numbers);
		return (0);
	}
	
	i = 0;
	while (i < 4)
	{
		top[i] = numbers[i];
		bottom[i] = numbers[i + 4];
		left[i] = numbers[i + 8];
		right[i] = numbers[i + 12];
		
		i++;
	}
	
	grid = malloc(4 * sizeof(int *));
	if (!grid)
	{
		write(1, "Error\n", 6);
		free(numbers);
		return (0);
	}
	r = 0;
	while (r < 4)
	{
		grid[r] = malloc(4 * sizeof(int));
		if (!grid[r])
		{
			write(1, "Error\n", 6);
			while (r-- > 0)
				free(grid[r]);
			free(grid);
			free(numbers);
			return (0);
		}
		c = 0;
		while (c < 4)
		{
			grid[r][c] = 0;
			c++;
		}
		r++;
	}
	r = 0;
	while (r < 4)
	{
		free(grid[r]);
		r++;
	}
	free(iird);
	free(number);
        return (0);
}

