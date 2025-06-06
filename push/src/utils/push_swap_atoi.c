/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:33:58 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/06 00:53:17 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*pass_space(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static char	*check_plus_minus(char *str, int *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static bool	is_int(long long num, int sign)
{
	if (sign == 1 && num > __INT_MAX__)
		return (false);
	if (sign == -1 && num * -1 < INT_MIN)
		return (false);
	return (true);
}

bool	push_swap_atoi(char *str, int *data)
{
	int			sign;
	long long	ans;

	sign = 1;
	ans = 0;
	str = pass_space(str);
	str = check_plus_minus(str, &sign);
	if (*str == '\0' || str == NULL)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		ans = (*str - '0') + (ans * 10);
		if (!is_int(ans, sign))
			return (false);
		str++;
	}
	*data = ans * sign;
	return (true);
}
