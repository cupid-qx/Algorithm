//
// Created by qcq on 2017/2/25.
//

#include <malloc.h>
#include <stdio.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE]; // 队列元素
    int head; // 队头
    int tail; // 队尾
} Queue;

// 初始化队列
Queue *init() {
    Queue *q;
    // 申请内存空间
    q = (Queue *) malloc(sizeof(Queue));

    if (q == NULL) {
        // 分配空间失败
        return NULL;
    } else {
        // 设置队头和队尾
        q->head = 0;
        q->tail = 0;
    }
    return q;
}

// 释放队列
void freeQueue(Queue *q) {
    if (q != NULL)
        free(q);
}

// 判断队列是否为空
int isEmpty(Queue *q) {
    if (q->tail == q->head)
        return 1;

    return 0;
    // 或者：return (q->tail==q->head) ;
}

// 判断队列是否已满
int isFull(Queue *q) {
    // 循环队列，当队列尾部和头部相邻是为满
    if ((q->tail + 1) % MAXSIZE == q->head)
        return 1;
    return 0;
}

// 入队列
int push(Queue *q, int data) {
    // 判断队列是否已满
    if (isFull(q) == 1) {
        printf("当前队列已满，入队列失败。\n");
        return 0;
    } else {
        // 求出队列尾部的序号
        q->tail = (q->tail + 1) % MAXSIZE;
        q->data[q->tail] = data;
        return 1;
    }
}

// 出队列
int pop(Queue *q) {
    // 队列为空
    if (isEmpty(q) == 1) {
        printf("当前队列为空。\n");
        return NULL;
    } else {
        q->head = (q->head + 1) % MAXSIZE;
        return q->data[q->head];
    }
}

// 获取第一个位置的数据
int top(Queue *q) {
    if (isEmpty(q) == 1) {
        printf("队列已经空了");
        return NULL;
    }
    return q->data[(q->head + 1) % MAXSIZE];
}

// 求队列的长度
int length(Queue *q) {
    int n = q->tail - q->head;
    if (n < 0)
        return MAXSIZE + n;
    return n;
}

// 显示队列全部元素
void show(Queue *q)
{
    if (length(q)==0)
        printf("当前队列为空，没有元素");
    int i ;
    for (i = 1; i <= length(q); ++i) {
        int j = q->head + i ;
        if(j>=MAXSIZE)
            j = j%MAXSIZE ;
        printf("%d\t",q->data[j]);
    }
}
int main() {

    // 初始化一个循环队列
    Queue *q = init();

    int i;
    for (i = 0; i < 9; ++i) {
        push(q, i);
    }

    printf("当前队列元素为：");
    show(q);

    for (i = 1; i < 10; ++i) {
        pop(q);
    }

    printf("\n队列的长度为：%d\n", length(q));
    printf("此时的头和尾分别是：%d\t%d\n",q->head,q->tail);

    for (i = 1; i < 5; ++i) {
        push(q, i);
    }
    printf("当前队列元素为：");
    show(q);

    printf("\n此时的头和尾分别是：%d\t%d",q->head,q->tail);
    return 0;
}