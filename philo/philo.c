/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:37:06 by root              #+#    #+#             */
/*   Updated: 2025/05/17 11:18:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	arg_checker(argc, argv);
	return (write(1, "Done\n", 5), 0);
}

void arg_checker(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (write(1, "Bad Argc\n", 10));
	return (ft_printf("Args are all good"), 0);
}

//for later, should check if it's better to have an int