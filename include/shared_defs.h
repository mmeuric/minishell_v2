/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:27:04 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 01:27:06 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_DEFS_H
# define SHARED_DEFS_H

# define DEBUG

# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../src/cmds_minishell/include/global_utils.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <exit.h>

# define BLUE "\033[0;94m"
# define NOCOL "\033[0m"

t_env		*get_envp(t_env *envp);
void		prompt_pwd(void);
extern int	g_signal_status;

#endif
