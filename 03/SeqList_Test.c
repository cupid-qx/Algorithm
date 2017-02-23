//
// Created by qcq on 2017/2/21.
//

#include <stdio.h>
#include <conio.h>
#include <mem.h>


typedef struct {
    char key[15];  //结点的关键字
    char name[20];
    int age;
} DATA;    //定义节点类型，可定义为简单类型，也可定义为结构


#include "Seq_List.c"


void show(SeqList *SL)  //遍历顺序表中的结点
{
    int i;
    for (i = 1; i <= SL->length; i++)
        printf("(%s,%s,%d)\n", SL->listData[i].key, SL->listData[i].name, SL->listData[i].age);
}

int main() {

    SeqList SL;         //定义顺序表变量
    DATA data;

    init(&SL);       //初始化顺序表

    do {                    //循环添加结点数据
        printf("输入添加的节点(学号 姓名 年龄)：");

        fflush(stdin);              //清空输入缓冲区

        scanf("%s%s%d", &data.key, &data.name, &data.age);
        if (strcmp(data.key,"0"))                                    //若年龄不为0
        {
            if (add(&SL, data) == -1)                   //若添加节点失败
                break;                                  //退出死循环
        } else   //若年龄为0
            break;          //退出死循环
    } while (1);
    printf("\n顺序表中的节点顺序为：\n");
    show(&SL);                     //显示所有结点数据

    getch();
    return 0;
}

