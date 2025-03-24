/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:23:56 by jtakahas          #+#    #+#             */
/*   Updated: 2025/03/24 00:57:43 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp->next != stack->top)
	{
		if (temp->data > temp->next->data)
			return (false);
		temp = temp->next;
	}
	return (true);
}

bool	is_empty(t_stack *stack)//stackが空かどうかを判定
{
	return (stack->top == NULL);//topがNULLの場合はTrueを返す
}
