/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:05:28 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/14 18:54:23 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

// Camera data parser has to handle:
/*
∗ identifier: C
∗ x,y,z coordinates of the view point: -50.0,0,20
∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
∗ FOV : Horizontal field of view in degrees in range [0,180]: 70*/

int unsigned_decimal_check(char *str)
{
    double  value;
    char    *c;

    c = str;
    while (*c)
    {
        if (ft_isdigit(*c) && *c != '.')
        {
            printf("returning 0 from pos decimal check\n");
            return 0;
        }
        c++;
    }
    value = ft_atof(str);
    if (*c == '-')
        c++;
    while (!ft_isdigit(*c))
        c++;
    if (*c == '.')
        c++;
    while (!ft_isdigit(*c))
        c++;
    if (*c != '\0' || value < -1000.0 || value > 1000.0) 
    {
        printf("returning 0 from pos decimal check\n");
        return 0;
    }
    printf("returned 1 from unsigned decimal check\n");
    return 1;
}

int xyz_check(char *str)
{
    char    **split;

    split = ft_split(str, ',');
    printf("%s\n%s\n%s\n%s", split[0], split[1], split[2], split[3]);
    //while (split)
    //{
//
  //  }
    return (1);
}

int	validate_camera(char *line, int i, t_element_count *element_count)
{
    char	**split;

    printf("inside validate_camera\n");
	split = ft_split(line, ' ');
	printf("%s\n%s\n%s\n%s", split[0], split[1], split[2], split[3]);
    if (split[0][0] != 'C' || split[0][1] != '\0')
    {
        printf("returning 0 from validate_camera 0\n");
		return (free_split(split));
    }
    while (i < 4)
	{
		if (split[i] == NULL)
        {
            printf("returning 0 from validate_camera 1\n");
			return (free_split(split));
        }
		i++;
	}
	if (split[4] != NULL)
    {
        printf("returning 0 from validate_camera 2\n");
		return (free_split(split));
    }
    // add x,y,z coordinates check
    if (xyz_check(split[1]) == 0)
    {
        printf("returning 0 from validate_camera 3\n");
        return (free_split(split));
    }
    // add unsigned decimal check for three vectors
    // add FOV check
    free_split(split);
    element_count->camera++;
    printf("returned 1 from camera check\n");
    return (1);
}