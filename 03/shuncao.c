//˳����в��� 
#include <malloc.h>
#include <stdio.h>
#include <mem.h>

#define QUEUEMAX 15

typedef struct {
    char name[20];
    int age;
} DATA;

typedef struct {
    DATA data[QUEUEMAX]; //�������� 
    int head; //��ͷ 
    int tail; //��β 
} Queue;

Queue *init(Queue *q) {
    if (q = (Queue *) malloc(sizeof(Queue))) //���뱣����е��ڴ�
    {
        q->head = 0;//���ö�ͷ 
        q->tail = 0;//���ö�β 
        return q;
    } else
        return NULL; //���ؿ�
}

void QueueFree(Queue *q) //�ͷŶ���
{
    if (q != NULL)
        free(q);
}

int QueueIsEmpty(Queue *q)  //�����Ƿ�Ϊ�� 
{
    return (q->head == q->tail);
}

int QueueIsFull(Queue *q)//�����Ƿ�����
{
    return (q->tail == QUEUEMAX);
}

int QueueLen(Queue *q) //��ȡ���г���
{
    return (q->tail - q->head);
}

int QueueIn(Queue *q, DATA data)//˳����е���Ӻ���
{
    if (q->tail == QUEUEMAX) {
        printf("�������ˣ�\n");
        return (0);
    } else {
        q->data[q->tail++] = data;
        return (1);
    }
}

DATA *QueueOut(Queue *q)//˳����еĳ���
{
    if (q->head == q->tail) {
        printf("\n���п��ˣ�\n");
        return NULL;
    } else {
        return &(q->data[q->head++]);
    }
}

DATA *QueuePeek(Queue *q) //��ȡ��ͷԪ��
{
    if (QueueIsEmpty(q)) {
        printf("\n���п���!\n");
        return NULL;
    } else {
        return &(q->data[q->head]);
    }
}

int main() {

    Queue *queue;
    queue = init(queue);
    DATA data;

    printf("%d", queue->tail);
    do {
        printf("������Ԫ�أ����������䣩��");
        fflush(stdin);              //������뻺����
        scanf("%s%d", &data.name, &data.age);
        if(strcmp(data.name,"0")==0)
            break;
        if(QueueIn(queue, data)==0)
            break;
    } while (1);

    printf("��һ��Ԫ�أ����������䣩�ǣ�%s,%d", QueuePeek(queue)->name, QueuePeek(queue)->age);
    return 0;
}