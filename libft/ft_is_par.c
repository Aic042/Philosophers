/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:46:28 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/04 13:15:55 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_pair(int num)
{
	if (num % 2 == 0)
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	printf("1 is pair, 0 is not| num 2 is :%d\n", is_pair(2));
// 	printf("1 is pair, 0 is not| num 7 is :%d\n", is_pair(7));
// 	printf("1 is pair, 0 is not| num 5 is :%d\n", is_pair(5));
// 	printf("1 is pair, 0 is not| num 4 is :%d\n", is_pair(4));
// }