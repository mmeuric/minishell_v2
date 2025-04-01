/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:12 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 00:18:42 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H
# include <shared_defs.h>
# include <signal.h>

void	reset_default_sig_handlers(void);
void	install_default_sig_handlers(void);
void	sigint_handler(int sig);
void	heredoc_sigint_handler(int sig);
enum
{
	SET,
	RESET
};
#endif
