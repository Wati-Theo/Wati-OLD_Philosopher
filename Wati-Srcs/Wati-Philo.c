/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:27:09 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/19 23:08:09 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"

void	snitching(t_philo *philo, int choice)
{

	pthread_mutex_lock(&philo->data->is_snitching);
	if (choice == 1)
		printf("timestamp_in_ms %d is thinking\n", philo->id);
	else if (choice == 2)
		printf("timestamp_in_ms %d has taken a fork\n", philo->id);
	else if (choice == 3)
		printf("timestamp_in_ms %d is eating\n", philo->id);
	else if (choice == 4)
		printf("timestamp_in_ms %d is sleeping\n", philo->id);
	else if (choice == 5)
		printf("timestamp_in_ms %d died\n", philo->id);
	pthread_mutex_unlock(&philo->data->is_snitching);
}

void	*eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]) && 
		pthread_mutex_lock(&philo->data->forks[philo->id]);
	snitching(philo, 2);
	snitching(philo, 3);
	usleep(200);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]) && 
		pthread_mutex_unlock(&philo->data->forks[philo->id]);
	return (think_philo(philo));
}

void	*think_philo(void *arg)
{
	t_philo		*philo;

	philo = arg;
	snitching(philo, 1);
	eat_philo(philo);
	eat_philo(philo);
	return (eat_philo(philo));
}
