// グローバル変数を使ってスタック法でpushとpopをやってみる

#include <stdio.h>

#define STACK_SIZE  100   /* スタックに積むことのできるデータの最大個数 */
#define SUCCESS     1     /* 成功 */
#define FAILURE     0     /* 失敗 */

typedef int data_t;       /* スタックに貯えるデータの型 */
data_t stack_data[STACK_SIZE];  /* スタック本体 */
int stack_num;                  /* スッタク内のデータ数 *///グローバル変数

int push(data_t push_data)
{
    if (stack_num < STACK_SIZE) {
        stack_data[stack_num] = push_data;
        stack_num ++;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}
// data_t 型の引数 push_data をとり，それをスタックstack_data に積み，整数値 SUCCESS を関数値として返す。
// ただし，スタックが満杯であるときは積まずに，整数値 FAILURE を関数値として返す。
// stack_num は，現在スタックに積まれているデータの個数を保持しているが，それは stack_data[0] から stack_data[stack_num - 1] までにデータが入っていることを意味している。
//したがって，新しいデータは stack_data[stack_num] に保存することになる。
//そして保存した後， stack_num の値を1増やす。

int pop(data_t *pop_data)
{
    if (stack_num > 0) {
        stack_num --;
        *pop_data = stack_data[stack_num];
        return SUCCESS;
    } else {
        return FAILURE;
    }
}
// スタックが空でないとき，stack_data にある最後の値を *pop_data に代入し，stack_num の値を 1 減じて、戻り値 SUCCESS を返す。
//スタックが空であるときには何もしないで、戻り値 FAILURE を返す（*pop_data の値も変化させない）。

void stackPrint()
{
    int i;

    printf("stack [");
    for (i = 0; i < stack_num; i++) {
        printf("%3d", stack_data[i]);
    }
    printf("]\n");
}
// スッタク内のデータを表示する関数

int main()
{
int i, p;

    stack_num = 0; /* スタックのデータ数を 0 に初期化 */
    for (i = 1; i<=5 ; i++) {     
        push(i);                  /* 1 から 5 までの数値を push */
        printf("push %2d :", i);
        stackPrint();
    } 
    for (i = 1; i <= 3; i++) {
        pop(&p);                /* 3 回だけ pop */
        printf("pop  %2d :", p);
        stackPrint();
    }
    for (i = 6; i <= 9; i++) {
        push(i);                  /* 6 から 9 までの数値を push */
        printf("push %2d :", i);
        stackPrint();
    }
    while (stack_num > 0) {
        pop(&p);                /* スタックに残っているデータを全て pop */
        printf("pop  %2d :", p);
        stackPrint();
    } 
}

// result
// push  1 :stack [  1]
// push  2 :stack [  1  2]
// push  3 :stack [  1  2  3]
// push  4 :stack [  1  2  3  4]
// push  5 :stack [  1  2  3  4  5]
// pop   5 :stack [  1  2  3  4]
// pop   4 :stack [  1  2  3]
// pop   3 :stack [  1  2]
// push  6 :stack [  1  2  6]
// push  7 :stack [  1  2  6  7]
// push  8 :stack [  1  2  6  7  8]
// push  9 :stack [  1  2  6  7  8  9]
// pop   9 :stack [  1  2  6  7  8]
// pop   8 :stack [  1  2  6  7]
// pop   7 :stack [  1  2  6]
// pop   6 :stack [  1  2]
// pop   2 :stack [  1]
// pop   1 :stack []