/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:26:00 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 02:04:18 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_UTILS_H
# define GLOBAL_UTILS_H
# ifdef FROM_SUBMODULE
#  include <shell_cmds.h>
#  include <ft_lsts.h>
# else
#  include "../include/shell_cmds.h"
#  include "../include/ft_lsts.h"
# endif
# include <shared_defs.h>
# include <libft.h>
# include <stdbool.h>
# include <stdlib.h>
# include <construct_str.h>

int		export(int argc, char **argv, t_env **env);
int		env_(t_env **env);
int		unset(int argc, char **args, t_env **env);
int		my_exit(int argc, char *arg);
int		check_builtins(int argc, char *command, char **args);
char	*pwd_cmd(char *str);
char	*trim_path(char *pwd);
t_env	*search_in_env(t_env *env, char *key);
t_env	**get_envp_internal(t_env *envp);
t_env	*get_envp(t_env *envp);
char	**consume_env(t_env *env);
char	*get_env_value(char *var);
void	create_env(char **envp);
char	*get_key(char *line);
char	*get_value(char *line);
void	set_env_value(char *key, char *value, int equal_sign);
void	append_to_env(t_env **env, char *key, char *value, int equal_sign);
void	edit_env(t_env *node, char *value, int equal_sign);
int		is_concate(char *str);
t_env	*get_envp(t_env *envp);
t_env	**get_envp_internal(t_env *envp);
void	log_last_command(char *value);
int		validate_arg(char *arg);
char	*contruct_path(char **path);
#endif
