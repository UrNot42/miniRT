/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 03:40:23 by ulevallo          #+#    #+#             */
/*   Updated: 2024/03/05 12:29:53 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buff_list	*gnl_new_nd(t_buff_list *node)
{
	if (node)
	{
		node->next = malloc(sizeof(t_buff_list));
		if (!node->next)
			return (NULL);
		node = node->next;
	}
	else
	{
		node = malloc(sizeof(t_buff_list));
		if (!node)
			return (NULL);
	}
	node->next = NULL;
	node->nwln = -1;
	node->size = 0;
	node->read = 0;
	return (node);
}

int	gnl_nwln(t_buff_list *node, int skip)
{
	size_t	index;
	int		i;

	i = 0;
	index = 0;
	if (skip < 0)
		return (0);
	while (index < node->size)
		if (node->buff[index++] == '\n')
			if (i++ == skip)
				return (index);
	return (0);
}

static int	save_gnl(t_buff_list **head)
{
	*head = gnl_new_nd(*head);
	if (!(*head))
		return (false);
	return (true);
}

char	*get_next_line(int fd)
{
	static t_buff_list	*head = NULL;
	t_buff_list			*node;
	int					rd_size;

	if (fd < 0)
		return (free(head), NULL);
	if (!head && !save_gnl(&head))
		return (NULL);
	node = head;
	if (node->nwln <= 0)
		node = gnl_new_nd(head);
	rd_size = BUFFER_SIZE;
	while (node->nwln <= 0 && rd_size >= BUFFER_SIZE)
	{
		rd_size = read(fd, node->buff, BUFFER_SIZE);
		if (rd_size <= 0 || fd < 0)
			return (free(head->next), free(head), head = NULL, NULL);
		node->size = rd_size;
		node->nwln = gnl_nwln(node, 0);
		node->buff[rd_size] = '\0';
		if (node->nwln <= 0)
			node = gnl_new_nd(node);
	}
	return (gnl_lst_str(&head));
}
