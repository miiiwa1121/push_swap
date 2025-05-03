/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:00:02 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/03 15:00:04 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_from_b(t_stack *stack_b, int data)
{
	t_node	*temp;
	int		target;
	int		max;
	int		min;
	int		len;

	temp = stack_b->top;
	max = get_max_data(stack_b);
	min = get_min_data(stack_b);
	len = get_len_stack(stack_b);
	if (data > max || data < min)
		return (max);
	target = min;
	while (len > 0)
	{
		if (temp->data < data && temp->data > target)
			target = temp->data;
		temp = temp->next;
		len--;
	}
	return (target);
}

int	get_target_from_a(t_stack *stack_a, int data)
{
	t_node	*temp;
	int		target;
	int		a_max;
	int		a_min;
	int		len_a;

	temp = stack_a->top;
	a_max = get_max_data(stack_a);
	a_min = get_min_data(stack_a);
	len_a = get_len_stack(stack_a);
	if (data > a_max)
		return (a_min);
	if (data < a_min)
		return (a_min);
	target = a_max;
	while (len_a > 0)
	{
		if (temp->data > data && temp->data < target)
			target = temp->data;
		temp = temp->next;
		len_a--;
	}
	return (target);
}

void	sort_reverse(t_stack *stack)//最小の値を一番上に持ってくる
{
	int	min;
	int	min_index;
	int	len;

	min = get_min_data(stack);//stack_aのデータの中で最小の値を取得
	min_index = get_index_from_data(stack, min);//最小の値のインデックスを取得
	len = get_len_stack(stack);//(例：1234の場合、len = 4)
	if (min_index <= len / 2)//最小の値のインデックスがstack_aの長さの半分以下の場合(半分より下は下にシフト、上なら上にシフト、無駄なシフト回数を削減する工夫)
	{	
		while (stack->top->data != min)//stack_aの一番上の値が最小の値ではない間繰り返す
			ra(stack);//stack_aを上から下に1つ回転(例：top→bottomとするとき、1234→2341)
	}
	else
	{
		while (stack->top->data != min)//stack_aの一番上の値が最小の値ではない間繰り返す
			rra(stack);//stack_aを下から1つ回転(例：top→bottomとするとき、2314→4231)
	}
}

bool	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_command	*command;

	if (!pb(stack_a, stack_b))
		return (false);
	if (!pb(stack_a, stack_b))
		return (false);
	while (get_len_stack(stack_a) > 3)
	{
		both_stack_index_init(stack_a, stack_b);
		command = serch_optimal_command_push_to_b(stack_a, stack_b);
		do_command(*command, stack_a, stack_b);
		if (!pb(stack_a, stack_b))
			return (false);
	}
	sort_len_3(stack_a);
	while (get_len_stack(stack_b) > 0)
	{
		both_stack_index_init(stack_a, stack_b);
		command = serch_optimal_command_push_to_a(stack_a, stack_b);
		do_command(*command, stack_a, stack_b);
		if (!pa(stack_a, stack_b))
			return (false);
	}
	sort_reverse(stack_a);
	return (true);
}
