/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:35:14 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/11 16:05:12 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack, char c)//stackを逆回転させる//stackのtopを一つ前にずらす
{
	if (is_empty(stack) || stack->top->next == stack->top)
		return ;
	stack->top = stack->top->prev;
	ft_printf("rr%c\n", c);
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a, 'a');
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b, 'b');
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 'a');
	reverse_rotate(stack_b, 'b');
}
