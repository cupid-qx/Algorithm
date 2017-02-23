#include <stdio.h>
#include <conio.h>


typedef struct {
    char key[15];    //�ؼ���
    char name[20];
    int age;
} DATA;    //���ݽ������

#include "ChainList.c"
void ChainListAll(ChainList *head) //��������
{
    ChainList *h;
    DATA data;
    h = head;
    printf("���������������£�\n");
    while (h) //ѭ����������ÿ�����
    {
        data = h->data;//��ȡ�������
        printf("(%s,%s,%d)\n", data.key, data.name, data.age);
        h = h->next;//������һ���
    }
    return;
}

int main() {
    ChainList *node, *head = NULL;
    DATA data;
    char key[15], findkey[15];

    printf("���������е����ݣ������ؼ��֡����������䣬�ؼ�������0�����˳���\n");

    do {
        fflush(stdin);  //������뻺���� 
        scanf("%s", data.key);
        if (strcmp(data.key, "0") == 0) break; //������0�����˳�
        scanf("%s%d", data.name, &data.age);
        head = addEnd(head, data);//������β����ӽ������
        printf("���������е����ݣ������ؼ��֡����������䣬�ؼ�������0�����˳���\n");
    } while (1);

    printf("��������%d����㡣\n", length(head)); //���ؽ������
    ChainListAll(head); //��ʾ���н��

    printf("\n�����㣬�������λ�õĹؼ��֣�");
    scanf("%s", &findkey);//�������λ�ùؼ���
    printf("��������������(�ؼ��� ���� ����):");
    scanf("%s%s%d", data.key, data.name, &data.age);//�������������
    head = insert(head, findkey, data);//���ò��뺯��

    ChainListAll(head); //��ʾ���н��

    printf("\n�������в��ң�������ҹؼ���:");
    fflush(stdin);//������뻺���� 
    scanf("%s", key);//������ҹؼ���
    node = find(head, key);//���ò��Һ��������ؽ��ָ��
    if (node)//�����ؽ��ָ����Ч
    {
        data = node->data;//��ȡ��������
        printf("�ؼ���%s��Ӧ�Ľ������Ϊ(%s,%s,%d)\n", key, data.key, data.name, data.age);
    } else//�����ָ����Ч
        printf("��������δ�ҵ��ؼ���Ϊ%s�Ľ�㣡\n", key);

    printf("\n��������ɾ����㣬����Ҫɾ���Ĺؼ���:");
    fflush(stdin);//������뻺���� 
    scanf("%s", key);//����ɾ�����ؼ���
    delete(head, key); //����ɾ����㺯��
    ChainListAll(head); //��ʾ���н��   
    getch();
    return 0;
}
