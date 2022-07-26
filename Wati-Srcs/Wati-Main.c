/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:45:28 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/26 10:33:34 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("ERR, Nb of ARG\n");
		return (1);
	}
	data.nb_philo = 0;
	data.time_to_die = 0;
	data.time_to_eat = 0;
	data.time_to_sleep = 0;
	data.nb_eat_max = -42;
	if (argc == 6)
		data.nb_eat_max = 0;
	check_if_digit(argc, argv, &data);
}
