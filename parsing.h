/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:39:44 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/11 20:29:15 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include "libft/GNL/get_next_line.h"

// here make a struct definition to hold all elements
// make a struct definition to hold all the map data

typedef struct s_ambient
{
	char    *id;
	double  ratio;
	int     r;
	int     g;
	int     b;
}               t_ambient;

typedef struct s_camera
{
	char    *id;
	double  x;
	double  y;
	double  z;
	double  nx;
	double  ny;
	double  nz;
	double  fov;
}               t_camera;

typedef struct s_light
{
	char    *id;
	double  x;
	double  y;
	double  z;
	double  ratio;
	int     r;
	int     g;
	int     b;
}               t_light;

typedef struct s_sphere
{
	char    *id;
	double  x;
	double  y;
	double  z;
	double  diameter;
	int     r;
	int     g;
	int     b;
}               t_sphere;

typedef struct s_plane
{
	char    *id;
	double  x;
	double  y;
	double  z;
	double  nx;
	double  ny;
	double  nz;
	int     r;
	int     g;
	int     b;
}               t_plane;

typedef struct s_cylinder
{
	char    *id;
	double  x;
	double  y;
	double  z;
	double  nx;
	double  ny;
	double  nz;
	double  diameter;
	double  height;
	int     r;
	int     g;
	int     b;
}               t_cylinder;

// lets create a main struct which will hold all the elements, there might be muleltiple nodes of most of the elements

typedef struct s_map
{
	t_ambient   *ambient;
	t_camera    **camera;
	t_light     **light;
	t_sphere    **sphere;
	t_plane     **plane;
	t_cylinder  **cylinder;
}               t_map;

// make a struct definition here to hold all the map data

#endif