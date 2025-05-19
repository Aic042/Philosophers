/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:49:03 by aingunza          #+#    #+#             */
/*   Updated: 2025/05/19 12:49:14 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_checker(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ft_printf("Bad Argc\n"), 0);
	if (argv[1] == NULL || argv[2] == NULL
		|| argv[3] == NULL || argv[4] == NULL)
		return (ft_printf("Null\n"), 0);
	if (is_str_digit(argv[1]) == 0 || is_str_digit(argv[2]) == 0
		|| is_str_digit(argv[3]) == 0 || is_str_digit(argv[4]) == 0)
		return (ft_printf("No digit\n"), 0);
	return (ft_printf("Args are all good\n"), 1);
}
