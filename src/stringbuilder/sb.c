/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:55:17 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/06 14:55:19 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stringbuilder.h>

t_strbuilder	*stringbuilder(void)
{
	t_strbuilder	*sb;

	sb = ft_malloc(sizeof(t_strbuilder));
	if (!sb)
		return (NULL);
	sb->capacity = 16;
	sb->str = ft_calloc(1, sb->capacity);
	if (!sb)
		return (free(sb), NULL);
	sb->used_len = 0;
	return (sb);
}

t_strbuilder	*sb_append(t_strbuilder *sb, char *str)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (sb->used_len + len + 1 > sb->capacity)
		sb_reallocate(sb, len);
	ft_memcpy(sb->str + sb->used_len, str, len);
	sb->used_len += len;
	return (sb);
}

t_strbuilder	*sb_append_free(t_strbuilder *sb, char *str)
{
	t_strbuilder	*to_return;

	to_return = sb_append(sb, str);
	free(str);
	return (to_return);
}

t_strbuilder	*sb_append_int(t_strbuilder *sb, int nb)
{
	char	*str;

	str = ft_itoa(nb);
	if (!str)
		return (NULL);
	return (sb_append_free(sb, str));
}

void	sb_free(t_strbuilder *sb)
{
	free(sb->str);
	free(sb);
}
