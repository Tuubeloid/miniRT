/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:18:40 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/13 19:45:52 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"
#include <ctype.h>

int	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
/*
int	is_rgb_number(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("%s\n%s\n%s\n%s\n", split[0] , split[1], split[2], split[3]);
	while (i < 3)
	{
		while (split[i][j] != '\0')
		{
			//if (ft_isdigit(split[i][j]) == 0)
			if (ft_isdigit(ft_atoi(split[i])) == 1)
			{
				printf("returning 0 from is rgb number\n");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}*/
/*
int	is_rgb_number(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("%s\n%s\n%s\n", split[0] , split[1], split[2]);
	while (i < 3)
	{
		while (split[i][j] != '\0' || split[i][j] != '\n')
		{
			if (ft_atoi(split[i][j]) < 0 || ft_atoi(split[i][j]) > 255)
			{
				printf("returning 0 from is rgb number\n");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}*/


int is_rgb_number(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("%s\n%s\n%s", split[0] , split[1], split[2]);
	while (i < 3)
	{
		printf("inside is rgb number while loop\n");
		while (split[i][j] != '\0')
		{
			if (split[i][j] == '\n')
				break ;
			printf("inside is rgb number while loop 2\n");
			printf("split[i][j] = %c\n", split[i][j]);
			if (!isdigit(split[i][j]))
			{
				printf("returning 0 from is rgb number\n");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("returned 1 from is rgb number\n");
	return (1);
}

int	rgb_check(char *rgb, int min, int max)
{
	char	**split;

	split = ft_split(rgb, ',');
	if (split[0] == NULL)
		return (free_split(split));
	if (split[1] == NULL)
		return (free_split(split));
	if (split[2] == NULL)
		return (free_split(split));
	if (split[3] != NULL)
		return (free_split(split));
	printf("inside rgb check 0\n");
	if (is_rgb_number(split) == 0)
		return (free_split(split));
	printf("inside rgb check 1\n");
	if (ft_atoi(split[0]) < min || ft_atoi(split[0]) > max)
		return (free_split(split));
	if (ft_atoi(split[1]) < min || ft_atoi(split[1]) > max)
		return (free_split(split));
	if (ft_atoi(split[2]) < min || ft_atoi(split[2]) > max)
		return (free_split(split));
	free_split(split);
	printf("returned 1 from rgb check\n");
	return (1);
}
// A double in C typically provides about 15 to 17 
// significant decimal digits of precision. Figure out
// how many decimals we need to check for the ratio.

int	pos_decimal_check(char *str, int i, int j)
{
	char	**split;

	printf("inside pos decimal check\n");
	split = ft_split(str, '.');
	if (split[0] == NULL || split[1] == NULL || split[2] != NULL)
		return (free_split(split));
	if (split[0][1] != '\0')
		return (free_split(split));
	while (i < 2)
	{
		printf("inside pos decimal check while loop\n");
		while (split[i][j] != '\0')
		{
			printf("inside pos decimal check while loop 2\n");
			if (isdigit(split[i][j]) == 0)
			{
				printf("returning 0 from pos decimal check\n");
				return (free_split(split));
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (ft_atoi(split[0]) < 0 || ft_atoi(split[0]) > 1)
	{
		printf("returning 0 from pos decimal check 1\n");
		return (free_split(split));
	}
	if (ft_atoi(split[1]) < 0 || ft_atoi(split[1]) > 9)
	{
		printf("returning 0 from pos decimal check 2\n");
		return (free_split(split));
	}
	free_split(split);
	printf("returned 1 from pos decimal check\n");
	return (1);
}

int	check_element_count(t_element_count *element_count)
{
	if (element_count->ambient > 1)
		return (0);
	if (element_count->camera > 1)
		return (0);
	if (element_count->light > 3)
		return (0);
	if (element_count->sphere > 3)
		return (0);
	if (element_count->plane > 3)
		return (0);
	if (element_count->cylinder > 3)
		return (0);
	printf("returned 1 from check element count\n");
	return (1);
}

int	validate_lines(char *line, t_element_count *element_count)
{
	if (check_element_count(element_count) == 0)
		return (0);
	else if (ft_strncmp(line, "\n", 1) == 0)
		return (1);
	else if (ft_strncmp(line, "A", 1) == 0)
		return (validate_ambient(line, 1, element_count));
	else if (ft_strncmp(line, "C", 1) == 0)
		return (1);
	else if (ft_strncmp(line, "L", 1) == 0)
		return (1);
	else if (ft_strncmp(line, "sp", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "pl", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "cy", 2) == 0)
		return (1);
	else
		return (0);
	return (1);
}
