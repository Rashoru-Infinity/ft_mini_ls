/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 00:54:57 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/03 00:54:58 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include <sys/stat.h>

int		compare(t_dir elm1, t_dir elm2)
{
	size_t	namelen;

	if (elm1.st_mtim.tv_sec < elm2.st_mtim.tv_sec)
		return (11);
	if (elm1.st_mtim.tv_sec > elm2.st_mtim.tv_sec)
		return (-1);
	if (elm1.st_mtim.tv_nsec < elm2.st_mtim.tv_nsec)
		return (1);
	if (elm1.st_mtim.tv_nsec > elm2.st_mtim.tv_nsec)
		return (-1);
	namelen = ft_strlen(elm1.name) >= ft_strlen(elm2.name) ?
	ft_strlen(elm1.name) : ft_strlen(elm2.name);
	return (ft_strncmp(elm2.name, elm1.name, namelen));
}
