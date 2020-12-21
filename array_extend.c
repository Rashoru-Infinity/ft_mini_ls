/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_extend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:52:20 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/02 23:52:21 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include <stdint.h>
#include <stdlib.h>

int	extend(void **original, size_t length, size_t elmsize)
{
	void	*new_array;
	size_t	new_size;

	if (!original)
		return (FAIL);
	if (length <= SIZE_MAX >> 1)
		new_size = length << 1;
	else
		return (FAIL);
	if (new_size == 0)
		++new_size;
	if (!(new_array = malloc(new_size * elmsize)))
		return (FAIL);
	if (*original)
		ft_memcpy(new_array, *original, length * elmsize);
	free(*original);
	*original = new_array;
	return (SUCCESS);
}
