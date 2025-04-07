// push_swap.h
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack *next;
}   t_stack;

// stack.c
void    push(t_stack **stack, int value);
int     pop(t_stack **stack);
void    free_stack(t_stack **stack);
int     stack_size(t_stack *stack);
int     is_sorted(t_stack *stack);
int     get_max_bits(t_stack *stack);
void    assign_index(t_stack *stack);

// parse_args.c
int     parse_args(int argc, char **argv, t_stack **a);
int     is_valid_number(char *str);
int     is_duplicate(t_stack *stack, int value);
int     error_exit(t_stack **a, t_stack **b);

// operations.c
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

// sort.c
void    sort_stack(t_stack **a, t_stack **b);

#endif