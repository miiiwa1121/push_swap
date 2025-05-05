/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:34:59 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/05 13:35:00 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	stack_init(t_stack *stack_a, t_stack *stack_b)//stackの初期化
{
	stack_a->top = NULL;//topをNULLにする//ポインタがどの有効なメモリアドレスも指していないことを示す
	stack_b->top = NULL;//topをNULLにする
}

void	both_stack_index_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_index_init(stack_a);
	stack_index_init(stack_b);
}

void	stack_index_init(t_stack *stack)
{
	t_node	*temp;
	int		index;

	temp = stack->top;
	index = 0;
	while (temp->next != stack->top)
	{
		temp->index = index;
		temp = temp->next;
		index++;
	}
	temp->index = index;
}

void	free_stack(t_stack *stack)//stackの解放
{
	t_node	*temp;
	t_node	*next;

	if (is_empty(stack))//stackが空の場合は何もしない
		return ;//関数を終了し何も返さない
	temp = stack->top;//tempにstackのtopを代入
	while (temp->next != stack->top)//tempのnextがtopでない間繰り返す(最初のポインタが指していたところまで循環しきるまで)//ポインタの指す先を一つずつずらしながら一つ一つ解放していく必要がある。
	{
		next = temp->next;//nextにtempのnextを代入
		free(temp);//tempを解放
		temp = next;//tempにnextを代入
	}
	free(temp);
	stack->top = NULL;//stackのtopをNULLにする
}
