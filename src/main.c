/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:55:32 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/28 16:12:02 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <executor.h>
#include <exit.h>
#include <globals.h>
#include <lexer.h>
#include <parser.h>
#include <signals.h>
#include <termios.h>

int		g_signal_status;

void	prompt_pwd(void)
{
	ft_putstr_fd("" BLUE, 1);
	ft_putstr_fd(pwd_cmd(NULL), 1);
	ft_putendl_fd("" NOCOL "", 1);
}

void	tty_attr(struct termios *attrs, int action)
{
	if (action == ATTR_GET)
	{
		tcgetattr(STDIN_FILENO, &attrs[0]);
		tcgetattr(STDOUT_FILENO, &attrs[1]);
		tcgetattr(STDERR_FILENO, &attrs[2]);
	}
	else if (action == ATTR_SET)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &attrs[0]);
		tcsetattr(STDOUT_FILENO, TCSANOW, &attrs[1]);
		tcsetattr(STDERR_FILENO, TCSANOW, &attrs[2]);
	}
	else if (action == ATTR_CHG)
	{
		attrs[0].c_lflag &= ~ECHOCTL;
		attrs[1].c_lflag &= ~ECHOCTL;
		attrs[2].c_lflag &= ~ECHOCTL;
		tty_attr(attrs, ATTR_SET);
	}
}

void	initialize_shell(char **envp, struct termios *attrs, ...)
{
	char	*tmp;

	create_env(envp);
	tmp = getcwd(NULL, 0);
	rl_catch_signals = false;
	pwd_cmd(tmp);
	free(tmp);
	install_default_sig_handlers();
	tty_attr(attrs, ATTR_GET);
	tty_attr(attrs, ATTR_CHG);
}

bool	parse_and_execute(char *command_line)
{
	t_token		*tokens;
	t_ast_cmd	*ast;

	if (!command_line)
	{
		ft_putendl_fd("exit", 1);
		return (free(command_line), true);
	}
	if (ft_strcmp(command_line, "exit") == 0)
	{
		return (free(command_line), true);
	}
	lexer(command_line, &tokens);
	if (parser(tokens, &ast))
		executor(ast, false);
	else
	{
		dup2(2, 0);
		g_signal_status = 0;
	}
	if (*command_line)
	{
		add_history(command_line);
	}
	return (free_ast(ast), free(command_line), false);
}

int	main(int _, char **__, char **envp)
{
	char			*command_line;
	struct termios	attrs[3];

	initialize_shell(envp, attrs, _, __);
	if (signal(SIGTSTP, handler_sigtstp) == SIG_ERR)
	{
		perror("Erreur lors de l'attachement du gestionnaire de signal");
		exit(1);
	}
	while (true)
	{
		if (g_signal_status != 88)
			prompt_pwd();
		command_line = readline("💻 ");
		if (parse_and_execute(command_line))
			break ;
		g_signal_status = 0;
		tty_attr(attrs, ATTR_SET);
	}
	ft_free_all();
	exit(get_exit_status());
}
