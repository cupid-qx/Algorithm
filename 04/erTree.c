#include <stdio.h> 
#include <stdlib.h> 

#define QUEUE_MAXSIZE 50

// 定义二叉树中的元素类型
typedef char DATA;

// 定义二叉树中的节点类型
typedef struct Node {
    // 元素
    DATA element;
    // 左子树
    struct Node *leftChild;
    // 右子树
    struct Node *rightChild;
} BinaryTree;

// 初始化二叉树根节点
BinaryTree *init(BinaryTree *root) {
    // 若二叉树根节点不为空
    if(root !=NULL)
        return root ;
    root = (BinaryTree *) malloc(sizeof(BinaryTree));
    return root;
}

/**
 * 向二叉树中的节点添加孩子节点
 * @param parent：父亲节点
 * @param node ：要添加的节点
 * @param n ：添加的位置，1表示左节点，2表示右节点
 * @return
 */
int addNode(BinaryTree *parent, BinaryTree *node, int n) {
    if (parent == NULL) {
        printf("父亲节点不存在，添加失败");
        return 0;
    }
    switch (n) {
        case 1:
            // 添加到左节点
            if (parent->leftChild) {
                // 左节点不为空
                printf("左节点不为空，添加失败");
                return 0;
            } else
                parent->leftChild = node;
            break;

        case 2:
            // 添加到右节点
            if (parent->rightChild) {
                // 右节点不为空
                printf("右节点不为空，添加失败");
                return 0;
            } else
                parent->rightChild = node;
            break;

        default:
            printf("输入参数错误");
            return 0;
    }
    return 1;
}

/**
 * 获得父亲节点的左子节点
 * @param parent ：父亲节点
 * @return ：返回子节点的元素值，不存在返回NULL
 */
DATA getLeft(BinaryTree *parent) {
    if (parent->leftChild)
        return parent->leftChild->element;
    else
        return NULL;
}

/**
 * 获得父亲节点的右子节点
 * @param parent ：父亲节点
 * @return ：返回子节点的元素值，不存在返回NULL
 */
DATA getRight(BinaryTree *parent) {
    if (parent->rightChild)
        return parent->rightChild->element;
    else
        return NULL;
}

/**
 * 判空
 * @param root：二叉树节点
 * @return
 */
int isEmpty(BinaryTree *root) {
    if (root)
        return 0;
    else
        return 1;
}

/**
 * 求二叉树的深度
 * @param root
 * @return 递归遍历左子树和右子树，取最大值
 */
int deepth(BinaryTree *root) {
    int dep1, dep2;
    if (root == NULL)
        return 0; //对于空树，深度为0
    else {
        dep1 = deepth(root->leftChild);
        dep2 = deepth(root->rightChild);
        if (dep1 > dep2)
            return dep1 + 1;
        else
            return dep2 + 1;
    }
}

/**
 * 查找二叉树中是否包含某元素
 * @param root ：二叉树的根节点
 * @param data ：要查找的数据
 * @return ：1包含，0不包含
 */
int search(BinaryTree *root, DATA data) {
    if (root == NULL)
        return 0;
    else {
        if (root->element == data)
            return 1;
        else {
            if (search(root->leftChild, data) == 1)
                return 1;
            else if (search(root->rightChild, data) == 1)
                return 1;
            else
                return 0;
        }
    }
}

void clear(BinaryTree *root) {
    if (root) {
        clear(root->leftChild);
        clear(root->rightChild);
        free(root);
        root = NULL;
    }
    return;
}

/**
 * 前序遍历
 * @param root
 */
void preOrder(BinaryTree *root) {
    if (root) {
        printf("%c、", root->element);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
    return;
}

/**
 * 中序遍历
 * @param root
 */
void inOrder(BinaryTree *root) {
    if (root) {
        inOrder(root->leftChild);
        printf("%c、", root->element);
        inOrder(root->rightChild);
    }
    return;
}

/**
 * 后序遍历
 * @param root
 */
void postOrder(BinaryTree *root) {
    if (root) {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%c、", root->element);
    }
    return;
}

/**
 * 按层遍历
 * @param root
 */
void levelOrder(BinaryTree *root) //按层遍历
{
    BinaryTree *p;
    BinaryTree *q[QUEUE_MAXSIZE]; //定义一个顺序栈
    int head = 0, tail = 0;//队首、队尾序号
    if (root)//若队首指针不为空
    {
        tail = (tail + 1) % QUEUE_MAXSIZE;//计算循环队列队尾序号
        q[tail] = root;//将二叉树根指针进队
    }
    while (head != tail) //队列不为空，进行循环
    {
        head = (head + 1) % QUEUE_MAXSIZE; //计算循环队列的队首序号
        p = q[head]; //获取队首元素
        printf("%c、", root->element);//处理队首元素
        if (p->leftChild != NULL) //若节点存在左子树，则左子树指针进队
        {
            tail = (tail + 1) % QUEUE_MAXSIZE;//计算循环队列的队尾序号
            q[tail] = p->leftChild;//将左子树指针进队
        }

        if (p->rightChild != NULL)//若节点存在右孩子，则右孩子节点指针进队
        {
            tail = (tail + 1) % QUEUE_MAXSIZE;//计算循环队列的队尾序号
            q[tail] = p->rightChild;//将右子树指针进队
        }
    }
    return;
}

int main() {

    BinaryTree *root=NULL;
    root = init(root);

    root->element = 'A';
    root->leftChild = NULL;
    root->rightChild = NULL;

    BinaryTree *temp = NULL;
    temp = init(temp);

    temp->element = 'A' + 1;
    temp->rightChild = NULL;
    temp->leftChild = NULL;

    addNode(root, temp, 1);

    printf("根节点的左子树和右子树分别是：%c,%c\n",getLeft(root),getRight(root));
    preOrder(root);

    printf("\n树的高度是：%d",deepth(root));
    return 0;
}
