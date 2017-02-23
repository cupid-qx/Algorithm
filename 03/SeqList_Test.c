//
// Created by qcq on 2017/2/21.
//

#include <stdio.h>
#include <conio.h>
#include <mem.h>


typedef struct {
    char key[15];  //���Ĺؼ���
    char name[20];
    int age;
} DATA;    //����ڵ����ͣ��ɶ���Ϊ�����ͣ�Ҳ�ɶ���Ϊ�ṹ


#include "Seq_List.c"


void show(SeqList *SL)  //����˳����еĽ��
{
    int i;
    for (i = 1; i <= SL->length; i++)
        printf("(%s,%s,%d)\n", SL->listData[i].key, SL->listData[i].name, SL->listData[i].age);
}

int main() {

    SeqList SL;         //����˳������
    DATA data;

    init(&SL);       //��ʼ��˳���

    do {                    //ѭ����ӽ������
        printf("������ӵĽڵ�(ѧ�� ���� ����)��");

        fflush(stdin);              //������뻺����

        scanf("%s%s%d", &data.key, &data.name, &data.age);
        if (strcmp(data.key,"0"))                                    //�����䲻Ϊ0
        {
            if (add(&SL, data) == -1)                   //����ӽڵ�ʧ��
                break;                                  //�˳���ѭ��
        } else   //������Ϊ0
            break;          //�˳���ѭ��
    } while (1);
    printf("\n˳����еĽڵ�˳��Ϊ��\n");
    show(&SL);                     //��ʾ���н������

    getch();
    return 0;
}

