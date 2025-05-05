# push_swap

## 目次
- [構成](#構成)
- [概要](#概要)
- [コマンド](#コマンド)
- [構造体](#構造体)
- [ビジュアライザー](#ビジュアライザー)
- [関数](#関数)
- [参照](#参照)

## 構成
```
.
├── Makefile
├── all_libft
│   ├── Makefile
│   ├── include
│   │   ├── ft_printf.h
│   │   ├── get_next_line.h
│   │   └── libft.h
│   └── src
│       ├── ft_printf
│       ├── gnl
│       └── libft
├── include
│   └── push_swap.h
└── src
    ├── command_utils
    │   ├── command_utils.c
    │   ├── command_utils2.c
    │   └── command_utils3.c
    ├── main
    │   ├── main.c
    │   ├── push_swap.c
    │   └── sort.c
    ├── operations
    │   ├── push.c
    │   ├── reverse_rotate.c
    │   ├── rotate.c
    │   └── swap.c
    ├── stack_utils
    │   ├── stack_checker.c
    │   ├── stack_info.c
    │   └── stack_management.c
    └── utils
        ├── error.c
        └── push_swap_atoi.c
```

## 概要
sortするプログラムを作成する、とにかく数字を並べるのです

## 制約
1. 2つのスタックStack_a, Stack_bのみを使用してソートしなくてはならない
2. スタック間の操作は指定の11個のコマンドしか使用してはならない
3. グローバル変数は使用してはならない
4. 使用してよい標準関数は(read, write, malloc, free, exit)の5つのみ
5. 入力値エラーや、メモリ確保のエラーなど、エラーハンドリングも適切に実装しなくてはならない

## コマンド
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

## 構造体
### スタック
**以下の条件を揃えたスタックを利用する**
- 双方向連結（前後に参照できる）
- 循環（先頭と末尾が繋がっている）
```
typedef struct s_node
{
	int				data;
	int				index;
	t_command		command;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
```
```
typedef struct s_stack
{
	t_node	*head;
}	t_stack;
```
### コマンドをカウントし保存しておくための構造体
- プッシュが実行される際に数字ごとに最適なコマンドを保存しておく必要がある。
```
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
```

## 手順
### 下処理
1. **コマンドライン引数を配列に格納する**
2. **スタックを初期化**
3. **配列の値をスタックに格納する**
### ソート
4. **データ数が3個以下**
```
- ソート済み：何もしない
- データ数が1個：何もしない
- データ数が2個：入れ替え
- データ数が3個：全パターン手書き
```
5. **データ数が4個**
```
① 最小値をBへプッシュ
② 残った３個を上記３個のソートアルゴリズムを用いてソート
③ Bにいる最小値をAへプッシュ
```
6. **データ数が5個以上**
```
① BへAの先頭2つをプッシュ
② Aが３個以下になるまでBへプッシュ
  [プッシュする際の条件]
  - Bの最大以上か、最小以下ならBの最大の上にプッシュ
  - Bの最大が一番上にくるまでローテ
  - それ以外は一番数字が近い、自分より少ない数字の上にプッシュ
 - 上記２つの条件を満たすコマンド数が一番少なくて済むAを選択してプッシュする
③ Aが３個以下になったらAをソート
④ Bの全てをAへプッシュする
  [プッシュする際の条件（１の逆）] 
  - Aの最大以上か、最小以下ならAの最小の上にプッシュ
  - それ以外は一番数字が近い、自分より大きい数字の上にプッッシュ
 - 上記2つの条件を満たすコマンド数が一番少なくて済むBを選択してプッシュする
⑤ Aが昇順になるまでローテーション
```

## ビジュアライザー
https://github.com/o-reo/push_swap_visualizer

## 関数
> ### command\_utils
#### *command\_utils.c*
* void `do_command`(t\_command command, t\_stack \*stack\_a, t\_stack \*stack\_b)
* t\_command `calculation_command`(int a\_index, int b\_index, int a\_len, int b\_len)
* static int `get_smallest`(int ra\_rb, int rra\_rrb, int ra\_rrb, int rra\_rb)
* static int `rotate_count_with_ab`(int a\_count, int b\_count)
#### *command\_utils2.c*
* void `command_set_rrarb`(t\_command \*command, int rra\_count, int rb\_count)
* void `command_set_rarrb`(t\_command \*command, int ra\_count, int rrb\_count)
* void `commnad_set_rrarrb`(t\_command \*command, int rra\_count, int rrb\_count)
* void `commnad_set_rarb`(t\_command \*command, int ra\_count, int rb\_count)
#### *command\_utils3.c*
* void `register_command_push_a`(t\_stack \*stack\_a, t\_stack \*stack\_b, int b\_data, t\_command \*command)
* void `register_command_push_b`(t\_stack \*stack\_a, t\_stack \*stack\_b, int a\_data, t\_command \*command)
* t\_command \*`serch_optimal_command_push_to_a`(t\_stack \*stack\_a, t\_stack \*stack\_b)
* t\_command \*`serch_optimal_command_push_to_b`(t\_stack \*stack\_a, t\_stack \*stack\_b)
> ### main
#### *main.c*
* static bool `is_duplicate`(int \*array, int len, int data)
* int `data_set_to_stack`(int len\_data, t\_stack \*stack\_a, int \*data)
* static void `data_set_to_array`(int len\_data, char \*\*av, int \*data)
* int `main`(int ac, char \*\*av)
#### *push\_swap.c*
* void `sort_len_3`(t\_stack \*stack)
* void `sort_len_4`(t\_stack \*stack\_a, t\_stack \*stack\_b)
* void `push_swap`(int len, t\_stack \*stack\_a, t\_stack \*stack\_b)
#### *sort.c*
* int `get_target_from_b`(t\_stack \*stack\_b, int data)
* int `get_target_from_a`(t\_stack \*stack\_a, int data)
* void `sort_reverse`(t\_stack \*stack)
* bool `sort`(t\_stack \*stack\_a, t\_stack \*stack\_b)
> ### operations
#### *push.c*
* bool `push`(t\_stack \*stack, int data)
* bool `push_to`(t\_stack \*from, t\_stack \*to, char c)
* bool `pa`(t\_stack \*stack\_a, t\_stack \*stack\_b)
* bool `pb`(t\_stack \*stack\_a, t\_stack \*stack\_b)
#### *reverse\_rotate.c*
* void `reverse_rotate`(t\_stack \*stack, char c)
* void `rra`(t\_stack \*stack\_a)
* void `rrb`(t\_stack \*stack\_b)
* void `rrr`(t\_stack \*stack\_a, t\_stack \*stack\_b)
#### *rotate.c*
* void `rotate`(t\_stack \*stack, char c)
* void `ra`(t\_stack \*stack\_a)
* void `rb`(t\_stack \*stack\_b)
* void `rr`(t\_stack \*stack\_a, t\_stack \*stack\_b)
#### *swap.c*
* void `swap`(t\_stack \*stack, char c)
* void `sa`(t\_stack \*stack\_a)
* void `sb`(t\_stack \*stack\_b)
* void `ss`(t\_stack \*stack\_a, t\_stack \*stack\_b)
> ### stack\_utils
#### *stack\_checker.c*
* bool `is_sorted`(t\_stack \*stack)
* bool `is_empty`(t\_stack \*stack)
#### *stack\_info.c*
* int `get_len_stack`(t\_stack \*stack)
* int `get_max_data`(t\_stack \*stack)
* int `get_min_data`(t\_stack \*stack)
* int `get_index_from_data`(t\_stack \*stack, int data)
* void `print_stack`(t\_stack \*stack, char \*name)
#### *stack\_management.c*
* void `stack_init`(t\_stack \*stack\_a, t\_stack \*stack\_b)
* void `both_stack_index_init`(t\_stack \*stack\_a, t\_stack \*stack\_b)
* void `stack_index_init`(t\_stack \*stack)
* void `free_stack`(t\_stack \*stack)
> ### utils
#### *error.c*
* void `error_print`(void)
* void `error_print_exit`(void)
#### *push\_swap\_atoi.c*
* static char \*`pass_space`(char \*str)
* static char \*`check_plus_minus`(char \*str, int \*sign)
* static bool `is_int`(long long num, int sign)
* bool `push_swap_atoi`(char \*str, int \*data)
> ### libft
* int `ft_printf`(const char \*format, ...)
* int `ft_abs`(int nbr)
* int `ft_isdigit`(int c)
* int `ft_isspace`(int nbr)

## 参照
- https://github.com/o-reo/push_swap_visualizer
- https://medium.com/@ayogun/push-swap-c1f5d2d41e97