/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:03:01 by jtakahas          #+#    #+#             */
/*   Updated: 2025/03/24 01:21:17 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_duplicate(int *array, int len, int data)//重複がある場合はtrueを返す
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (array[index] == data)//重複がある場合
			return (true);
		index++;
	}
	return (false);//重複がない場合
}

int	data_set_to_stack(int len_data, t_stack *stack_a, int *data)
{
	int	index;

	index = 0;
	while (index < len_data)
	{
		if (!push(stack_a, data[len_data - index - 1]))//stack_aにデータを配列のうしろから順に格納//errorの場合はfalseを返す
		{
			free_stack(stack_a);//stack_aを解放
			free(data);
			error_print_exit();//エラー文を出力してプログラムを即終了
		}
		index++;
	}
	return (0);
}

static void	data_set_to_array(int len_data, char **av, int *data)//入力されたデータを配列に格納
{
	int	num_data;
	int	index;

	index = 0;
	while (index < len_data)
	{
		if (!push_swap_atoi(av[index], &num_data)//文字列を数値に変換し、エラーの場合はfalseを返す
			|| is_duplicate(data, index, num_data))//重複がある場合はtrueを返す//
		{
			free(data);//重複があって、数値に変換できない場合は配列を解放
			error_print_exit();//エラー文を出力してプログラムを即終了
		}
		data[index] = num_data;//数値を配列に格納
		index++;
	}
}
// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q push_swap");
// }

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*data;//入力されたデータを格納する配列
	int		len_data;//入力されたデータの数

	if (ac <= 1)//引数がない場合
		return (0);
	len_data = ac - 1;
	data = malloc(sizeof(int) * (len_data));//入力されたデータを格納する配列を動的に確保
	if (data == NULL)
		error_print_exit();//エラー文を出力してプログラムを即終了
	data_set_to_array(len_data, ++av, data);//入力されたデータを配列に格納//++avは値を増加した後に関数に渡す
	stack_init(&stack_a, &stack_b);//stack_aとstack_bを初期化
	data_set_to_stack(len_data, &stack_a, data);//stack_aにデータを格納
// ----------------------------------------------------------------------------------------------------------------ここまで終わった
	free(data);
	if (len_data != 1)//データが1つの場合は何もしない
		push_swap(len_data, &stack_a, &stack_b);//ソート処理へ
	free_stack(&stack_a);//stack_aを解放
	free_stack(&stack_b);//stack_bを解放
	return (0);
}
