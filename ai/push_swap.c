// push_swap.c
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
        return (0);

    if (!parse_args(argc, argv, &a))
        return (error_exit(&a, &b));

    if (!is_sorted(a))
        sort_stack(&a, &b);

    free_stack(&a);
    return (0);
}
