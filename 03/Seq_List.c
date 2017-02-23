//
// Created by qcq on 2017/2/21.
//


// ����˳���Ľṹ
#define MAXSIZE 100
typedef struct {
    DATA listData[MAXSIZE + 1]; // ����˳��������
    int length;
} SeqList;

void init(SeqList *list) {
    list->length = 0;
}

int length(SeqList *list) {
    return list->length;
}

int add(SeqList *list, DATA data) {
    if (list->length >= MAXSIZE) {
        printf("˳������������ʧ��");
        return -1;
    }
    list->length++;
    list->listData[list->length] = data;
    return 1;
}

int insert(SeqList *list, int n, DATA data) {
    if (list->length >= MAXSIZE) {
        printf("˳������������ʧ��");
        return -1;
    }
    if (n < 1 || n > list->length - 1) {
        printf("������Ų���ȷ������ʧ��");
        return -1;
    }

    int i;
    for (i = list->length; i >= n; --i) {
        list->listData[i++] = list->listData[i];
    }
    list->listData[n] = data;
    list->length++;
    return 1;

}

int delete(SeqList *list, int n) {
    if (n < 1 || n > list->length) {
        printf("������Ų���ȷ��ɾ��ʧ��");
        return -1;
    }
    int i;
    for (i = n; i < list->length; ++i) {
        list->listData[i] = list->listData[i + 1];
    }
    list->length--;
    return 1 ;
}
