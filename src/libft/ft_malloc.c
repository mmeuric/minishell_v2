/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:34:09 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/28 16:10:26 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_alloc	*g_allocs = NULL;

void	*ft_malloc(size_t size)
{
	void	*ptr;
	t_alloc	*new_alloc;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_alloc = malloc(sizeof(t_alloc));
	if (!new_alloc)
		return (NULL);
	new_alloc->ptr = ptr;
	new_alloc->next = g_allocs;
	g_allocs = new_alloc;
	return (ptr);
}

void	ft_free_all(void)
{
	t_alloc	*tmp;

	while (g_allocs)
	{
		tmp = g_allocs;
		g_allocs = g_allocs->next;
		free(tmp->ptr);
		free(tmp);
	}
}
