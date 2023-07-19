
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int)*2);
    int i, j, count_win = 0, count_unknown = 0;
    for(i = 0; i < 6; ++i){
        for(j = 0; j < 6; ++j){
            if(win_nums[j]==lottos[i])
                ++count_win;
        }
        if(lottos[i]==0)
            ++count_unknown;
    }
    
    if(count_win + count_unknown < 2)
        answer[0] = 6;
    else
        answer[0] = 7 - count_win - count_unknown;
    
    if(count_win<2)
        answer[1] = 6;  
    else
        answer[1] = 7 - count_win;
    
    
    return answer;
}