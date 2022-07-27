/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:46:58 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/27 15:01:26 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"
/*
** La wati-Freebox qui va free correctement promis 
*/
void	freebox(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_detach(data->philo[i].thread);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->eat_check);
	pthread_mutex_destroy(&data->is_snitching);
}

int	check_if_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if ((get_time_difference(data->start_time)
				- data->philo[i].last_meal) > (unsigned int)data->time_to_die)
		{
			pthread_mutex_lock(&data->is_snitching);
			printf("%d %d died\n",
				get_time_difference(data->start_time), i + 1);
			pthread_mutex_unlock(&data->is_snitching);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_nb_eat(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->eat_check);
		if (data->philo[i].nb_eat >= data->nb_eat_max)
			count++;
		i++;
		pthread_mutex_unlock(&data->eat_check);
	}
	if (count != data->nb_philo)
		return (1);
	return (0);
}
