#include <string.h>
#include <malloc.h>
#include <stdio.h>

//数据结点类型
typedef struct Node {
    DATA data;
    struct Node *next;
} ChainList;

ChainList *addEnd(ChainList *head, DATA data) {
    ChainList *node;
    ChainList *h;

    // 分配内存空间，构造出链表节点
    node = (ChainList *) malloc(sizeof(ChainList));
    // 构造失败，返回空
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
// 错误的写法，虽然当前传入的是构造的空链表，但不能直接返回构造的节点
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
    // 构造节点
    ChainList *node = (ChainList *) malloc(sizeof(ChainList));
    if (node == NULL) {
        printf("申请内存失败");
        return NULL;
    }
    node->data = data;

    // 插入到头部
    // 如果链表为空
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
    // 没有匹配，返回空指针
    return NULL;
}

ChainList *insert(ChainList *head, char *key, DATA data) {
    // 构造节点
    ChainList *node = (ChainList *) malloc(sizeof(ChainList));
    if (!node) {
        printf("申请内存失败");
        return NULL;
    }
    node->data = data;

    // 查找要插入节点的位置
    ChainList *node1;
    node1 = find(head, key);
    if (node1) {
        node->next = node1->next;
        node1->next = node;
    } else {
        free(node);
        printf("未找到位置");
    }

    return head;
}


int delete(ChainList *head, char *key) {
    ChainList *temp, *node;
    temp = node = head;
    while (temp) {
        if (strcmp(temp->data.key, key) == 0) {
            node->next = temp->next;
            free(temp);//释放内存
            return 1;
        } else {
            // node 指向当前结点，temp 指向下一个节点
            node = temp;
            temp = temp->next;
        }
    }
    // 删除失败
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
