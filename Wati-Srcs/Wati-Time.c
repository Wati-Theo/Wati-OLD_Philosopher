/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:59:41 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/20 20:46:16 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"

unsigned int	get_time_difference(struct timeval old_time)
{
	struct timeval	current_time;
	unsigned int	time_i;
	unsigned int	time_j;

	gettimeofday(&current_time, NULL);
	time_i = current_time.tv_sec * (unsigned int)1000 + current_time.tv_usec
		/ 1000;
	time_j = old_time.tv_sec * (unsigned int)1000 + old_time.tv_usec / 1000;
	return (time_i - time_j);
}
