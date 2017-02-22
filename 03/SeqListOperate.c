
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
 * @param L : 括号中传递参数是指针型L，只有这样才能改变指向的元素
 * @return
 */
int initList(SeqList *L) {
    int i;
    L->iElement = (int *) malloc(LIST_SIZE * sizeof(int));
    if (!L->iElement)
        exit(OVERFLOW);
    L->iLength = 10;
    L->iListSize = LIST_SIZE; //分配初始的空间

    for (i = 0; i < L->iLength; ++i) {
        L->iElement[i] = i;
    }

    return OK;
}

// 返回线性表长度
int length(SeqList *L) {
    return L->iLength;
}

int destroy(SeqList *L) {
    L->iLength = 0;
    return OK;
}

// 在线性表中第i个位置插入e
int insert(SeqList *L, int i, int e) {
    int *newBase, *q, *p;
    if (i < 1 || i > L->iLength + 1)
        return ERROR;

    if (L->iLength >= L->iListSize) {
        newBase = (int *) realloc(L->iElement, (L->iListSize + LIST_SIZE) * sizeof(int));
        //分配失败
        if (!newBase)
            exit(OVERFLOW);
        L->iElement = newBase;
        L->iListSize += LIST_SIZE;
    }

    q = &(L->iElement[i - 1]);

    // 将q之后元素向后移动
    for (p = &(L->iElement[L->iLength - 1]); p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    ++L->iLength;
    return OK;
}

// 删除线性表L中的第 i 个元素，返回它的值
int delete(SeqList *L, int i, int e) {
    int *p, *q;
    if (i < 1 || i > L->iLength)
        return ERROR;

    // 获得要删除的元素
    p = &(L->iElement[i - 1]);
    // 取出元素值
    e = *p;
    // 线性表最后的位置
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
        printf("请输入你要进行的操作序号\n");
        printf("1.线性表清空\n");
        printf("2.获得线性表长度\n");
        printf("3.插入元素\n");
        printf("4.删除元素\n");
        printf("5.显示全部元素\n");
        printf("6.退出\n");
        scanf("%d", &operator);
        switch (operator) {
            case 1:
                destroy(&L);
                break;
            case 2:
                printf("改线性表的长度为%d\n", length(&L));
                break;
            case 3:
                //在指定的位置上插入指定的数据元素
                printf("请输入你要插入的元素的位置（即在第i个元素之前插入）以及插入元素\n");
                scanf("%d %d", &i, &num);
                insert(&L, i, num);
                printf("新的线性表是\n");
                display(&L);
                break;
            case 4:
                //删除指定位置的数据元素
                printf("请输入你要删除的元素的位置（即删除第i个元素）\n");
                scanf("%d", &i);
                delete(&L, i, e);
                printf("新的线性表是\n");
                display(&L);
                break;
            case 5:
                //显示线性表的所有元素
                display(&L);
                printf("\n");
                break;
            case 6:
                //退出程序
                break;
        }
    } while (operator != 6);
    return OK;
}




