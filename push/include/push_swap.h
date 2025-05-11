/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:49:15 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/05/11 19:29:16 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define RA_RB 1
# define RRA_RRB 2
# define RA_RRB 3
# define RRA_RB 4

typedef struct s_command
{
	int		all;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
}	t_command;

typedef struct s_node
{
	int				data;
	int				index;
	t_command		command;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

void		stack_init(t_stack *stack, t_stack *stack_b);
void		stack_index_init(t_stack *stack);
void		both_stack_index_init(t_stack *stack_a, t_stack *stack_b);
void		free_stack(t_stack *stack);
bool		is_empty(t_stack *stack);
bool		is_sorted(t_stack *stack);
int			get_len_stack(t_stack *stack);
int			get_max_data(t_stack *stack);
int			get_min_data(t_stack *stack);
int			get_index_from_data(t_stack *stack, int data);
void		print_stack(t_stack *stack, char *name);
void		push_swap(int len, t_stack *stack_a, t_stack *stack_b);
void		swap(t_stack *stack, char c);
void		rotate(t_stack *stack, char c);
void		reverse_rotate(t_stack *stack, char c);
bool		push(t_stack *stack, int data);
bool		push_to(t_stack *stack_a, t_stack *stack_b, char c);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack_a, t_stack *stack_b);
bool		pa(t_stack *stack_a, t_stack *stack_b);
bool		pb(t_stack *stack_a, t_stack *stack_b);
void		error_print(void);
void		error_print_exit(void);
bool		push_swap_atoi(char *str, int *num);
void		sort_len_3(t_stack *stack);
bool		sort(t_stack *stack_a, t_stack *stack_b);
void		sort_reverse(t_stack *stack);
int			get_target_from_b(t_stack *stack_b, int data);
int			get_target_from_a(t_stack *stack_a, int data);
t_command	calculation_command(int a_index, int b_index, int a_len, int b_len);
void		do_command(t_command command, t_stack *stack_a, t_stack *stack_b);
t_command	command_init(void);
void		commnad_set_rarb(t_command *command, int ra_count, int rb_count);
void		commnad_set_rrarrb(t_command *command,
				int rra_count,
				int rrb_count);
void		command_set_rarrb(t_command *command, int ra_count, int rb_count);
void		command_set_rrarb(t_command *command, int rra_count, int rb_count);
void		register_command_push_a(t_stack *stack_a,
				t_stack *stack_b,
				int b_data,
				t_command *command);
void		register_command_push_b(t_stack *stack_a,
				t_stack *stack_b,
				int a_data,
				t_command *command);
t_command	*serch_optimal_command_push_to_a(t_stack *stack_a,
				t_stack *stack_b);
t_command	*serch_optimal_command_push_to_b(t_stack *stack_a,
				t_stack *stack_b);

#endif