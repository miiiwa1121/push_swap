/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:53:57 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/10/22 18:01:15 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sa(int *stack_a, int top_a);
void ra(int *stack_a, int top_a);

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
