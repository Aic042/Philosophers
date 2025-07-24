/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:49:03 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/23 23:31:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_pos_int(int num)
{
	if (num < 0)
		return (printf("num is negative\n"), 0);
	else
		return (1);
}

int	arg_checker(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("Bad Argc\n"), 0);
	if (argv[1] == NULL || argv[2] == NULL
		|| argv[3] == NULL || argv[4] == NULL)
		return (printf("Null\n"), 0);
	if (is_str_digit(argv[1]) == 0 || is_str_digit(argv[2]) == 0
		|| is_str_digit(argv[3]) == 0 || is_str_digit(argv[4]) == 0)
		return (printf("No digit\n"), 0);
	if (!check_pos_int(ft_atol(argv[1])) || !check_pos_int(ft_atol(argv[2]))
		|| !check_pos_int(ft_atol(argv[3])) || !check_pos_int(ft_atol(argv[4])))
		return (0);
	if (ft_atol(argv[1]) <= 0)
		return (printf("No philosophers\n"), 0);
	if (ft_atol(argv[3]) == 0 || ft_atol(argv[4]) == 0)
		return (printf("Num is bad\n"), 0);
	if (argc == 6)
		if (!check_pos_int(ft_atol(argv[5])))
			return (0);
	return (1);
}
