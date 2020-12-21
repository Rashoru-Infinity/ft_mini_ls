/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:24:57 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/03 04:35:57 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mini_ls.h"
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static void	putdir(t_heap *heap)
{
	t_dir curr;

	while (pop_heap(heap, &curr) == SUCCESS)
	{
		if (curr.name[0] != '.')
		{
			write(STDOUT, curr.name, ft_strlen(curr.name));
			write(STDOUT, "\n", 1);
		}
		free(curr.name);
	}
	free(heap->array);
	(*heap).array = NULL;
}

int			main(void)
{
	t_heap			dirinfo;
	DIR				*dir;
	struct dirent	*dp;
	struct stat		stat_buf;

	ft_bzero(&dirinfo, sizeof(t_heap));
	if (!(dir = opendir("./")))
	{
		perror(strerror(errno));
		return (0);
	}
	while ((dp = readdir(dir)))
	{
		if (lstat(dp->d_name, &stat_buf) != 0
		|| push_heap(&dirinfo, stat_buf, dp->d_name) == FAIL)
		{
			perror(strerror(errno));
			break ;
		}
	}
	closedir(dir);
	if (!errno)
		putdir(&dirinfo);
}
