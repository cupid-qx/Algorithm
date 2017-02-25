//
// Created by qcq on 2017/2/25.
//

#include <malloc.h>
#include <stdio.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE]; // ����Ԫ��
    int head; // ��ͷ
    int tail; // ��β
} Queue;

// ��ʼ������
Queue *init() {
    Queue *q;
    // �����ڴ�ռ�
    q = (Queue *) malloc(sizeof(Queue));

    if (q == NULL) {
        // ����ռ�ʧ��
        return NULL;
    } else {
        // ���ö�ͷ�Ͷ�β
        q->head = 0;
        q->tail = 0;
    }
    return q;
}

// �ͷŶ���
void freeQueue(Queue *q) {
    if (q != NULL)
        free(q);
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(Queue *q) {
    if (q->tail == q->head)
        return 1;

    return 0;
    // ���ߣ�return (q->tail==q->head) ;
}

// �ж϶����Ƿ�����
int isFull(Queue *q) {
    // ѭ�����У�������β����ͷ��������Ϊ��
    if ((q->tail + 1) % MAXSIZE == q->head)
        return 1;
    return 0;
}

// �����
int push(Queue *q, int data) {
    // �ж϶����Ƿ�����
    if (isFull(q) == 1) {
        printf("��ǰ���������������ʧ�ܡ�\n");
        return 0;
    } else {
        // �������β�������
        q->tail = (q->tail + 1) % MAXSIZE;
        q->data[q->tail] = data;
        return 1;
    }
}

// ������
int pop(Queue *q) {
    // ����Ϊ��
    if (isEmpty(q) == 1) {
        printf("��ǰ����Ϊ�ա�\n");
        return NULL;
    } else {
        q->head = (q->head + 1) % MAXSIZE;
        return q->data[q->head];
    }
}

// ��ȡ��һ��λ�õ�����
int top(Queue *q) {
    if (isEmpty(q) == 1) {
        printf("�����Ѿ�����");
        return NULL;
    }
    return q->data[(q->head + 1) % MAXSIZE];
}

// ����еĳ���
int length(Queue *q) {
    int n = q->tail - q->head;
    if (n < 0)
        return MAXSIZE + n;
    return n;
}

// ��ʾ����ȫ��Ԫ��
void show(Queue *q)
{
    if (length(q)==0)
        printf("��ǰ����Ϊ�գ�û��Ԫ��");
    int i ;
    for (i = 1; i <= length(q); ++i) {
        int j = q->head + i ;
        if(j>=MAXSIZE)
            j = j%MAXSIZE ;
        printf("%d\t",q->data[j]);
    }
}
int main() {

    // ��ʼ��һ��ѭ������
    Queue *q = init();

    int i;
    for (i = 0; i < 9; ++i) {
        push(q, i);
    }

    printf("��ǰ����Ԫ��Ϊ��");
    show(q);

    for (i = 1; i < 10; ++i) {
        pop(q);
    }

    printf("\n���еĳ���Ϊ��%d\n", length(q));
    printf("��ʱ��ͷ��β�ֱ��ǣ�%d\t%d\n",q->head,q->tail);

    for (i = 1; i < 5; ++i) {
        push(q, i);
    }
    printf("��ǰ����Ԫ��Ϊ��");
    show(q);

    printf("\n��ʱ��ͷ��β�ֱ��ǣ�%d\t%d",q->head,q->tail);
    return 0;
}