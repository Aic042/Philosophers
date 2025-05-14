/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:37:06 by root              #+#    #+#             */
/*   Updated: 2025/05/14 20:16:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 5 && argc != 6)
		return (write(1, "Bad Argc", 9));
	return (write(1, "Done\n", 5), 0);
}

void arg_checker(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (write(1, "Bad Argc", 9));
	return (write(1, "Done\n", 5), 0);
}

//for later, should check if it's better to have an int