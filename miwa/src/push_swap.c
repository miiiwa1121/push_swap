#include <stdio.h>

void sa(int *stack_a, int top_a) {
    if (top_a > 0) {
        int temp = stack_a[top_a];
        stack_a[top_a] = stack_a[top_a - 1];
        stack_a[top_a - 1] = temp;
    }
}

void ra(int *stack_a, int top_a) {
    if (top_a > 0) {
        int temp = stack_a[top_a];
        for (int i = top_a; i > 0; i--) {
            stack_a[i] = stack_a[i - 1];
        }
        stack_a[0] = temp;
    }
}

int main() {
    // int stack_a[3] = {2, 3, 1};
    // int top_a = 2;
    int stack_a[5] = {4, 1, 3, 2, 5};
    int top_a = 4;


    // 操作をテスト
    sa(stack_a, top_a);
    ra(stack_a, top_a);

    // 結果の表示
    for (int i = 0; i <= top_a; i++) {
        printf("%d ", stack_a[i]);
    }
    printf("\n");

    return 0;
}
