#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include "push_swap.h"



static char	*pass_space(char *str)//空白をスキップ
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static char	*check_sign(char *str, int *sign)//符号を取得
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static bool	is_int(long long num, int sign)//intの範囲外の場合
{
	if (sign == 1 && num > __INT_MAX__)
		return (false);
	if (sign == -1 && num * -1 < INT_MIN)
		return (false);
	return (true);
}

bool	atoi_custom(char *str, int *num_data)//文字列を数値に変換し、エラーの場合はfalseを返す
{
	int			sign;
	long long	ans;

	sign = 1;//1 or -1
	ans = 0;
	str = pass_space(str);
	str = check_sign(str, &sign);
	if (*str == '\0' || str == NULL)//文字列が空の場合
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))//数字以外の文字の場合(asciiで48~57以外)
			return (false);
		ans = (*str - '0') + (ans * 10);
		if (!is_int(ans, sign))
			return (false);
		str++;
	}
	*num_data = ans * sign;
	return (true);
}


int set_array(int len_data, char **av, int *data)//コマンドライン引数で受け取った引数を配列に格納していく
{
    int index;
    int num_data;

    index = 0;
    while(len_data > index){
        if(!atoi_custom(av[index],&num_data))
        {
            free(data);
            return (0);
        }
        data[index] = num_data;
        index++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int *data;
    int len_data;

    if (ac < 2)
		return (0);
    len_data = ac - 1;
    data = malloc(sizeof(int) * len_data);
    if (!data)
    {
        free(data);
        return (0);
    }
    if (set_array(len_data, ++av, data) == -1)
		return (1);

        for (int i = 0; i < len_data; i++)
        {
            printf("data[%d] = %d\n", i, data[i]);
        }
    
        free(data);
        return (0);
}
