// stack.c
#include "push_swap.h"

void push(t_stack **stack, int value)
{
    t_stack *new = malloc(sizeof(t_stack));
    if (!new)
        return ;
    new->value = value;
    new->index = -1;
    new->next = *stack;
    *stack = new;
}

int pop(t_stack **stack)
{
    if (!*stack)
        return (0);
    t_stack *tmp = *stack;
    int val = tmp->value;
    *stack = tmp->next;
    free(tmp);
    return (val);
}

void free_stack(t_stack **stack)
{
    while (*stack)
        pop(stack);
}

int stack_size(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void assign_index(t_stack *stack)
{
    t_stack *tmp1 = stack;
    t_stack *tmp2;

    while (tmp1)
    {
        int count = 0;
        tmp2 = stack;
        while (tmp2)
        {
            if (tmp1->value > tmp2->value)
                count++;
            tmp2 = tmp2->next;
        }
        tmp1->index = count;
        tmp1 = tmp1->next;
    }
}

int get_max_bits(t_stack *stack)
{
    int max = 0;
    t_stack *tmp = stack;
    while (tmp)
    {
        if (tmp->index > max)
            max = tmp->index;
        tmp = tmp->next;
    }
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}