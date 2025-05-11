/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:34:55 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/10 18:36:55 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_len_stack(t_stack *stack)//stackの長さを取得
{
	int		len;
	t_node	*temp;

	if (is_empty(stack))
		return (0);
	len = 1;
	temp = stack->top;
	while (temp->next != stack->top)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	get_max_data(t_stack *stack)//stackの中で最大の値を取得
{
	t_node	*temp;
	int		max;
	int		len;

	temp = stack->top;//tempにstackのtopのアドレスを代入
	max = temp->data;//maxにtempのdataを代入
	len = get_len_stack(stack);
	while (len > 0)//stackの長さが0より大きい間繰り返す
	{
		if (temp->data > max)//tempのdataがmaxより大きい場合
			max = temp->data;//maxにtempのdataを代入
		temp = temp->next;//tempにtempのnextを代入
		len--;
	}
	return (max);
}

int	get_min_data(t_stack *stack)//stackの中で最小の値を取得
{
	t_node	*temp;
	int		min;
	int		len;

	temp = stack->top;
	min = temp->data;
	len = get_len_stack(stack);
	while (len > 0)
	{
		if (temp->data < min)//tempのdataがminより小さい場合
			min = temp->data;
		temp = temp->next;
		len--;
	}
	return (min);
}

int	get_index_from_data(t_stack *stack, int data)//dataのindexを取得
{
	t_node	*temp;
	int		index;

	temp = stack->top;
	index = 0;
	while (temp->next != stack->top)
	{
		if (temp->data == data)
			return (index);
		temp = temp->next;
		index++;
	}
	if (temp->data == data)
		return (index);
	return (-1);
}

// void	print_stack(t_stack *stack, char *name)//stackの中身を表示
// {
// 	t_node	*temp;

// 	if (is_empty(stack))
// 	{
// 		ft_printf("%s is empty\n", name);
// 		return ;
// 	}
// 	temp = stack->top;
// 	ft_printf("%s: ", name);
// 	while (temp->next != stack->top)
// 	{
// 		ft_printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// 	ft_printf("%d\n", temp->data);
// }
