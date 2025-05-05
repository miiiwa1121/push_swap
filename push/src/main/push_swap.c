/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:59:45 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/06 00:54:32 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_len_3(t_stack *stack)
{
	int	max_data;

	max_data = get_max_data(stack);
	if (max_data == stack->top->data)
		ra(stack);
	else if (max_data == stack->top->next->data)
		rra(stack);
	if (stack->top->data > stack->top->next->data)
		sa(stack);
}

void	sort_len_4(t_stack *stack_a, t_stack *stack_b)
{
	sort_reverse(stack_a);
	if (!pb(stack_a, stack_b))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		error_print_exit();
	}
	sort_len_3(stack_a);
	if (!pa(stack_a, stack_b))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		error_print_exit();
	}
}

void	push_swap(int len, t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_len_3(stack_a);
	else if (len == 4)
		sort_len_4(stack_a, stack_b);
	else
	{
		if (!sort(stack_a, stack_b))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			error_print_exit();
		}
	}
}
