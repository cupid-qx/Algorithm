
#include <malloc.h>
#include <stdio.h>

#define LIST_SIZE 10
#define OVERFLOW -2
#define OK 1
#define ERROR 0
/**
 * @author Cupid
 * @date: 2017/2/22
 */

typedef struct {
    int *iElement;
    int iLength;
    int iListSize;
} SeqList;

/**
 *
 * @param L : �����д��ݲ�����ָ����L��ֻ���������ܸı�ָ���Ԫ��
 * @return
 */
int initList(SeqList *L) {
    int i;
    L->iElement = (int *) malloc(LIST_SIZE * sizeof(int));
    if (!L->iElement)
        exit(OVERFLOW);
    L->iLength = 10;
    L->iListSize = LIST_SIZE; //�����ʼ�Ŀռ�

    for (i = 0; i < L->iLength; ++i) {
        L->iElement[i] = i;
    }

    return OK;
}

// �������Ա���
int length(SeqList *L) {
    return L->iLength;
}

int destroy(SeqList *L) {
    L->iLength = 0;
    return OK;
}

// �����Ա��е�i��λ�ò���e
int insert(SeqList *L, int i, int e) {
    int *newBase, *q, *p;
    if (i < 1 || i > L->iLength + 1)
        return ERROR;

    if (L->iLength >= L->iListSize) {
        newBase = (int *) realloc(L->iElement, (L->iListSize + LIST_SIZE) * sizeof(int));
        //����ʧ��
        if (!newBase)
            exit(OVERFLOW);
        L->iElement = newBase;
        L->iListSize += LIST_SIZE;
    }

    q = &(L->iElement[i - 1]);

    // ��q֮��Ԫ������ƶ�
    for (p = &(L->iElement[L->iLength - 1]); p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    ++L->iLength;
    return OK;
}

// ɾ�����Ա�L�еĵ� i ��Ԫ�أ���������ֵ
int delete(SeqList *L, int i, int e) {
    int *p, *q;
    if (i < 1 || i > L->iLength)
        return ERROR;

    // ���Ҫɾ����Ԫ��
    p = &(L->iElement[i - 1]);
    // ȡ��Ԫ��ֵ
    e = *p;
    // ���Ա�����λ��
    q = L->iElement + L->iLength - 1;

    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    --L->iLength;
    return OK;
}

int display(SeqList *L) {
    int i;
    for (i = 0; i < L->iLength; ++i) {
        printf("%d", L->iElement[i]);
        printf(" ");
    }

    return OK;
}

int main() {

    SeqList L;
    int operator, e = 0;
    int i, num;

    initList(&L);

    do {
        printf("��������Ҫ���еĲ������\n");
        printf("1.���Ա����\n");
        printf("2.������Ա���\n");
        printf("3.����Ԫ��\n");
        printf("4.ɾ��Ԫ��\n");
        printf("5.��ʾȫ��Ԫ��\n");
        printf("6.�˳�\n");
        scanf("%d", &operator);
        switch (operator) {
            case 1:
                destroy(&L);
                break;
            case 2:
                printf("�����Ա�ĳ���Ϊ%d\n", length(&L));
                break;
            case 3:
                //��ָ����λ���ϲ���ָ��������Ԫ��
                printf("��������Ҫ�����Ԫ�ص�λ�ã����ڵ�i��Ԫ��֮ǰ���룩�Լ�����Ԫ��\n");
                scanf("%d %d", &i, &num);
                insert(&L, i, num);
                printf("�µ����Ա���\n");
                display(&L);
                break;
            case 4:
                //ɾ��ָ��λ�õ�����Ԫ��
                printf("��������Ҫɾ����Ԫ�ص�λ�ã���ɾ����i��Ԫ�أ�\n");
                scanf("%d", &i);
                delete(&L, i, e);
                printf("�µ����Ա���\n");
                display(&L);
                break;
            case 5:
                //��ʾ���Ա������Ԫ��
                display(&L);
                printf("\n");
                break;
            case 6:
                //�˳�����
                break;
        }
    } while (operator != 6);
    return OK;
}




