#include <string.h>
#include <malloc.h>
#include <stdio.h>

//���ݽ������
typedef struct Node {
    DATA data;
    struct Node *next;
} ChainList;

ChainList *addEnd(ChainList *head, DATA data) {
    ChainList *node;
    ChainList *h;

    // �����ڴ�ռ䣬���������ڵ�
    node = (ChainList *) malloc(sizeof(ChainList));
    // ����ʧ�ܣ����ؿ�
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
// �����д������Ȼ��ǰ������ǹ���Ŀ�����������ֱ�ӷ��ع���Ľڵ�
//    if(head == NULL)
//        return node ;
    if (head == NULL) {
        head = node;
        return head;
    }

    h = head;
    while (h->next) {
        h = h->next;
    }
    h->next = node;

    return head;
}

ChainList *addFirst(ChainList *head, DATA data) {
    // ����ڵ�
    ChainList *node = (ChainList *) malloc(sizeof(ChainList));
    if (node == NULL) {
        printf("�����ڴ�ʧ��");
        return NULL;
    }
    node->data = data;

    // ���뵽ͷ��
    // �������Ϊ��
    if (head == NULL) {
        head = node;
        return head;
    }
    node->next = head;
    head = node;

    return head;
}


ChainList *find(ChainList *head, char *key) {
    ChainList *temp;
    temp = head;
    while (temp) {
        if (strcmp(temp->data.key, key) == 0)
            return temp;
        temp = temp->next;
    }
    // û��ƥ�䣬���ؿ�ָ��
    return NULL;
}

ChainList *insert(ChainList *head, char *key, DATA data) {
    // ����ڵ�
    ChainList *node = (ChainList *) malloc(sizeof(ChainList));
    if (!node) {
        printf("�����ڴ�ʧ��");
        return NULL;
    }
    node->data = data;

    // ����Ҫ����ڵ��λ��
    ChainList *node1;
    node1 = find(head, key);
    if (node1) {
        node->next = node1->next;
        node1->next = node;
    } else {
        free(node);
        printf("δ�ҵ�λ��");
    }

    return head;
}


int delete(ChainList *head, char *key) {
    ChainList *temp, *node;
    temp = node = head;
    while (temp) {
        if (strcmp(temp->data.key, key) == 0) {
            node->next = temp->next;
            free(temp);//�ͷ��ڴ�
            return 1;
        } else {
            // node ָ��ǰ��㣬temp ָ����һ���ڵ�
            node = temp;
            temp = temp->next;
        }
    }
    // ɾ��ʧ��
    return 0;
}

int length(ChainList *head) {
    ChainList *temp;
    int count = 0;
    temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    return count;
}
