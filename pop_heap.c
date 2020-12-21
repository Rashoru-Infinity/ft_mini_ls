/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 01:01:48 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/03 12:12:41 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_mini_ls.h"

static int	set_child(t_heap *heap, size_t index, size_t *child)
{
	if (index > (SIZE_MAX - 1) / 2)
		return (FAIL);
	if (index == (SIZE_MAX - 1) / 2)
	{
		if (index * 2 + 1 <= heap->next_index - 1)
			*child = index * 2 + 1;
		else
			return (FAIL);
	}
	if (index <= (SIZE_MAX - 2) / 2)
	{
		if (index * 2 + 2 <= heap->next_index - 1)
		{
			if (compare(heap->array[index * 2 + 1],
			heap->array[index * 2 + 2]) > 0)
				*child = index * 2 + 1;
			else
				*child = index * 2 + 2;
		}
		else if (index * 2 + 1 == heap->next_index - 1)
			*child = index * 2 + 1;
		else
			return (FAIL);
	}
	return (SUCCESS);
}

static void	sort_downward(t_heap *heap, size_t index)
{
	size_t	child;
	t_dir	tmp;

	if (set_child(heap, index, &child) == FAIL)
		return ;
	if (compare(heap->array[index], heap->array[child]) < 0)
	{
		tmp = heap->array[index];
		(*heap).array[index] = (*heap).array[child];
		(*heap).array[child] = tmp;
		sort_downward(heap, child);
	}
}

int			pop_heap(t_heap *heap, t_dir *dest)
{
	if (heap->next_index == 0)
		return (FAIL);
	*dest = (*heap).array[0];
	(*heap).array[0] = (*heap).array[(*heap).next_index-- - 1];
	if (heap->next_index >= 1)
		sort_downward(heap, 0);
	return (SUCCESS);
}
