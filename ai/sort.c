// sort.c
#include "push_swap.h"

void sort_3(t_stack **a)
{
    int x = (*a)->value;
    int y = (*a)->next->value;
    int z = (*a)->next->next->value;

    if (x > y && y < z && x < z)
        sa(a);
    else if (x > y && y > z)
    {
        sa(a);
        rra(a);
    }
    else if (x > y && y < z && x > z)
        ra(a);
    else if (x < y && y > z && x < z)
    {
        sa(a);
        ra(a);
    }
    else if (x < y && y > z && x > z)
        rra(a);
}

void sort_stack(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    if (size <= 3)
        sort_3(a);
    else
    {
        assign_index(*a);
        int bits = get_max_bits(*a);
        int i, j;
        for (i = 0; i < bits; i++)
        {
            j = 0;
            int len = stack_size(*a);
            while (j++ < len)
            {
                if (((*a)->index >> i) & 1)
                    ra(a);
                else
                    pb(a, b);
            }
            while (*b)
                pa(a, b);
        }
    }
}
