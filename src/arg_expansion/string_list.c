/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:17:37 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:17:40 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>
#include <assert.h>

t_str	*new_str(char *str, bool to_expand)
{
	t_str	*node;

	node = ft_malloc(sizeof(t_str));
	if (!node)
		return (NULL);
	node->str = ft_strdup(str);
	node->wild_card = to_expand;
	node->next = NULL;
	return (node);
}

t_str	*ft_strlast(t_str *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	free_strnode(t_str *node)
{
	free(node->str);
	free(node);
}

int	ft_strlstlen(t_str *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	ft_striter(t_str *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
