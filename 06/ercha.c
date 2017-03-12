#include <stdio.h>
#include <malloc.h>

#define LENGTH 10

int sourceArray[] = {54, 20, 6, 70, 12, 37, 92, 28, 65, 83};

typedef struct binaryTree {
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
} BinarySortTree;

/**
 * 在一个二叉树中插入元素
 * @param t ：二叉排序树
 * @param key：关键字
 */
void insert(BinarySortTree *t, int key) {
    BinarySortTree *p, *parent, *head;

    //申请内存空间
    p = (BinarySortTree *) malloc(sizeof(BinarySortTree *));
    if (!p) {
        printf("申请内存出错!\n");
        exit(0);
    }

    //保存结点数据
    p->data = key;
    //左右子树置空
    p->left = p->right = NULL;
    head = t;

    //查找需要添加的父结点
    while (head) {
        parent = head;
        if (key < head->data) //若关键字小于结点的数据
            head = head->left; //在左子树上查找
        else                 //若关键字大于结点的数据 
            head = head->right;  //在右子树上查找
    }
    //判断添加到左子树还是右子树 
    if (key < parent->data) {
        //小于父结点，添加到左子树
        parent->left = p;
    } else {
        //大于父结点，添加到右子树
        parent->right = p;
    }
}

/**
 * 创建二叉排序树，通过上面所定义的插入函数
 * @param t ：二叉树
 * @param data ：数据源数组
 * @param n ：个数
 */
void create(BinarySortTree *t, int data[], int n) {
    int i;
    t->data = data[0];
    t->left = t->right = NULL;
    for (i = 1; i < n; i++) {
        insert(t, data[i]);
    }
}

/**
 * 中序遍历
 * @param t
 */
void inOrder(BinarySortTree *t) {
    if (t)//树不为空，则执行如下操作
    {
        inOrder(t->left); //中序遍历左子树
        printf("%d ", t->data); //输出结点数据
        inOrder(t->right); //中序遍历右子树/
    }
    return;
}

BinarySortTree *search(BinarySortTree *t, int key) {
    if (!t || t->data == key) //结点为空，或关键字相等
        return t;          //返回结点指针
    else if (key > t->data) //关键字大于结点数据
        return (search(t->right, key));
    else
        return (search(t->left, key));
}

//删除结点
void delete(BinarySortTree *t, int key) {
    BinarySortTree *p, *parent, *l, *l1;
    int child = 0;//0表示左子树，1表示右子树
    if (!t)
        return;     //二叉排序树为空，则退出

    p = t;

    parent = p;
    while (p)           //二叉排序树有效
    {
        if (p->data == key) {
            //叶结点(左右子树都为空)
            if (!p->left && !p->right) {
                if (p == t) //被删除的是根结点
                {
                    free(p);//释放被删除结点 
                } else if (child == 0) //父结点为左子树
                {
                    parent->left = NULL; //设置父结点左子树为空
                    free(p); //释放结点空间 
                } else //父结点为右子树
                {
                    parent->right = NULL; //设置父结点右子树为空
                    free(p); //释放结点空间 
                }
            }
                //左子树为空，右子树不为空
            else if (!p->left) {
                if (child == 0) //是父结点的左子树
                    parent->left = p->right;
                else //是父结点的右子树             
                    parent->left = p->left;
                free(p); //释放被删除结点
            }
                //右子树为空，左子树不为空
            else if (!p->right)
            {
                if (child == 0) //是父结点的左子树
                    parent->right = p->right;
                else //是父结点的右子树             
                    parent->right = p->left;
                free(p); //释放被删除结点       
            }
                //左右子树都不为空
            else
            {
                l1 = p; //保存左子树的父结点
                l = p->right; //从当前结点的右子树进行查找
                while (l->left) //左子树不为空
                {
                    l1 = l;
                    l = l->left; //查找左子树
                }
                p->data = l->data; //将左子树的数据保存到被删除结点
                l1->left = NULL; //设置父结点的左子树指针为空
                free(l1); //释放左子树占的内存空间
            }
            p = NULL;
        }
        else if (key < p->data) //需删除记录的关键字小于结点的数据
        {
            child = 0;//标记在当前结点左子树查找
            parent = p; //保存当前结点作父结点
            p = p->left; //查找右子树
        }
        else //需删除记录的关键字大于结点的数据
        {
            child = 1;//标记在当前结点右子树查找
            parent = p;//保存当前结点作父结点
            p = p->right; //查找右子树
        }
    }
}

int main() {
    int i;
    BinarySortTree *tree; //保存二叉排序树根结点
    printf("原数据:");
    for (i = 0; i < LENGTH; i++)
        printf("%d 、", sourceArray[i]);
    printf("\n");

    create(tree, sourceArray, LENGTH);
    printf("遍历二叉排序树:");
    inOrder(tree);
    return 0;
}
