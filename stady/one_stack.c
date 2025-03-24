//ひとつのスタックを利用してスワップしてみる
// sa: stack_aの一番上とその下の値を入れ替える
// ra: stack_aの一番上の値を一番下に移動 
// rra: stack_aの一番下の値を一番上に移動

#include <stdio.h>

void sa(int *stack_a, int top_a) {//隣同士の値を入れ替える
    if (top_a > 0) {
        int temp = stack_a[top_a];
        stack_a[top_a] = stack_a[top_a - 1];
        stack_a[top_a - 1] = temp;
    }
}

void ra(int *stack_a, int top_a) {//一番上の値を一番下に移動
    if (top_a > 0) {
        int temp = stack_a[top_a];
        for (int i = top_a; i > 0; i--) {
            stack_a[i] = stack_a[i - 1];
        }
        stack_a[0] = temp;
    }
}

void rra(int *stack_a, int top_a) {//一番下の値を一番上に移動
    if (top_a > 0) {
        int temp = stack_a[0];
        for (int i = 0; i < top_a; i++) {
            stack_a[i] = stack_a[i + 1];
        }
        stack_a[top_a] = temp;
    }
}

int main() {
    int stack_a[5] = {4, 1, 3, 2, 5};
    int top_a = 4;//一番上の値のindex

    // 結果の表示
    for (int i = 0; i <= top_a; i++)
        printf("%d ", stack_a[i]);
    printf("\n");

    // 操作をテスト
    sa(stack_a, top_a);

    // 結果の表示
    for (int i = 0; i <= top_a; i++)
        printf("%d ", stack_a[i]);
    printf("\n");

    // 操作をテスト
    ra(stack_a, top_a);

    // 結果の表示
    for (int i = 0; i <= top_a; i++)
        printf("%d ", stack_a[i]);
    printf("\n");

    rra(stack_a, top_a);

    // 結果の表示
    for (int i = 0; i <= top_a; i++)
        printf("%d ", stack_a[i]);
    printf("\n");


    return 0;
}
