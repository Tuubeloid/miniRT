/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:16:31 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/17 22:26:20 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	setup_raw_data(char *line, t_raw_data *raw_data)
{
	if (raw_data->line == NULL)
	{
		raw_data->line = ft_strdup(line);
		if (raw_data->line == NULL)
			return (0);
		return (1);
	}
	while (raw_data->next != NULL)
		raw_data = raw_data->next;
	raw_data->next = malloc(sizeof(t_raw_data));
	if (raw_data->next == NULL)
		return (0);
	raw_data->next->line = ft_strdup(line);
	if (raw_data->next->line == NULL)
		return (0);
	raw_data->next->next = NULL;
	return (1);
}

int	validate_ambient(char *line, int i, t_element_count *element_count, \
	t_raw_data *raw_data)
{
	char	**split;

	split = ft_split(line, ' ');
	printf("%s\n%s\n%s", split[0], split[1], split[2]);
	if (split[0][0] != 'A' || split[0][1] != '\0')
		return (free_split(split));
	while (i < 3)
	{
		if (split[i] == NULL)
			return (free_split(split));
		i++;
	}
	if (split[3] != NULL)
		return (free_split(split));
	if (pos_decimal_check(split[1]) == 0)
		return (free_split(split));
	if (rgb_check(split[2], 0, 255) == 0)
		return (free_split(split));
	if (setup_raw_data(line, raw_data) == 0)
		return (free_split(split));
	free_split(split);
	element_count->ambient++;
	printf("Returning 1 from validate_ambient\n");
	return (1);
}
