//
// Created by qcq on 2017/2/17.
//

#include <stdio.h>
#include <stdlib.h>

Move(int n, int x, int y, int z) {
    if (n == 1) {
        printf("����%d�����Ӵ�%c-->%c\n", n, x, z); //
    } else {
        Move(n - 1, x, z, y);//
        printf("����%d�����Ӵ�%c-->%c\n", n, x, z);
        {
            getchar();
        }
        Move(n - 1, y, x, z);//
    }
}

void main() {
    int h;
    printf("�������Ӹ�����");//
    scanf("%d", &h);
    printf("�ƶ�%2d�����ӵĲ�������\n", h);
    Move(h, 'a', 'b', 'c');//
    system("pause");
}