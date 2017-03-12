//
// Created by qcq on 2017/3/10.
//

#include <stdio.h>
#include <conio.h>

#define LENGTH 8
int sourceArray[LENGTH + 1] = {61, 62, 90, 33, 88, 6, 28, 54};
int sourceArray2[LENGTH + 1] = {1, 2, 3, 4, 5, 6, 7, 8};

/**
 * ˳����ҷ���
 * @param s �����ؼ������еı�
 * @param n ��˳���ĳ���
 * @param key ���ؼ���
 * @return ���ؼ������ڵ�λ��
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
 * �۰���ҷ���������˳�����еı�
 * @param s �����ؼ������еı�
 * @param n ��˳���ĳ���
 * @param key ���ؼ���
 * @return ���ؼ������ڵ�λ��
 */
int binSearch(int s[], int n, int key) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        // �����м�λ�����
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
    printf("������ؼ��֣�");
    scanf("%d", &iKey);

    // ���� key ֵ�����һ��λ��
    sourceArray [LENGTH] = iKey;
    iPosition = search(sourceArray, LENGTH, iKey);

    printf("Դ���ݱ�");
    for (i = 0; i < LENGTH; ++i) {
        printf("%d\t", sourceArray[i]);
    }

    if (iPosition >= 0)
        printf("\n���ҳɹ����ؼ��ֵ�λ����%d��\n", iPosition);
    else
        printf("����ʧ��!\n");


    getch();
}