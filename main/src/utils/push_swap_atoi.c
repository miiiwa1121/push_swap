/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:33:58 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/05 13:34:00 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*pass_space(char *str)//空白をスキップ
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static char	*check_plus_minus(char *str, int *sign)//符号を取得
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
	if (sign == 1 && num > __INT_MAX__)//intの最大値を超える場合
		return (false);
	if (sign == -1 && num * -1 < INT_MIN)//intの最小値を超える場合
		return (false);
	return (true);
}

bool	push_swap_atoi(char *str, int *data)//文字列を数値に変換し、エラーの場合はfalseを返す
{
	int			sign;
	long long	ans;

	sign = 1;
	ans = 0;
	str = pass_space(str);//空白をスキップ
	str = check_plus_minus(str, &sign);//符号を取得
	if (*str == '\0' || str == NULL)//文字列が空の場合はfalseを返す
		return (false);
	while (*str)//文字列の最後まで繰り返す
	{
		if (!ft_isdigit(*str))//数字でない場合(asciiで48~57が数字)
			return (false);
		ans = (*str - '0') + (ans * 10);//数値に変換
		if (!is_int(ans, sign))//intの範囲外の場合
			return (false);
		str++;
	}
	*data = ans * sign;
	return (true);
}
