/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:12:13 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/03 15:19:13 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include <sys/stat.h>

static void		sort_upward(t_heap *heap, size_t index)
{
	size_t	parent;
	t_dir	tmp;

	if (index == 0)
		return ;
	parent = index % 2 != 0 ? (index - 1) / 2 : (index - 2) / 2;
	if (compare(heap->array[parent], heap->array[index]) < 0)
	{
		tmp = heap->array[parent];
		(*heap).array[parent] = (*heap).array[index];
		(*heap).array[index] = tmp;
		sort_upward(heap, parent);
	}
}

int				push_heap(t_heap *heap, struct stat stat_buf, char *name)
{
	char *filename;

	if (heap->real_size - heap->next_index <= 1)
	{
		if (extend((void **)&((*heap).array),
		heap->real_size, sizeof(t_dir)) == FAIL)
			return (FAIL);
		(*heap).real_size *= 2;
		if (heap->real_size == 0)
			++(*heap).real_size;
	}
	if (!(filename = ft_strdup(name)))
		return (FAIL);
	(*heap).array[(*heap).next_index].name = filename;
	(*heap).array[(*heap).next_index].st_mtim = stat_buf.st_mtim;
	sort_upward(heap, heap->next_index);
	++(*heap).next_index;
	return (SUCCESS);
}
