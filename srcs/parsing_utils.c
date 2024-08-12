/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:18:40 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/12 19:50:41 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

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
	if (ft_atoi(split[0]) < min || ft_atoi(split[0]) > max)
		return (free_split(split));
	if (ft_atoi(split[1]) < min || ft_atoi(split[1]) > max)
		return (free_split(split));
	if (ft_atoi(split[2]) < min || ft_atoi(split[2]) > max)
		return (free_split(split));
	free_split(split);
	return (1);
}

int	pos_decimal_check(char *str, int i, int j)
{
	char	**split;

	split = ft_split(str, '.');
	if (split[0] == NULL || split[1] == NULL || split[2] != NULL)
		return (free_split(split));
	if (split[0][1] != '\0' || split[1][1] != '\0')
		return (free_split(split));
	while (i < 2)
	{
		while (split[i][j])
		{
			if (ft_isdigit(split[i][j]) == 0)
				return (free_split(split));
			j++;
		}
		j = 0;
		i++;
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
