/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:11:02 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 00:28:04 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command_runner.h>

void	handle_dups(t_ast_cmd *sub_tree, int *fd, int fd_num)
{
	close(fd[!fd_num]);
	if (dup2(fd[fd_num], fd_num) == -1)
		(print_err("dup", 0), exit(-1));
	close(fd[fd_num]);
	executor(sub_tree, true);
	exit(get_exit_status());
}

void	exec_pipe(t_ast_binary *tree, bool forked)
{
	int		fd[2];
	pid_t	pids[2];
	int		exit_status;

	pids[0] = 0;
	pids[1] = 0;
	if (pipe(fd) == -1)
		(perror("pipe"), exit(1));
	pids[0] = ft_fork();
	if (!pids[0])
		handle_dups(tree -> left, fd, STDOUT_FILENO);
	pids[1] = ft_fork();
	if (!pids[1])
		handle_dups(tree -> right, fd, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	waitpid(pids[0], &exit_status, 0);
	waitpid(pids[1], &exit_status, 0);
	set_exit_status(WEXITSTATUS(exit_status));
	if (forked)
		exit(get_exit_status());
}

void	exec_or(t_ast_binary *tree, bool forked)
{
	executor((t_ast_cmd *)tree->left, false);
	if (get_exit_status())
		executor((t_ast_cmd *)tree->right, false);
	if (forked)
		exit(get_exit_status());
}

void	exec_and(t_ast_binary *tree, bool forked)
{
	executor((t_ast_cmd *)tree->left, false);
	if (!get_exit_status())
		executor((t_ast_cmd *)tree->right, false);
	if (forked)
		exit(get_exit_status());
}
