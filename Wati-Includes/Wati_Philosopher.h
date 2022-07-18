/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati_Philosopher.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:45:25 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/18 19:33:40 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATI_PHILOSOPHER_H
# define WATI_PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	t_data		data;
}	t_philo;

typedef struct data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat_max;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_data;

void			check_if_digit(int argc, char *argv[], t_data *data);
int				ft_isdigit(int c);
long long int	ft_atoi(const char *str);
void			init_data(char *argv[], t_data *data);
void			think_philo(t_philo *philo);
#endif
