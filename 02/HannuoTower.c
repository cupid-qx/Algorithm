//
// Created by qcq on 2017/2/17.
//

#include <stdio.h>
#include <stdlib.h>

Move(int n, int x, int y, int z) {
    if (n == 1) {
        printf("将第%d个盘子从%c-->%c\n", n, x, z); //
    } else {
        Move(n - 1, x, z, y);//
        printf("将第%d个盘子从%c-->%c\n", n, x, z);
        {
            getchar();
        }
        Move(n - 1, y, x, z);//
    }
}

void main() {
    int h;
    printf("输入盘子个数：");//
    scanf("%d", &h);
    printf("移动%2d个盘子的步骤如下\n", h);
    Move(h, 'a', 'b', 'c');//
    system("pause");
}