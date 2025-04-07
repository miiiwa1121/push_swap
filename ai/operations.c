// operations.c
#include "push_swap.h"

void sa(t_stack **a)
{
    if (!*a || !(*a)->next)
        return ;
    int tmp = (*a)->value;
    (*a)->value = (*a)->next->value;
    (*a)->next->value = tmp;
    write(1, "sa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    if (!*a)
        return ;
    int val = pop(a);
    push(b, val);
    write(1, "pb\n", 3);
}

void pa(t_stack **a, t_stack **b)
{
    if (!*b)
        return ;
    int val = pop(b);
    push(a, val);
    write(1, "pa\n", 3);
}

void ra(t_stack **a)
{
    if (!*a || !(*a)->next)
        return ;
    t_stack *first = *a;
    t_stack *last = *a;
    while (last->next)
        last = last->next;
    *a = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}

void rra(t_stack **a)
{
    if (!*a || !(*a)->next)
        return ;
    t_stack *prev = NULL;
    t_stack *last = *a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    *a = last;
    write(1, "rra\n", 4);
}