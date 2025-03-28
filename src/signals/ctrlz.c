/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrlz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:37 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/28 15:07:47 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

void	handler_sigtstp(int sig)
{
	(void)sig;
}

void	sigquit_handler(int sig)
{
	(void)sig;
}
