/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:30:24 by jtakahas          #+#    #+#             */
/*   Updated: 2025/05/03 14:46:49 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_abs(int nbr)
{
	if (nbr == INT_MIN)
		return (0);
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}
