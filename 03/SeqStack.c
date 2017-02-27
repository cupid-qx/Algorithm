//
// Created by qcq on 2017/2/25.
//
#include <malloc.h>
#include <stdio.h>

#define MAXSIZE 10
// ����˳��ջ�Ļ����ṹ
typedef struct stack {
    int data[MAXSIZE + 1]; // ����ջԪ��
    int top; // ջ��
} Stack;

Stack *init() {
    Stack *s;
    s = (Stack *) malloc(sizeof(Stack));
    if (s == NULL) {
        printf("����ռ�ʧ��");
        return NULL;
    }
    // ����ջ��Ϊ 0
    s->top = 0;
    // ����ָ��ջ��ָ��
    return s;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack *s) {
    if (s->top == 0)
        return 1;

    return 0;
}

// �ͷ�վ��ռ���ڴ�ռ�
void freeStack(Stack *s) {
    if (s)
        free(s);
}

// ���ջ
void clear(Stack *s) {
    s->top = 0;
}

// �ж�ջ�Ƿ�����
int isFull(Stack *s) {
    if (s->top == MAXSIZE)
        return 1;

    return 0;
}

// ��ջ����
int push(Stack *s, int data) {
    // �ж��ܷ���ջ
    if (isFull(s) == 1) {
        printf("ջ��������ջ����ʧ��");
        return 0;
    }
    s->top++;
    s->data[s->top] = data;

    return 1;
}

// ��ջ����
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("ջ�ѿգ���ջ����ʧ��");
        exit(0);
    }

    int res = s->data[s->top];
    // ջ��ָ����һ��λ��
    s->top--;

    return res;
}

// ����ջ������
int peek(Stack *s) {
    // ջΪ�յ�ʱ��
    if (isEmpty(s) == 1)
        exit(0);

    return s->data[s->top];
}

int main() {

    Stack *stack1;

    // ��ջ���г�ʼ��
    stack1 = init();

    int i;
    for (i = 1; i < 10; ++i)
        push(stack1, i);
    printf("��ǰջ����Ԫ��Ϊ��%d\n", peek(stack1));

    pop(stack1);

    printf("��ǰջ����Ԫ��Ϊ��%d\n", peek(stack1));


    return 0;
}