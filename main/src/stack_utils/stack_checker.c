/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:34:49 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/05 13:34:51 by mtsubasa         ###   ########.fr       */
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
