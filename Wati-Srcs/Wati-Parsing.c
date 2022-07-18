/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:48:52 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/18 18:50:37 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"	

void	check_if_valid_nb(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648
			|| ft_atoi(argv[i]) < 1)
		{
			printf("Invalid Arg\n");
			return ;
		}
		i++;
	}
	printf("Parsing OK\n");
	init_data(argv, data);
}

void	check_if_digit(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i]))
			{
				printf("Invalid Arg\n");
				return ;
			}
			i++;
		}
		j++;
	}
	check_if_valid_nb(argc, argv, data);
}
