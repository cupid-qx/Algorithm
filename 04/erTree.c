#include <stdio.h> 
#include <stdlib.h> 

#define QUEUE_MAXSIZE 50

// ����������е�Ԫ������
typedef char DATA;

// ����������еĽڵ�����
typedef struct Node {
    // Ԫ��
    DATA element;
    // ������
    struct Node *leftChild;
    // ������
    struct Node *rightChild;
} BinaryTree;

// ��ʼ�����������ڵ�
BinaryTree *init(BinaryTree *root) {
    // �����������ڵ㲻Ϊ��
    if(root !=NULL)
        return root ;
    root = (BinaryTree *) malloc(sizeof(BinaryTree));
    return root;
}

/**
 * ��������еĽڵ���Ӻ��ӽڵ�
 * @param parent�����׽ڵ�
 * @param node ��Ҫ��ӵĽڵ�
 * @param n ����ӵ�λ�ã�1��ʾ��ڵ㣬2��ʾ�ҽڵ�
 * @return
 */
int addNode(BinaryTree *parent, BinaryTree *node, int n) {
    if (parent == NULL) {
        printf("���׽ڵ㲻���ڣ����ʧ��");
        return 0;
    }
    switch (n) {
        case 1:
            // ��ӵ���ڵ�
            if (parent->leftChild) {
                // ��ڵ㲻Ϊ��
                printf("��ڵ㲻Ϊ�գ����ʧ��");
                return 0;
            } else
                parent->leftChild = node;
            break;

        case 2:
            // ��ӵ��ҽڵ�
            if (parent->rightChild) {
                // �ҽڵ㲻Ϊ��
                printf("�ҽڵ㲻Ϊ�գ����ʧ��");
                return 0;
            } else
                parent->rightChild = node;
            break;

        default:
            printf("�����������");
            return 0;
    }
    return 1;
}

/**
 * ��ø��׽ڵ�����ӽڵ�
 * @param parent �����׽ڵ�
 * @return �������ӽڵ��Ԫ��ֵ�������ڷ���NULL
 */
DATA getLeft(BinaryTree *parent) {
    if (parent->leftChild)
        return parent->leftChild->element;
    else
        return NULL;
}

/**
 * ��ø��׽ڵ�����ӽڵ�
 * @param parent �����׽ڵ�
 * @return �������ӽڵ��Ԫ��ֵ�������ڷ���NULL
 */
DATA getRight(BinaryTree *parent) {
    if (parent->rightChild)
        return parent->rightChild->element;
    else
        return NULL;
}

/**
 * �п�
 * @param root���������ڵ�
 * @return
 */
int isEmpty(BinaryTree *root) {
    if (root)
        return 0;
    else
        return 1;
}

/**
 * ������������
 * @param root
 * @return �ݹ��������������������ȡ���ֵ
 */
int deepth(BinaryTree *root) {
    int dep1, dep2;
    if (root == NULL)
        return 0; //���ڿ��������Ϊ0
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
 * ���Ҷ��������Ƿ����ĳԪ��
 * @param root ���������ĸ��ڵ�
 * @param data ��Ҫ���ҵ�����
 * @return ��1������0������
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
 * ǰ�����
 * @param root
 */
void preOrder(BinaryTree *root) {
    if (root) {
        printf("%c��", root->element);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
    return;
}

/**
 * �������
 * @param root
 */
void inOrder(BinaryTree *root) {
    if (root) {
        inOrder(root->leftChild);
        printf("%c��", root->element);
        inOrder(root->rightChild);
    }
    return;
}

/**
 * �������
 * @param root
 */
void postOrder(BinaryTree *root) {
    if (root) {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%c��", root->element);
    }
    return;
}

/**
 * �������
 * @param root
 */
void levelOrder(BinaryTree *root) //�������
{
    BinaryTree *p;
    BinaryTree *q[QUEUE_MAXSIZE]; //����һ��˳��ջ
    int head = 0, tail = 0;//���ס���β���
    if (root)//������ָ�벻Ϊ��
    {
        tail = (tail + 1) % QUEUE_MAXSIZE;//����ѭ�����ж�β���
        q[tail] = root;//����������ָ�����
    }
    while (head != tail) //���в�Ϊ�գ�����ѭ��
    {
        head = (head + 1) % QUEUE_MAXSIZE; //����ѭ�����еĶ������
        p = q[head]; //��ȡ����Ԫ��
        printf("%c��", root->element);//�������Ԫ��
        if (p->leftChild != NULL) //���ڵ��������������������ָ�����
        {
            tail = (tail + 1) % QUEUE_MAXSIZE;//����ѭ�����еĶ�β���
            q[tail] = p->leftChild;//��������ָ�����
        }

        if (p->rightChild != NULL)//���ڵ�����Һ��ӣ����Һ��ӽڵ�ָ�����
        {
            tail = (tail + 1) % QUEUE_MAXSIZE;//����ѭ�����еĶ�β���
            q[tail] = p->rightChild;//��������ָ�����
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

    printf("���ڵ�����������������ֱ��ǣ�%c,%c\n",getLeft(root),getRight(root));
    preOrder(root);

    printf("\n���ĸ߶��ǣ�%d",deepth(root));
    return 0;
}
