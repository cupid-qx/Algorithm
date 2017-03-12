//
// Created by qcq on 2017/3/10.
//

#include <stdio.h>
#include <conio.h>

#define LENGTH 8
int sourceArray[LENGTH + 1] = {61, 62, 90, 33, 88, 6, 28, 54};
int sourceArray2[LENGTH + 1] = {1, 2, 3, 4, 5, 6, 7, 8};

/**
 * 顺序查找法，
 * @param s ：按关键字排列的表
 * @param n ：顺序表的长度
 * @param key ：关键字
 * @return ：关键字所在的位置
 */
int search(int s[], int n, int key) {
    int i;
    for (i = 0; s[i] != key; ++i);
    if (i < n)
        return i;
    else
        return -1;
}

/**
 * 折半查找法，适用于顺序排列的表
 * @param s ：按关键字排列的表
 * @param n ：顺序表的长度
 * @param key ：关键字
 * @return ：关键字所在的位置
 */
int binSearch(int s[], int n, int key) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        // 计算中间位置序号
        mid = (low + high) / 2;
        if (s[mid] == key)
            return mid;
        else if (s[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int iKey, i, iPosition;
    printf("请输入关键字：");
    scanf("%d", &iKey);

    // 保存 key 值到最后一个位置
    sourceArray [LENGTH] = iKey;
    iPosition = search(sourceArray, LENGTH, iKey);

    printf("源数据表：");
    for (i = 0; i < LENGTH; ++i) {
        printf("%d\t", sourceArray[i]);
    }

    if (iPosition >= 0)
        printf("\n查找成功，关键字的位置是%d。\n", iPosition);
    else
        printf("查找失败!\n");


    getch();
}