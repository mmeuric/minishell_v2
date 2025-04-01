/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_resolver.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:30:17 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 00:34:49 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_RESOLVER_H
# define VARIABLE_RESOLVER_H

# include "shared_defs.h"
# include "tokenizer.h"
# include "construct_str.h"

# define DIGIT 132

typedef struct s_str
{
	char			*str;
	bool			wild_card;
	struct s_str	*next;
}					t_str;

char				**expand_args(t_token *argv_tok);
char				*expand_env(char *to_expand, bool in_quote,
						bool ignore_env);
void				expand_nosp_arg(t_token *sub_tok, t_str **lst,
						bool ignore_env);
/* expander utils */
unsigned int		get_chunk_len(char *ptr, char *sp);
void				ghost_char_action(char *str);

/* String list utils */
void				ft_stradd_back(t_str **lst, t_str *new);
t_str				*new_str(char *str, bool to_expand);
void				free_strnode(t_str *node);
void				p_str_node(void *s);
void				ft_striter(t_str *lst, void (*f)(void *));
int					ft_strlstlen(t_str *lst);
t_str				*ft_strlast(t_str *lst);
void				ft_join_last(t_str **lst, char *str, bool to_expand);
int					split_len(char **lst);
char				**consume_argv(t_str *lst);
void				add_str_lst(char *str, t_str **lst, bool join_to_last,
						t_token *tok);

#endif
