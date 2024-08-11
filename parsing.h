/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:39:44 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/11 20:28:44 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*◦ Each element first’s information is the type identifier (composed by one or two
character(s)), followed by all specific information for each object in a strict
order such as:
◦ Ambient lightning:
A 0.2 255,255,255
∗ identifier: A
∗ ambient lighting ratio in range [0.0,1.0]: 0.2
∗ R,G,B colors in range [0-255]: 255, 255, 255
◦ Camera:
C -50.0,0,20 0,0,1 70
∗ identifier: C
∗ x,y,z coordinates of the view point: -50.0,0,20
∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
◦ Light:
L -40.0,50.0,0.0 0.6 10,0,255
∗ identifier: L
∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
∗ the light brightness ratio in range [0.0,1.0]: 0.6
∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
◦ Sphere:
sp 0.0,0.0,20.6 12.6 10,0,255
∗ identifier: sp
∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
∗ the sphere diameter: 12.6
∗ R,G,B colors in range [0-255]: 10, 0, 255
7
miniRT My first RayTracer with miniLibX
◦ Plane:
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
∗ identifier: pl
∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
∗ R,G,B colors in range [0-255]: 0,0,225
◦ Cylinder:
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
∗ identifier: cy
∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ the cylinder diameter: 14.2
∗ the cylinder height: 21.42
∗ R,G,B colors in range [0,255]: 10, 0, 255*/

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