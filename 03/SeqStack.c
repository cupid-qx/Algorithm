//
// Created by qcq on 2017/2/25.
//
#include <malloc.h>
#include <stdio.h>

#define MAXSIZE 10
// 定义顺序栈的基本结构
typedef struct stack {
    int data[MAXSIZE + 1]; // 保存栈元素
    int top; // 栈顶
} Stack;

Stack *init() {
    Stack *s;
    s = (Stack *) malloc(sizeof(Stack));
    if (s == NULL) {
        printf("分配空间失败");
        return NULL;
    }
    // 设置栈顶为 0
    s->top = 0;
    // 返回指向栈的指针
    return s;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    if (s->top == 0)
        return 1;

    return 0;
}

// 释放站所占的内存空间
void freeStack(Stack *s) {
    if (s)
        free(s);
}

// 清空栈
void clear(Stack *s) {
    s->top = 0;
}

// 判断栈是否已满
int isFull(Stack *s) {
    if (s->top == MAXSIZE)
        return 1;

    return 0;
}

// 入栈操作
int push(Stack *s, int data) {
    // 判断能否入栈
    if (isFull(s) == 1) {
        printf("栈已满，入栈操作失败");
        return 0;
    }
    s->top++;
    s->data[s->top] = data;

    return 1;
}

// 出栈操作
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("栈已空，出栈操作失败");
        exit(0);
    }

    int res = s->data[s->top];
    // 栈顶指向下一个位置
    s->top--;

    return res;
}

// 读出栈顶数据
int peek(Stack *s) {
    // 栈为空的时候
    if (isEmpty(s) == 1)
        exit(0);

    return s->data[s->top];
}

int main() {

    Stack *stack1;

    // 对栈进行初始化
    stack1 = init();

    int i;
    for (i = 1; i < 10; ++i)
        push(stack1, i);
    printf("当前栈顶的元素为：%d\n", peek(stack1));

    pop(stack1);

    printf("当前栈顶的元素为：%d\n", peek(stack1));


    return 0;
}