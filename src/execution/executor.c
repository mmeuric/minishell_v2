/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:12:49 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/28 15:18:03 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	free_list(char **list)
{
	unsigned int	i;

	i = 0;
	while (list[i])
		i++;
}

void	executor(t_ast_cmd *tree, bool forked)
{
	if (!tree)
	{
		if (forked)
			exit(get_exit_status());
		return ;
	}
	if (tree->type == P_AND)
		exec_and((t_ast_binary *)tree, forked);
	else if (tree->type == P_OR)
		exec_or((t_ast_binary *)tree, forked);
	else if (tree->type == P_PIPE)
		exec_pipe((t_ast_binary *)tree, forked);
	else if (tree->type == P_EXEC)
		exec_exe((t_ast_exec *)tree, forked);
	else if (tree->type == P_REDIR)
		exec_redir((t_ast_redir *)tree, forked);
	else if (tree->type == P_SUBSH)
		exec_subsh((t_ast_subsh *)tree, forked);
}
