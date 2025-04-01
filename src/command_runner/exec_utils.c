/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:11:24 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 00:28:15 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command_runner.h>

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		print_err("fork", 0);
		exit(1);
	}
	return (pid);
}

char	*find_path(t_env *envp)
{
	t_env	*node;

	node = search_in_env(envp, "PATH");
	if (!node)
		return (NULL);
	return (node->value);
}

int	is_dir(char *str)
{
	DIR	*ptr;
	int	res;

	if (!str)
		return (0);
	ptr = opendir(str);
	res = !!ptr;
	if (ptr)
		closedir(ptr);
	return (res);
}

int	execute_cmd(char **cmd, t_env *env)
{
	char			**paths;
	char			**tmp;
	t_strbuilder	*sb;

	if (is_dir(cmd[0]))
		return (-88);
	if (check_absolute_path(cmd, env))
		return (-1);
	if (!find_path(env))
		return (-3);
	paths = ft_split(find_path(env), ':');
	tmp = paths;
	if (!paths)
		return (-2);
	while (*tmp)
	{
		sb = stringbuilder();
		sb_append(sb_append(sb_append_free(sb, *tmp), "/"), cmd[0]);
		*tmp = sb->str;
		free(sb);
		if (check_if_executable(cmd, *tmp, paths, env))
			return (-1);
		tmp++;
	}
	return (free_list(paths), -1);
}
