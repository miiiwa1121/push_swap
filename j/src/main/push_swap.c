/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:19:40 by jtakahas          #+#    #+#             */
/*   Updated: 2025/04/08 18:45:10 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_len_3(t_stack *stack)//stack_aのデータが3つの場合のソート
{
	int	max_data;

	max_data = get_max_data(stack);//stack_aのデータの中で最大の値を取得
	if (max_data == stack->top->data)//最大の値が一番上の場合
		ra(stack);//スタック a を上から1つ回転
	else if (max_data == stack->top->next->data)//最大の値が2番目の場合
		rra(stack);//スタック a を下から1つ回転
	if (stack->top->data > stack->top->next->data)//一番上の値が2番目の値より大きい場合
		sa(stack);//スタック a の上から2つの要素を交換
}

// 123 132 213 231 312 321
// 312 321 321 312 312 321
// 321 321 321 321 321 321

void	sort_len_4(t_stack *stack_a, t_stack *stack_b)
{
	sort_reverse(stack_a);//最小の値を一番上に持ってくる
	if (!pb(stack_a, stack_b))//stack_aの一番上の値をstack_bに移動(最小の値をstack_bに移動)、エラーの場合はfalseを返す
	{
		free_stack(stack_a);//stack_aを解放
		free_stack(stack_b);//stack_bを解放
		error_print_exit();//エラー文を出力してプログラムを即終了
	}
	sort_len_3(stack_a);//最小の値を除いた3つの値をソート
	if (!pa(stack_a, stack_b))//stack_bの一番上の値をstack_aに移動(stack_bに移動した最小の値を戻す)、エラーの場合はfalseを返す
	{
		free_stack(stack_a);//stack_aを解放
		free_stack(stack_b);//stack_bを解放
		error_print_exit();//エラー文を出力してプログラムを即終了
	}
}

// 1234 1243 1324 1342 1423 1432 2134 2143 2314 2341 2413 2431 3124 3142 3214 3241 3412 3421 4123 4132 4213 4231 4312 4321
// 2341 2431 3241 3421 4231 4321 3421 4321 4231 2341 3241 2431 2431 4231 4321 3241 2341 3421 2341 3241 1342 4231 2431 4321
// 2341 2431 3241 3421 4231 4321 ・・・  
// 4231 4321 4321 4231 4231 4321 ・・・
// 4321 4321 4321 4321 4321 4321 ・・・ 


void	push_swap(int len, t_stack *stack_a, t_stack *stack_b)//ソートする関数	
{
	if (is_sorted(stack_a))//stack_aがソートされている場合		//----------------------koreyattenai
		return ;
	if (len == 2)//stack_aのデータが2つの場合
		sa(stack_a);
	else if (len == 3)//stack_aのデータが3つの場合
		sort_len_3(stack_a);
	else if (len == 4)//stack_aのデータが4つの場合
		sort_len_4(stack_a, stack_b);
	else//stack_aのデータが5つ以上の場合
	{
		//----------------------kokomade
		if (!sort(stack_a, stack_b))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			error_print_exit();
		}
	}
}
