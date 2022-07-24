/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:46:58 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/24 15:32:38 by tschlege         ###   ########lyon.fr   */
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
	}
	pthread_mutex_destroy(&data->is_snitching);
}

int	check_nb_eat(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->nb_philo)
	{
		if (data->philo[i].nb_eat >= data->nb_eat_max)
			count++;
		i++;
	}
	// printf("count %d nb_philo %d\n", count, data->nb_philo);
	if (count != data->nb_philo)
		return (1);
	return (0);
}

void	check_can_eat(t_data *data)
{
	int	i;

	i = 0;
	if (!check_nb_eat(data))
	{
		printf("\n\ntout mangé\n\n");
		freebox(data);
	}
	return ;
}
