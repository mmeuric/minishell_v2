/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:39:29 by jojo              #+#    #+#             */
/*   Updated: 2025/04/01 01:52:09 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"
#include <stdio.h>

int	cd_home(t_env *env)
{
	t_env	*node;

	node = search_in_env(env, "HOME");
	if (!node)
	{
		printf("cd: HOME not set\n");
		return (1);
	}
	return (change_directory(node->value));
}

int	cd_oldpwd(t_env *env)
{
	t_env	*node;
	int		ret;

	node = search_in_env(env, "OLDPWD");
	if (!node)
	{
		printf("cd: OLDPWD not set\n");
		return (1);
	}
	ret = change_directory(node->value);
	if (ret == 0)
		printf("%s\n", node->value);
	return (ret);
}

int	cd(char *arg, t_env *env)
{
	if (!arg)
		return (cd_home(env));
	if (!ft_strcmp(arg, "-"))
		return (cd_oldpwd(env));
	return (change_directory(arg));
}
