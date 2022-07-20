/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:59:41 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/20 23:22:31 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"

unsigned int	get_time_difference(struct timeval old_time)
{
	struct timeval	current_time;
	unsigned int	time_current;
	unsigned int	time_old;

	gettimeofday(&current_time, NULL);
	time_current = current_time.tv_sec * (unsigned int)1000 + current_time.tv_usec
		/ 1000;
	time_old = old_time.tv_sec * (unsigned int)1000 + old_time.tv_usec / 1000;
	return (time_current - time_old);
}
