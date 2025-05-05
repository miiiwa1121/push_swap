# push_swap

## 目次
- [構成](#構成)
- [課題条件](#課題条件)
- [概要](#概要)
- [実行](#ビルドとクリーンコマンド)
- [使用関数](#使用関数)
- [用語](#用語)
- [ビット操作](#ビット操作)
- [質問](#質問)
- [メモ](#メモ)


## 使用操作一覧
```
sa: スタック a の上から2つの要素を交換します。
sb: スタック b の上から2つの要素を交換します。
ss: sa と sb を同時に実行します。
pa: スタック b の上の要素をスタック a に移動させます。
pb: スタック a の上の要素をスタック b に移動させます。
ra: スタック a を回転させます（上の要素を下に移動させる）。
rb: スタック b を回転させます。
rr: ra と rb を同時に実行します。
rra: スタック a を逆回転させます（下の要素を上に移動させる）。
rrb: スタック b を逆回転させます。
rrr: rra と rrb を同時に実行します。
```

## 利用したビジュアライザー
https://github.com/o-reo/push_swap_visualizer

## 関数
> ### command_utils
#### *command_utils.c*
- `void	do_command(t_command command, t_stack *stack_a, t_stack *stack_b)` 
- `t_command	calculation_command(int a_index, int b_index, int a_len, int b_len)`
- `static int	get_smallest(int ra_rb, int rra_rrb, int ra_rrb, int rra_rb)`
- `static int	rotate_count_with_ab(int a_count, int b_count)`
#### *command_utils2.c*
- `void	command_set_rrarb(t_command *command, int rra_count, int rb_count)`
- `void	command_set_rarrb(t_command *command, int ra_count, int rrb_count)`
- `void	commnad_set_rrarrb(t_command *command, int rra_count, int rrb_count)`
- `void	commnad_set_rarb(t_command *command, int ra_count, int rb_count)`
#### *command_utils3.c*
- `void	register_command_push_a(t_stack *stack_a, t_stack *stack_b, int b_data,	t_command *command)`
- `void	register_command_push_b(t_stack *stack_a, t_stack *stack_b, int a_data, t_command *command)`
- `t_command	*serch_optimal_command_push_to_a(t_stack *stack_a, t_stack *stack_b)`
- `t_command	*serch_optimal_command_push_to_b(t_stack *stack_a, t_stack *stack_b)`
> ### main
#### *main.c*
- `static bool	is_duplicate(int *array, int len, int data)`
- `int	data_set_to_stack(int len_data, t_stack *stack_a, int *data)`
- `static void	data_set_to_array(int len_data, char **av, int *data)`
- `int	main(int ac, char **av)`
#### *push_swap.c*
- `void	sort_len_3(t_stack *stack)`
- `void	sort_len_4(t_stack *stack_a, t_stack *stack_b)`
- `void	push_swap(int len, t_stack *stack_a, t_stack *stack_b)`
#### *sort.c*
- `int	get_target_from_b(t_stack *stack_b, int data)`
- `int	get_target_from_a(t_stack *stack_a, int data)`
- `void	sort_reverse(t_stack *stack)//最小の値を一番上に持ってくる`
- `bool	sort(t_stack *stack_a, t_stack *stack_b)`
> ### operations
#### *push.c*
- `bool	push(t_stack *stack, int data)//stackのtopにデータを追加`
- `bool	push_to(t_stack *from, t_stack *to, char c)`
- `bool	pa(t_stack *stack_a, t_stack *stack_b)`
- `bool	pb(t_stack *stack_a, t_stack *stack_b)`
#### *reverse_rotate.c*
- `void	reverse_rotate(t_stack *stack, char c)`
- `void	rra(t_stack *stack_a)`
- `void	rrb(t_stack *stack_b)`
- `void	rrr(t_stack *stack_a, t_stack *stack_b)`
#### *rotate.c*
- `void	rotate(t_stack *stack, char c)`
- `void	ra(t_stack *stack_a)`
- `void	rb(t_stack *stack_b)`
- `void	rr(t_stack *stack_a, t_stack *stack_b)`
#### *swap.c*
- `void	swap(t_stack *stack, char c)`
- `void	sa(t_stack *stack_a)`
- `void	sb(t_stack *stack_b)`
- `void	ss(t_stack *stack_a, t_stack *stack_b)`
> ### stack_utils
#### *stack_checker.c*
- `bool	is_sorted(t_stack *stack)`
- `bool	is_empty(t_stack *stack)`
#### *stack_info.c*
- `int	get_len_stack(t_stack *stack)`
- `int	get_max_data(t_stack *stack)`
- `int	get_min_data(t_stack *stack)`
- `int	get_index_from_data(t_stack *stack, int data)`
- `void	print_stack(t_stack *stack, char *name)`
#### *stack_management.c*
- `void	stack_init(t_stack *stack_a, t_stack *stack_b)`
- `void	both_stack_index_init(t_stack *stack_a, t_stack *stack_b)`
- `void	stack_index_init(t_stack *stack)`
- `void	free_stack(t_stack *stack)`
> ### utils
#### *error.c*
- `void	error_print(void)`
- `void	error_print_exit(void)`
#### *push_swap_atoi.c*
- `static char	*pass_space(char *str)//空白をスキップ`
- `static char	*check_plus_minus(char *str, int *sign)`
- `static bool	is_int(long long num, int sign)`
- `bool	push_swap_atoi(char *str, int *data)`
> ### libft
- `int	ft_printf(const char *format, ...)`
- `int	ft_abs(int nbr)`
- `int	ft_isdigit(int c)`
- `int	ft_isspace(int nbr)`
