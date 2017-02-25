//顺序队列操作 
#include <malloc.h>
#include <stdio.h>
#include <mem.h>

#define QUEUEMAX 15

typedef struct {
    char name[20];
    int age;
} DATA;

typedef struct {
    DATA data[QUEUEMAX]; //队列数组 
    int head; //队头 
    int tail; //队尾 
} Queue;

Queue *init(Queue *q) {
    if (q = (Queue *) malloc(sizeof(Queue))) //申请保存队列的内存
    {
        q->head = 0;//设置队头 
        q->tail = 0;//设置队尾 
        return q;
    } else
        return NULL; //返回空
}

void QueueFree(Queue *q) //释放队列
{
    if (q != NULL)
        free(q);
}

int QueueIsEmpty(Queue *q)  //队列是否为空 
{
    return (q->head == q->tail);
}

int QueueIsFull(Queue *q)//队列是否已满
{
    return (q->tail == QUEUEMAX);
}

int QueueLen(Queue *q) //获取队列长度
{
    return (q->tail - q->head);
}

int QueueIn(Queue *q, DATA data)//顺序队列的入队函数
{
    if (q->tail == QUEUEMAX) {
        printf("队列满了！\n");
        return (0);
    } else {
        q->data[q->tail++] = data;
        return (1);
    }
}

DATA *QueueOut(Queue *q)//顺序队列的出队
{
    if (q->head == q->tail) {
        printf("\n队列空了！\n");
        return NULL;
    } else {
        return &(q->data[q->head++]);
    }
}

DATA *QueuePeek(Queue *q) //获取队头元素
{
    if (QueueIsEmpty(q)) {
        printf("\n队列空了!\n");
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
        printf("请输入元素（姓名，年龄）：");
        fflush(stdin);              //清空输入缓冲区
        scanf("%s%d", &data.name, &data.age);
        if(strcmp(data.name,"0")==0)
            break;
        if(QueueIn(queue, data)==0)
            break;
    } while (1);

    printf("第一个元素（姓名、年龄）是：%s,%d", QueuePeek(queue)->name, QueuePeek(queue)->age);
    return 0;
}