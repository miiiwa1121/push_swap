/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:35:09 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/11 15:48:31 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

bool	push(t_stack *stack, int data)//stackのtopにデータを追加//stackに新しいノードを追加
{
	t_node		*new_node;
	t_command	command;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (false);
	// command = command_init();//commandの初期化
	new_node->data = data;
	new_node->command = command_init();//new_nodeのcommandを初期化
	if (is_empty(stack))
	{
		new_node->prev = new_node;//全ての矢印が自分を指す
		new_node->next = new_node;
	}
	else
	{
		new_node->next = stack->top;//新しいノードを追加しても良い感じに双方向循環になるように調整
		new_node->prev = stack->top->prev;
		stack->top->prev->next = new_node;
		stack->top->prev = new_node;
	}
	stack->top = new_node;
	return (true);
}
// top
// A   B   C   D   E
// <--------------->

bool	push_to(t_stack *from, t_stack *to, char c)//fromのtopの値をtoのtopに移動//スタックから一部のノードを取り出す
{
	int		data;
	t_node	*temp;

	if (is_empty(from))
		return (false);
	data = from->top->data;//fromのtopのデータを取得
	temp = from->top;
	if (from->top->next == from->top)//アドレスが同じ場合
		from->top = NULL;
	else
	{
		from->top->prev->next = from->top->next;//一部ノードを取り出しても良い感じに双方向循環になるように調整
		from->top->next->prev = from->top->prev;
		from->top = from->top->next;
	}
	free(temp);
	if (push(to, data))
	{
		ft_printf("p%c\n", c);
		return (true);
	}
	return (false);
}

bool	pa(t_stack *stack_a, t_stack *stack_b)//stack_bの一番上の値をstack_aに移動
{
	return (push_to(stack_b, stack_a, 'a'));
}

bool	pb(t_stack *stack_a, t_stack *stack_b)//stack_aの一番上の値をstack_bに移動
{
	return (push_to(stack_a, stack_b, 'b'));
}
