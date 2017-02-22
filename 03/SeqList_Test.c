//
// Created by qcq on 2017/2/21.
//

#include <stdio.h>
#include <conio.h>
#include "Seq_List.h"
#include "Seq_List.c"
typedef struct {
    char key[15];  //结点的关键字
    char name[20];
    int age;
} DATA;    //定义节点类型，可定义为简单类型，也可定义为结构




void show(SeqList *SL)  //遍历顺序表中的结点
{
    int i;
    for (i = 1; i <= SL->length; i++)
        printf("(%s,%s,%d)\n", SL->ListData[i].key, SL->ListData[i].name, SL->ListData[i].age);
}

int main() {
    int i;
    SeqList SL;         //定义顺序表变量
    DATA data, *data1;       //定义节点保存数据类型变量和指针变量
    char key[15];           //保存关键字

    init(&SL);       //初始化顺序表

    do {                    //循环添加结点数据
        printf("输入添加的节点(学号 姓名 年龄)：");
        fflush(stdin);              //清空输入缓冲区
        scanf("%s%s%d", &data.key, &data.name, &data.age);
        if (data.age)                                    //若年龄不为0
        {
            if (!add(&SL, data))                   //若添加节点失败
                break;                                  //退出死循环
        } else   //若年龄为0
            break;          //退出死循环
    } while (1);
    printf("\n顺序表中的节点顺序为：\n");
    show(&SL);                     //显示所有结点数据

    fflush(stdin);                       //清空输入缓冲区
    printf("\n要取出节点的序号：");
    scanf("%d", &i);                 //输入节点序号
    data1 = findByNum(&SL, i);  //按序号查找结点
    if (data1)                       //若返回的节点指针不为NULL
        printf("第%d个节点为：(%s,%s,%d)\n", i, data1->key, data1->name, data1->age);

    fflush(stdin);                                                             //清空输入缓冲区
    printf("\n要查找节点的关键字：");
    scanf("%s", key);  //输入关键字
    i = findByKey(&SL, key);      //按关键字查找 ，返回节点序号
    data1 = findByNum(&SL, i);     //按序号查询，返回节点指针
    if (data1)                          //若节点指针不为NULL
        printf("第%d个节点为：(%s,%s,%d)\n", i, data1->key, data1->name, data1->age);
    getch();
    return 0;
}

