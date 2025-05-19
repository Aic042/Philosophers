/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:52:32 by aingunza          #+#    #+#             */
/*   Updated: 2025/05/19 12:29:41 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_malloc_checker(void *whatever, int signal)
{
	if (!whatever)
		perror("Failed memory allocation");
	if (signal == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	else
		ft_printf("malloc checker is not exiting. Signal is 1 to exit.");
}
