/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:35:23 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/11 16:34:01 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	swap(t_stack *stack, char c)//上の2つの要素を入れ替える
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (is_empty(stack) || stack->top->next == stack->top)//stackが空の場合や要素が1つしかない場合は何もしない
		return ;
	first = stack->top;//firstにstackのtopを代入
	second = stack->top->next;//secondにfirstのnextを代入
	temp = first->data;//tempにfirstのdataを代入
	first->data = second->data;//firstのdataにsecondのdataを代入
	second->data = temp;//secondのdataにtempを代入
	ft_printf("s%c\n", c);
}

void	sa(t_stack *stack_a)
{
	swap(stack_a, 'a');
}

void	sb(t_stack *stack_b)
{
	swap(stack_b, 'b');
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
}
