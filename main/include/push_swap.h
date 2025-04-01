#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct t_command
{
	int		all;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
};

typedef struct t_node
{
	int				data;//データ
	int				index;//インデックス
	t_command		command;//コマンド
	struct s_node	*next;//次のノードへのポインタ
	struct s_node	*prev;//前のノードへのポインタ
};

typedef struct t_stack
{
	t_node	*top;//スタックのトップへのポインタ
};
