/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:31:35 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/25 14:55:16 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H
# include <globals.h>
# include <signal.h>

void	reset_default_sig_handlers(void);
void	install_default_sig_handlers(void);
void	sigint_handler(int sig);
void	heredoc_sigint_handler(int sig);
void	handler_SIGTSTP(int sig);
void	sigquit_handler(int sig);
enum
{
	SET,
	RESET
};
#endif
