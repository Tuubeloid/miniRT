/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:47 by tvalimak          #+#    #+#             */
/*   Updated: 2024/07/16 18:42:41 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int parse_file(char *line)
{
    if (ft_strncmp(line, "A", 1) == 0)
        // func to parse ambiient
    if (ft_strncmp(line, "C", 1) == 0)
        // func to parse camera
    if (ft_strncmp(line, "L", 1) == 0)
        // func to parse lightning
    if (ft_strncmp(line, "sp", 2) == 0)
        // func to parse shapes
    if (ft_strncmp(line, "pl", 2) == 0)
        // func to parse shapes
    if (ft_strncmp(line, "cy", 2) == 0)
        // func to parse shapes
    return (0);
}