//
// Created by qcq on 2017/1/20.
//

#include <stdio.h>

int main() {
    int i[5], j;//ѭ������������ i ������ʾ4�������
    int sign; // �ۼ�����ʱ�ķ���
    int result;//��������ʱ�Ľ��ֵ
    int count;//��������ͳ�Ʒ��������ķ���
    int num[6];//���������
    float left, right; //�����м���

    char oper[5] = {' ', '+', '-', '*', '/'};

    printf("����5������֮���ÿո����");
    for (j = 1; j <= 5; ++j) {
        scanf("%d", &num[j]);
    }
    printf("������Ҫ�õ��Ľ��:");
    scanf("%d", &result);
    for (i[1] = 1; i[1] <= 4; ++i[1]) {
        if ((i[1] < 4) || (num[2] != 0)) {
            for (i[2] = 1; i[2] <= 4; ++i[2]) {
                if ((i[2] < 4) || (num[3] != 0)) {
                    for (i[3] = 1; i[3] <= 4; ++i[3]) {
                        if ((i[3] < 4) || (num[4] != 0)) {
                            for (i[4] = 1; i[4] <= 4; ++i[4]) {
                                if ((i[4] < 4) || (num[5] != 0)) {
                                    left = 0;
                                    right = num[1];
                                    sign = 1;
                                    for (j = 1; j <= 4; ++j) {
                                        switch (oper[i[j]]) {
                                            case '+':
                                                left = left + sign * right;
                                                sign = 1;
                                                right = num[j + 1];
                                                break;
                                            case '-':
                                                left = left + sign * right;
                                                sign = 1;
                                                right = num[j + 1];
                                                break;
                                            case '*':
                                                right = right * num[j - 1];
                                                break;
                                            case '/':
                                                right = right / num[j + 1];
                                                break;
                                        }
                                    }
                                    if (left + sign * right == result) {
                                        count++;
                                        printf("%3d:", count);
                                        for (j = 1; j <= 4; ++j) {
                                            printf("%d%c", num[j], oper[i[j]]);
                                            printf("%d=%d\n", num[5], result);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0 ;
}
