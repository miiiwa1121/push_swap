// グローバル変数を使わずにスタック法でpushとpopをやってみる

#include<stdio.h>

#define STACK_SIZE    100  /* スタックデータ数の最大値 */
#define SUCCESS       1    /* 成功 */
#define FAILURE       0    /* 失敗 */

typedef int data_t;

typedef struct {
    int num;
    data_t data[STACK_SIZE];
} stack_t;

int push(stack_t *stk, data_t push_data)
{
    if (stk->num < STACK_SIZE) {
        stk->data[stk->num] = push_data;
        stk->num ++;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

int pop(stack_t *stk, data_t *pop_data)
{
    if (stk->num > 0) {
        stk->num --;
        *pop_data = stk->data[stk->num];
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

void stackPrint(stack_t *stk)
{
    int i;
	
    printf("stack [");
    for (i = 0; i < stk->num; i++) {
        printf("%3d", stk->data[i]);
    }
    printf("]\n");
}

int main()
{
    stack_t stk;
    int i, p;

    stk.num = 0; /* スタックのデータ数を 0 に初期化 */
    for (i = 1; i <=4 ; i++) {     
        push(&stk, i);                  /* 1 から 4 までの数値を push */
        printf("push %2d :", i);
        stackPrint(&stk);
    } 
    while (stk.num > 0) {
        pop(&stk, &p);                /* スタックに残っているデータを全て pop */
        printf("pop  %2d :", p);
        stackPrint(&stk);
    } 
}

// result
// push  1 :stack [  1]
// push  2 :stack [  1  2]
// push  3 :stack [  1  2  3]
// push  4 :stack [  1  2  3  4]
// pop   4 :stack [  1  2  3]
// pop   3 :stack [  1  2]
// pop   2 :stack [  1]
// pop   1 :stack []