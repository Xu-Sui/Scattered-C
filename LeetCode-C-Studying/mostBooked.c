#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
    int* count = (int*)malloc(sizeof(int) * n);
    int** conditions = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        count[i] = 0;
        conditions[i] = (int*)malloc(sizeof(int) * 2);
        conditions[i][0] = 0, conditions[i][1] = 0;
    }
    int now = meetings[0][0];
    //count[0]++, conditions[0][0] = 1, conditions[0][1] = meetings[0][1];

    for (int i = 0; i < meetingsSize; ) {
        for (int j = 0; j < n; j++)
            if (now >= conditions[j][1])
                conditions[j][0] = 0, conditions[j][1] = 0;
    get:
        if (i < meetingsSize && now == meetings[i][0]) {
            for (int j = 0; j < n; j++)
                if (!conditions[j][0]) {
                    conditions[j][0] = 1, conditions[j][1] = meetings[i][1], count[j]++, i++;
                    goto get;
                }
            for (int k = 0; k + i < meetingsSize; k++)
                if (meetings[k + i][0] == now)
                    meetings[k + i][0]++, meetings[k + i][1]++;
        }
        now++;
    }

    int ret = count[0];
    for (int i = 0; i < meetingsSize - 2; i++)
        ret = count[i] > count[i + 1] ? count[i] : count[i + 1];
    return ret;
}

int main(){
    int n = 2;
    int meetings[4][2] = { {0,10},{1,5},{2,7},{3,4} };
    int meetingsSize = 4;
    // 正确构造方式
    int* meetings_array[4];
    for (int i = 0; i < 4; i++) {
        meetings_array[i] = meetings[i];  // 每行的首地址
    }
    printf("%d\n", mostBooked(n, meetings_array, meetingsSize, NULL));
    return 0;
}