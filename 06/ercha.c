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
 * ��һ���������в���Ԫ��
 * @param t ������������
 * @param key���ؼ���
 */
void insert(BinarySortTree *t, int key) {
    BinarySortTree *p, *parent, *head;

    //�����ڴ�ռ�
    p = (BinarySortTree *) malloc(sizeof(BinarySortTree *));
    if (!p) {
        printf("�����ڴ����!\n");
        exit(0);
    }

    //����������
    p->data = key;
    //���������ÿ�
    p->left = p->right = NULL;
    head = t;

    //������Ҫ��ӵĸ����
    while (head) {
        parent = head;
        if (key < head->data) //���ؼ���С�ڽ�������
            head = head->left; //���������ϲ���
        else                 //���ؼ��ִ��ڽ������� 
            head = head->right;  //���������ϲ���
    }
    //�ж���ӵ����������������� 
    if (key < parent->data) {
        //С�ڸ���㣬��ӵ�������
        parent->left = p;
    } else {
        //���ڸ���㣬��ӵ�������
        parent->right = p;
    }
}

/**
 * ����������������ͨ������������Ĳ��뺯��
 * @param t ��������
 * @param data ������Դ����
 * @param n ������
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
 * �������
 * @param t
 */
void inOrder(BinarySortTree *t) {
    if (t)//����Ϊ�գ���ִ�����²���
    {
        inOrder(t->left); //�������������
        printf("%d ", t->data); //����������
        inOrder(t->right); //�������������/
    }
    return;
}

BinarySortTree *search(BinarySortTree *t, int key) {
    if (!t || t->data == key) //���Ϊ�գ���ؼ������
        return t;          //���ؽ��ָ��
    else if (key > t->data) //�ؼ��ִ��ڽ������
        return (search(t->right, key));
    else
        return (search(t->left, key));
}

//ɾ�����
void delete(BinarySortTree *t, int key) {
    BinarySortTree *p, *parent, *l, *l1;
    int child = 0;//0��ʾ��������1��ʾ������
    if (!t)
        return;     //����������Ϊ�գ����˳�

    p = t;

    parent = p;
    while (p)           //������������Ч
    {
        if (p->data == key) {
            //Ҷ���(����������Ϊ��)
            if (!p->left && !p->right) {
                if (p == t) //��ɾ�����Ǹ����
                {
                    free(p);//�ͷű�ɾ����� 
                } else if (child == 0) //�����Ϊ������
                {
                    parent->left = NULL; //���ø����������Ϊ��
                    free(p); //�ͷŽ��ռ� 
                } else //�����Ϊ������
                {
                    parent->right = NULL; //���ø����������Ϊ��
                    free(p); //�ͷŽ��ռ� 
                }
            }
                //������Ϊ�գ���������Ϊ��
            else if (!p->left) {
                if (child == 0) //�Ǹ�����������
                    parent->left = p->right;
                else //�Ǹ�����������             
                    parent->left = p->left;
                free(p); //�ͷű�ɾ�����
            }
                //������Ϊ�գ���������Ϊ��
            else if (!p->right)
            {
                if (child == 0) //�Ǹ�����������
                    parent->right = p->right;
                else //�Ǹ�����������             
                    parent->right = p->left;
                free(p); //�ͷű�ɾ�����       
            }
                //������������Ϊ��
            else
            {
                l1 = p; //�����������ĸ����
                l = p->right; //�ӵ�ǰ�������������в���
                while (l->left) //��������Ϊ��
                {
                    l1 = l;
                    l = l->left; //����������
                }
                p->data = l->data; //�������������ݱ��浽��ɾ�����
                l1->left = NULL; //���ø�����������ָ��Ϊ��
                free(l1); //�ͷ�������ռ���ڴ�ռ�
            }
            p = NULL;
        }
        else if (key < p->data) //��ɾ����¼�Ĺؼ���С�ڽ�������
        {
            child = 0;//����ڵ�ǰ�������������
            parent = p; //���浱ǰ����������
            p = p->left; //����������
        }
        else //��ɾ����¼�Ĺؼ��ִ��ڽ�������
        {
            child = 1;//����ڵ�ǰ�������������
            parent = p;//���浱ǰ����������
            p = p->right; //����������
        }
    }
}

int main() {
    int i;
    BinarySortTree *tree; //������������������
    printf("ԭ����:");
    for (i = 0; i < LENGTH; i++)
        printf("%d ��", sourceArray[i]);
    printf("\n");

    create(tree, sourceArray, LENGTH);
    printf("��������������:");
    inOrder(tree);
    return 0;
}
