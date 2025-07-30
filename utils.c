/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:40:27 by aingunza          #+#    #+#             */
/*   Updated: 2025/07/19 14:34:30 by aingunza         ###   ########.fr       */
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

// int	ft_isspace(int c)
// {
// 	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
// 		return (1);
// 	return (0);
// }

long	ft_atol(const char *s)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (res > INT_MAX / 10
			|| (res == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
			return (0);
		res = res * 10 + (s[i++] - '0');
	}
	return (sign * res);
}

void	print_status(t_philo *p, char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&p->config->print);
	if (get_exit(p->config))
	{
		pthread_mutex_unlock(&p->config->print);
		return ;
	}
	timestamp = get_time_ms() - p->config->start_time;
	printf("%ld %d %s\n", timestamp, p->id, msg);
	pthread_mutex_unlock(&p->config->print);
}
