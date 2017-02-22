#include <string.h>

ChainList *addEnd(ChainList *head, DATA data)  //添加结点到链表结尾
{
    ChainList *node, *h;
    if (!(node = (ChainList *) malloc(sizeof(ChainList)))) {
        printf("为保存结点数据申请内存失败！\n");
        return NULL;  //分配内存失败 
    }
    node->data = data; //保存数据
    node->next = NULL;  //设置结点指针为空，即为表尾
    if (head == NULL)  //是头指针
    {
        head = node;
        return head;
    }
    h = head;
    while (h->next != NULL) //查找链表的末尾
        h = h->next;
    h->next = node;
    return head;
}

ChainList *addFirst(ChainList *head, DATA data) {
    ChainList *node, *h;
    if (!(node = (ChainList *) malloc(sizeof(ChainList)))) {
        printf("为保存结点数据申请内存失败！\n");
        return NULL;  //分配内存失败 
    }
    node->data = data; //保存数据
    node->next = head;  //指向头指针所指结点
    head = node;        //头指针指向新增结点
    return head;
}

ChainList *insert(ChainList *head, char *findkey, DATA data)  //插入结点到链表指定位置
{
    ChainList *node, *node1;
    if (!(node = (ChainList *) malloc(sizeof(ChainList)))) //分配保存结点的内容
    {
        printf("为保存结点数据申请内存失败！\n");
        return 0;  //分配内存失败 
    }
    node->data = data;  //保存结点中的数据
    node1 = find(head, findkey);
    if (node1)  //若找到要插入的结点
    {
        node->next = node1->next;  //新插入结点指向关键结点的下一结点
        node1->next = node;    //设置关键结点指向新插入结点
    } else {
        free(node);//释放内存
        printf("未找到插入位置！\n");
    }
    return head;//返回头指针
}

ChainList *find(ChainList *head, char *key) //按关键字在链表中查找内容
{
    ChainList *h;
    h = head;       //保存链表头指针
    while (h)      //若结点有效，则进行查找
    {
        if (strcmp(h->data.key, key) == 0) //若结点关键字与传入关键字相同
            return h;  //返回该结点指针 
        h = h->next; //处理下一结点
    }
    return NULL; //返回空指针 
}

int delete(ChainList *head, char *key) {
    ChainList *node, *h; //node保存删除结点的前一结点
    node = h = head;
    while (h) {
        if (strcmp(h->data.key, key) == 0) //找到关键字，执行删除操作
        {
            node->next = h->next;  //使前一结点指向当前结点的下一结点
            free(h);  //释放内存 
            return 1;
        } else {
            node = h;  //指向当前结点
            h = h->next; //指向下一结点
        }
    }
    return 0;//未删除
}

int length(ChainList *head)//获取链表结点数量
{
    ChainList *h;
    int i = 0;
    h = head;
    while (h)      //遍历整个链表
    {
        i++; //累加结点数量 
        h = h->next;//处理下一结点
    }
    return i;//返回结点数量 
}
