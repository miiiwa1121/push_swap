/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:39:52 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/06 00:41:22 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_duplicate(int *array, int len, int data)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (array[index] == data)
			return (true);
		index++;
	}
	return (false);
}

int	data_set_to_stack(int len_data, t_stack *stack_a, int *data)
{
	int	index;

	index = 0;
	while (index < len_data)
	{
		if (!push(stack_a, data[len_data - index - 1]))
		{
			free_stack(stack_a);
			free(data);
			error_print_exit();
		}
		index++;
	}
	return (0);
}

static void	data_set_to_array(int len_data, char **av, int *data)
{
	int	num_data;
	int	index;

	index = 0;
	while (index < len_data)
	{
		if (!push_swap_atoi(av[index], &num_data)
			|| is_duplicate(data, index, num_data))
		{
			free(data);
			error_print_exit();
		}
		data[index] = num_data;
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
	int		*data;
	int		len_data;

	if (ac <= 1)
		return (0);
	len_data = ac - 1;
	data = malloc(sizeof(int) * (len_data));
	if (data == NULL)
		error_print_exit();
	data_set_to_array(len_data, ++av, data);
	stack_init(&stack_a, &stack_b);
	data_set_to_stack(len_data, &stack_a, data);
	free(data);
	if (len_data != 1)
		push_swap(len_data, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
