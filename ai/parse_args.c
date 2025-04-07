// parse_args.c
#include "push_swap.h"

int is_valid_number(char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int is_duplicate(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

int parse_args(int argc, char **argv, t_stack **a)
{
    for (int i = argc - 1; i > 0; i--)
    {
        if (!is_valid_number(argv[i]))
            return (0);
        long val = atol(argv[i]);
        if (val < INT_MIN || val > INT_MAX || is_duplicate(*a, (int)val))
            return (0);
        push(a, (int)val);
    }
    return (1);
}

int error_exit(t_stack **a, t_stack **b)
{
    write(2, "Error\n", 6);
    free_stack(a);
    free_stack(b);
    return (1);
}