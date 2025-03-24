//二つのスタックを利用してスワップしてみる
// sa: stack_aの一番上とその下の値を入れ替える
// sb: stack_bの一番上とその下の値を入れ替える
// ss: saとsbを同時に実行
// pa: stack_bの一番上の値をstack_aに移動
// pb: stack_aの一番上の値をstack_bに移動
// ra: stack_aの一番上の値を一番下に移動 
// rb: stack_bの一番上の値を一番下に移動
// rr: raとrbを同時に実行
// rra: stack_aの一番下の値を一番上に移動
// rrb: stack_bの一番下の値を一番上に移動
// rrr: rraとrrbを同時に実行

#include <stdio.h>

#define STACK_SIZE 6

void print_stacks(int *stack_a, int top_a, int *stack_b, int top_b) {
    printf("A:");
    for (int i = 0; i <= top_a; i++)
        printf("%d ", stack_a[i]);
    printf("\n");
    printf("B:");
    for (int i = 0; i <= top_b; i++)
        printf("%d ", stack_b[i]);
    printf("\n\n");
}

void sa(int *stack_a, int top_a) {//スタックaの上から2つの要素を交換
    if (top_a > 0) {
        int temp = stack_a[top_a];
        stack_a[top_a] = stack_a[top_a - 1];
        stack_a[top_a - 1] = temp;
    }
}
void sb(int *stack_b, int top_b) { // スタックbの上から2つの要素を交換
    if (top_b > 0) {
        int temp = stack_b[top_b];
        stack_b[top_b] = stack_b[top_b - 1];
        stack_b[top_b - 1] = temp;
    }
}

void ss(int *stack_a, int top_a, int *stack_b, int top_b) { // saとsbを同時に実行
    sa(stack_a, top_a);
    sb(stack_b, top_b);
}

void pa(int *stack_a, int *top_a, int *stack_b, int *top_b) { // スタックbの上の要素をスタックaに移動
    if (*top_b >= 0 && *top_a < STACK_SIZE - 1) {
        stack_a[*top_a + 1] = stack_b[*top_b];
        (*top_a)++;
        (*top_b)--;
    }
}

void pb(int *stack_a, int *top_a, int *stack_b, int *top_b) { // スタックaの上の要素をスタックbに移動
    if (*top_a >= 0 && *top_b < STACK_SIZE - 1) {
        stack_b[*top_b + 1] = stack_a[*top_a];
        (*top_b)++;
        (*top_a)--;
    }
}

void ra(int *stack_a, int top_a) {//スタックaを回転(上の要素を下に移動)
    if (top_a > 0) {
        int temp = stack_a[top_a];
        for (int i = top_a; i > 0; i--) {
            stack_a[i] = stack_a[i - 1];
        }
        stack_a[0] = temp;
    }
}

void rb(int *stack_b, int top_b) { // スタックbを回転(上の要素を下に移動)
    if (top_b > 0) {
        int temp = stack_b[top_b];
        for (int i = top_b; i > 0; i--) {
            stack_b[i] = stack_b[i - 1];
        }
        stack_b[0] = temp;
    }
}

void rr(int *stack_a, int top_a, int *stack_b, int top_b) { // raとrbを同時に実行
    ra(stack_a, top_a);
    rb(stack_b, top_b);
}

void rra(int *stack_a, int top_a) {//スタックaを逆回転(下の要素を上に移動)
    if (top_a > 0) {
        int temp = stack_a[0];
        for (int i = 0; i < top_a; i++) {
            stack_a[i] = stack_a[i + 1];
        }
        stack_a[top_a] = temp;
    }
}

void rrb(int *stack_b, int top_b) { // スタックbを逆回転(下の要素を上に移動)
    if (top_b > 0) {
        int temp = stack_b[0];
        for (int i = 0; i < top_b; i++) {
            stack_b[i] = stack_b[i + 1];
        }
        stack_b[top_b] = temp;
    }
}

void rrr(int *stack_a, int top_a, int *stack_b, int top_b) { // rraとrrbを同時に実行
    rra(stack_a, top_a);
    rrb(stack_b, top_b);
}

int main() {
    int stack_a[STACK_SIZE] = {4, 1, 3, 2, 5};
    int stack_b[STACK_SIZE] = {7, 6, 0, 9, 8};

    int top_a = 4;
    int top_b = 4;

    print_stacks(stack_a, top_a, stack_b, top_b);

    sa(stack_a, top_a);
    printf("sa\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    sb(stack_b, top_b);
    printf("sb\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    ss(stack_a, top_a, stack_b, top_b);
    printf("ss\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    pa(stack_a, &top_a, stack_b, &top_b);
    printf("pa\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    pb(stack_a, &top_a, stack_b, &top_b);
    printf("pb\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    ra(stack_a, top_a);
    printf("ra\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    rb(stack_b, top_b);
    printf("rb\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    rr(stack_a, top_a, stack_b, top_b);
    printf("rr\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    rra(stack_a, top_a);
    printf("rra\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    rrb(stack_b, top_b);
    printf("rrb\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    rrr(stack_a, top_a, stack_b, top_b);
    printf("rrr\n");
    print_stacks(stack_a, top_a, stack_b, top_b);

    return 0;
}
