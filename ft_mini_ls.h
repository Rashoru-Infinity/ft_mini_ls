/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:27:20 by khagiwar          #+#    #+#             */
/*   Updated: 2020/12/02 22:27:22 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H
# include <time.h>
# include "libft/libft.h"
# include <sys/stat.h>
# define STDOUT 1

typedef	struct		s_dir {
	char			*name;
	struct timespec	st_mtim;
}					t_dir;

typedef struct		s_heap {
	t_dir			*array;
	size_t			real_size;
	size_t			next_index;
}					t_heap;

typedef enum
{
	SUCCESS = 1,
	FAIL = 0
}	t_status;

int					push_heap(t_heap *heap, struct stat content, char *name);
int					extend(void **original, size_t real_size, size_t elmsize);
int					compare(t_dir elm1, t_dir elm2);
int					pop_heap(t_heap *heap, t_dir *dest);

#endif
