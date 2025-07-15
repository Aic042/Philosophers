/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:40:27 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/15 11:41:00 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

int	is_str_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str == '+' || *str == '-')
	{
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		i;
	int		final;

	if (!str)
		return (0);
	result = 0;
	i = 0;
	final = 0;
	if (str[0] == '+')
		i = 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '-')
			return (0);
		result *= 10;
		result += str[i] - 48;
		if (result > INT_MAX)
			return (0);
		i++;
	}
	final = result;
	return (final);
}
