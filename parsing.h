/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:39:44 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/15 15:43:16 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include "libft/GNL/get_next_line.h"

# include <fcntl.h>
# include <stdio.h>

typedef struct s_map t_map;

typedef struct s_ambient
{
	char    *id;
	float  ratio;
	int     r;
	int     g;
	int     b;
	t_map	*map;
}               t_ambient;

typedef struct s_camera
{
	char    *id;
	float  x;
	float  y;
	float  z;
	float  nx;
	float  ny;
	float  nz;
	float  fov;
	t_map	*map;
}               t_camera;

typedef struct s_light
{
	char    *id;
	float  x;
	float  y;
	float  z;
	float  ratio;
	int     r;
	int     g;
	int     b;
	t_map	*map;
}               t_light;

typedef struct s_sphere
{
	int    id;
	float  x;
	float  y;
	float  z;
	float  diameter;
	int     r;
	int     g;
	int     b;
	t_map	*map;
}               t_sphere;

typedef struct s_plane
{
	char    *id;
	float  x;
	float  y;
	float  z;
	float  nx;
	float  ny;
	float  nz;
	int     r;
	int     g;
	int     b;
	t_map	*map;
}               t_plane;

typedef struct s_cylinder
{
	char    *id;
	float  x;
	float  y;
	float  z;
	float  nx;
	float  ny;
	float  nz;
	float  diameter;
	float  height;
	int     r;
	int     g;
	int     b;
	t_map	*map;
}               t_cylinder;

typedef struct s_element_count
{
	int		ambient;
	int		camera;
	int		light;
	int		sphere;
	int		plane;
	int		cylinder;
}				t_element_count;

typedef struct s_map
{
	t_ambient   	*ambient;
	t_camera    	**camera;
	t_light     	**light;
	t_sphere    	**sphere;
	t_plane     	**plane;
	t_cylinder  	**cylinder;
	t_element_count *element_count;
}               t_map;

/* ************************************************************************** */
/*                                 parsing_utils.c                            */
/* ************************************************************************** */

int		validate_lines(char *line, t_element_count *element_count);
int		check_element_count(t_element_count *element_count, int flag);
int		validate_ambient(char *line, int i, t_element_count *element_count);
int 	validate_light(char *line, int i, t_element_count *element_count);
int		free_split(char **split);
int		pos_decimal_check(char *str);
int		rgb_check(char *rgb, int min, int max);
double	ft_atof(const char *str);
int 	vectors_check(char *str);


/* ************************************************************************** */
/*                                 validate_camera.c                          */
/* ************************************************************************** */

int xyz_check(char *str);
int decimal_check(char *str, int min, int max);
int	validate_camera(char *line, int i, t_element_count *element_count);

/* ************************************************************************** */
/*                                 validation of shapes                       */
/* ************************************************************************** */

int validate_sphere(char *line, t_element_count *element_count);
int validate_plane(char *line, t_element_count *element_count);
int validate_cylinder(char *line, t_element_count *element_count);

#endif