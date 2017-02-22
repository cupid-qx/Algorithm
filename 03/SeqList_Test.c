//
// Created by qcq on 2017/2/21.
//

#include <stdio.h>
#include <conio.h>
#include "Seq_List.h"
#include "Seq_List.c"
typedef struct {
    char key[15];  //���Ĺؼ���
    char name[20];
    int age;
} DATA;    //����ڵ����ͣ��ɶ���Ϊ�����ͣ�Ҳ�ɶ���Ϊ�ṹ




void show(SeqList *SL)  //����˳����еĽ��
{
    int i;
    for (i = 1; i <= SL->length; i++)
        printf("(%s,%s,%d)\n", SL->ListData[i].key, SL->ListData[i].name, SL->ListData[i].age);
}

int main() {
    int i;
    SeqList SL;         //����˳������
    DATA data, *data1;       //����ڵ㱣���������ͱ�����ָ�����
    char key[15];           //����ؼ���

    init(&SL);       //��ʼ��˳���

    do {                    //ѭ����ӽ������
        printf("������ӵĽڵ�(ѧ�� ���� ����)��");
        fflush(stdin);              //������뻺����
        scanf("%s%s%d", &data.key, &data.name, &data.age);
        if (data.age)                                    //�����䲻Ϊ0
        {
            if (!add(&SL, data))                   //����ӽڵ�ʧ��
                break;                                  //�˳���ѭ��
        } else   //������Ϊ0
            break;          //�˳���ѭ��
    } while (1);
    printf("\n˳����еĽڵ�˳��Ϊ��\n");
    show(&SL);                     //��ʾ���н������

    fflush(stdin);                       //������뻺����
    printf("\nҪȡ���ڵ����ţ�");
    scanf("%d", &i);                 //����ڵ����
    data1 = findByNum(&SL, i);  //����Ų��ҽ��
    if (data1)                       //�����صĽڵ�ָ�벻ΪNULL
        printf("��%d���ڵ�Ϊ��(%s,%s,%d)\n", i, data1->key, data1->name, data1->age);

    fflush(stdin);                                                             //������뻺����
    printf("\nҪ���ҽڵ�Ĺؼ��֣�");
    scanf("%s", key);  //����ؼ���
    i = findByKey(&SL, key);      //���ؼ��ֲ��� �����ؽڵ����
    data1 = findByNum(&SL, i);     //����Ų�ѯ�����ؽڵ�ָ��
    if (data1)                          //���ڵ�ָ�벻ΪNULL
        printf("��%d���ڵ�Ϊ��(%s,%s,%d)\n", i, data1->key, data1->name, data1->age);
    getch();
    return 0;
}

