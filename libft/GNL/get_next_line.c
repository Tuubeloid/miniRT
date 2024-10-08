/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:10 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/10 20:07:25 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int len_to_char(t_list *dump, int flag)
{
    int i;
    int len;
    char *content;

    if (dump == NULL)
        return (0);
    len = 0;
    while (dump)
    {
        i = 0;
        content = (char *)(dump->content);
        while (content[i])
        {
            if (content[i] == '\n')
            {
                ++i;
                ++len;
                return (len);
            }
            ++i;
            ++len;
        }
        dump = dump->next;
    }
    if (flag == 1)
        return (len);
    return (0);
}

static char	*get_new_line(t_list **dump, char *line)
{
	size_t	str_len;

	if (NULL == dump)
		return (NULL);
	str_len = len_to_char(*dump, 1);
	line = malloc(str_len + 1);
	if (NULL == line)
	{
		free(line);
		return (NULL);
	}
	cpy_str(*dump, line);
	return (line);
}

char	*cpy_str(t_list *dump, char *next_line)
{
	int		src;
	int		dst;
	char	*content;

	dst = 0;
	while (dump)
	{
		src = 0;
		content = (char *)(dump->content);
		while (content[src])
		{
			if (content[src] == '\n')
			{
				next_line[dst] = '\n';
				dst++;
				next_line[dst] = '\0';
				return (next_line);
			}
			next_line[dst++] = content[src++];
		}
		free(dump->content);
		dump->content = NULL;
		dump = dump->next;
	}
	next_line[dst] = '\0';
	return (next_line);
}

static t_list	*ft_read_to_dump(int fd, t_list **dump)
{
	char	*buff;
	int		bytes_read;
	t_list	*new_node;

	while (len_to_char(*dump, 0) == 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		new_node = malloc(sizeof(t_list));
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (!buff || !new_node || bytes_read < 0)
		{
			free(buff);
			free(new_node);
			return (NULL);
		}
		if (bytes_read <= 0)
		{
			free (buff);
			free(new_node);
			return (*dump);
		}
		buff[bytes_read] = '\0';
		ft_append_node(dump, new_node, buff);
	}
	return (*dump);
}

char	*get_next_line(int fd)
{
	static t_list	*dump;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
	{
		ft_terminate(&dump);
		return (NULL);
	}
	if (!ft_read_to_dump(fd, &dump))
	{
		ft_terminate(&dump);
		return (NULL);
	}
	line = get_new_line(&dump, line);
	if (!line)
	{
		ft_terminate(&dump);
		return (NULL);
	}
	ft_polish_dump(&dump);
	return (line);
}
