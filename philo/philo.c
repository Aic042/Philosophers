	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   philo.c                                            :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2025/05/14 19:37:06 by root              #+#    #+#             */
	/*   Updated: 2025/05/17 17:08:50 by root             ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#include "philo.h"

	int arg_checker(int argc, char **argv)
	{
		if (argc != 5 && argc != 6)
			return (ft_printf("Bad Argc\n"), 0);
		if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL)
			return (ft_printf("Null\n"), 0);
		if(ft_isdigit(argv[1][0]) == 0 || ft_isdigit(argv[2][0]) == 0 || ft_isdigit(argv[3][0]) == 0 || ft_isdigit(argv[4][0]) == 0)
			return (ft_printf("No digit\n"), 0);
		return (ft_printf("Args are all good\n"), 1);
	}

	int fork_getter(char **argv)
	{
		int forks;
		
		forks = ft_atoi(argv[1]);
		forks = forks + 1;
		return (forks);
	}

	int main(int argc, char **argv)
	{
		int forks;
		
		if(!arg_checker(argc, argv))
			exit(1);
		forks = fork_getter(argv);
		ft_printf("forks = %d\n", forks);
		return (write(1, "Done\n", 5), 0);
	}

	//for later, should check if it's better to have an int