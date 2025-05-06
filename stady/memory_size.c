#include <stdio.h>

typedef struct s_command//28
{
	int		all;//4
	int		ra;//4
	int		rra;//...
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
}	t_command;

typedef struct s_node//56
{
	int				data;//4
	int				index;//4
	t_command		command;//28+4(環境調整)
	struct s_node	*next;//8
	struct s_node	*prev;//8
}	t_node;

typedef struct s_stack//8
{
	t_node	*top;//8
}	t_stack;

int main() {
    printf("sizeof(t_node) = %zu\n", sizeof(t_command));
    return 0;
}

/* 
t_command		command;//28+4(環境調整)
t_node	*top;//8
この二つで値の大きさに差があるのは、 t_commandはポインタ型ではなく、t_nodeはポインタ型で宣言しているから
ポインタ型は、今回の例でいうと、t_node（56バイト）が格納されている値そのものではなく、格納先のポインタ分だけのメモリを確保すればよいので8バイト
比べて、t_commandはポインタ型ではないので、値そのもの確保する分のメモリを確保する必要がある
*/