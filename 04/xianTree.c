#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef char DATA;       //����Ԫ������ 
typedef enum 
{
    SubTree,
    Thread
}NodeFlag;  //ö��ֵSubTree(����)��Thread(����)�ֱ�Ϊ0��1
typedef struct ThreadTree  //��������������������� 
{
    DATA data;	//Ԫ������
    NodeFlag lflag; //���־ 
    NodeFlag rflag; //�ұ�־ 
    struct ThreadTree *left;	//���������ָ��
    struct ThreadTree *right;	//�������ڵ�ָ��
}ThreadBinTree;

ThreadBinTree *Previous=NULL;     //ǰ���ڵ�ָ�� 

ThreadBinTree *BinTreeInit(ThreadBinTree *node) //��ʼ�����������ڵ� 
{
     if(node!=NULL) //�����������ڵ㲻Ϊ�� 
         return node;
     else
         return NULL;
}
int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n) //������ݵ������� 
//btΪ���ڵ㣬nodeΪ�ӽڵ�,n=1��ʾ�����������n=2��ʾ��������� 
{
    if(bt==NULL)
    {
        printf("���ڵ㲻���ڣ��������ø��ڵ�!\n");
        return 0;
    } 
    switch(n)
    {
        case 1: //��ӵ���ڵ� 
            if(bt->left) //��������Ϊ�� 
            {
                printf("�������ڵ㲻Ϊ��!\n");
                return 0;
            }else
                bt->left=node;
            break;
        case 2://��ӵ��ҽڵ�
            if( bt->right) //��������Ϊ�� 
            {
                printf("�������ڵ㲻Ϊ��!\n"); 
                return 0;
            }else
                bt->right=node;
            break;
        default:
            printf("��������!\n");
            return 0;
    }
    return 1;
}
ThreadBinTree *BinTreeLeft(ThreadBinTree *bt) //�������ӽڵ� 
{
    if(bt)
        return bt->left;
    else
        return NULL;
}
ThreadBinTree *BinTreeRight(ThreadBinTree *bt) //�������ӽڵ� 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}
int BinTreeIsEmpty(ThreadBinTree *bt) //���������Ƿ�Ϊ�գ�Ϊ���򷵻�1,���򷵻�0 
{
    if(bt)
        return 0;
    else
        return 1;
} 
int BinTreeDepth(ThreadBinTree *bt) //����������
{
    int dep1,dep2;
    if(bt==NULL)
        return 0; //���ڿ��������Ϊ0
    else
    {
        dep1 = BinTreeDepth(bt->left); //��������� (�ݹ����)
        dep2 = BinTreeDepth(bt->right); //��������� (�ݹ����)
        if(dep1>dep2)
           return dep1 + 1; 
        else
            return dep2 + 1; 
    } 
} 
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data) //�ڶ������в���ֵΪdata�Ľڵ� 
{
    ThreadBinTree *p;
    if(bt==NULL)
        return NULL;
    else
    {
        if(bt->data==data)
            return bt; 
        else{ // �ֱ������������ݹ���� 
            if(p=BinTreeFind(bt->left,data))
                return p;
            else if(p=BinTreeFind(bt->right, data)) 
                return p;
            else
                return NULL; 
        } 
    } 
} 
void BinTreeClear(ThreadBinTree *bt) // ��ն�������ʹ֮��Ϊһ�ÿ���
{
     if(bt)
     {
         BinTreeClear(bt->left); //��������� 
         BinTreeClear(bt->right);//��������� 
         free(bt);//�ͷŵ�ǰ�ڵ���ռ�ڴ� 
         bt=NULL;
     }
     return; 
}
void BinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p))  //������� 
{     
     if(bt)//����Ϊ�գ���ִ�����²��� 
     {
         oper(bt); //����ڵ������ 
         BinTree_DLR(bt->left,oper);
         BinTree_DLR(bt->right,oper);
     }
     return; 
} 
void BinTree_LDR(ThreadBinTree *bt,void(*oper)(ThreadBinTree *p))  //������� 
{
     if(bt)//����Ϊ�գ���ִ�����²��� 
     {
         BinTree_LDR(bt->left,oper); //�������������
         oper(bt);//����ڵ����� 
         BinTree_LDR(bt->right,oper); //�������������/
     }
     return; 
} 
void BinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //�������
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //������������� 
         BinTree_LRD(bt->right,oper); //�������������/
         oper(bt); //����ڵ�����
     }
     return; 
} 
void BinTree_Level(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //������� 
{
     ThreadBinTree *p;
     ThreadBinTree *q[QUEUE_MAXSIZE]; //����һ��˳��ջ 
     int head=0,tail=0;//���ס���β��� 
     if(bt)//������ָ�벻Ϊ��     
     {
         tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����ж�β��� 
         q[tail] = bt;//����������ָ�����
     }
     while(head!=tail) //���в�Ϊ�գ�����ѭ�� 
     {
         head=(head+1)%QUEUE_MAXSIZE; //����ѭ�����еĶ������ 
         p=q[head]; //��ȡ����Ԫ�� 
         oper(p);//�������Ԫ�� 
         if(p->left!=NULL) //���ڵ��������������������ָ����� 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ�β��� 
             q[tail]=p->left;//��������ָ����� 
         }
                 
         if(p->right!=NULL)//���ڵ�����Һ��ӣ����Һ��ӽڵ�ָ����� 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ�β��� 
             q[tail]=p->right;//��������ָ����� 
         }
     }
     return; 
}
void BinTreeThreading_LDR(ThreadBinTree *bt)     //������������������
{
    if(bt) //�ڵ�ǿ�ʱ����ǰ���ʽڵ�
    {
        BinTreeThreading_LDR(bt->left); //�ݹ���ã���������������
        bt->lflag=(bt->left)?SubTree:Thread; //������ָ����ı�־
        bt->rflag=(bt->right)?SubTree:Thread;//������ָ����ı�־
        if(Previous) //����ǰ�ڵ��ǰ��Previous����
        {
            if(Previous->rflag==Thread) //����ǰ�ڵ��ǰ���ұ�־Ϊ����
                Previous->right=bt;//��Previous��������ָ����
            if(bt->lflag==Thread) //����ǰ�ڵ�����־Ϊ����
                bt->left=Previous;//�赱ǰ�ڵ��������ָ������ǰ�� 
        }
        Previous=bt;//��Previous����շ��ʵĽڵ�
        BinTreeThreading_LDR(bt->right);//�ݹ���ã���������������
    }
}
ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt) //��ָ���ڵ�ĺ�� 
{
    ThreadBinTree *nextnode;
    if(!bt) return NULL; //����ǰ�ڵ�Ϊ�գ��򷵻ؿ� 
    if(bt->rflag==Thread) //����ǰ�ڵ��������Ϊ��
        return bt->right; //������������ָ��������
    else{
        nextnode=bt->right; //�ӵ�ǰ�ڵ����������ʼ����
        while(nextnode->lflag==SubTree) //ѭ������������������Ϊ�յĽڵ�
            nextnode=nextnode->left;
        return nextnode; //�������·��Ľڵ�
    }
}
ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt) //��ָ���ڵ��ǰ�� 
{
    ThreadBinTree *prenode;
    if(!bt) return NULL; //����ǰ�ڵ�Ϊ�գ��򷵻ؿ� 
    if(bt->lflag==Thread) //����ǰ�ڵ��������Ϊ��
        return bt->left; //������������ָ��������
    else{
        prenode=bt->left; //�ӵ�ǰ�ڵ����������ʼ����
        while(prenode->rflag==SubTree) //ѭ������������������Ϊ�յĽڵ�
            prenode=prenode->left;
        return prenode; //�������·��Ľڵ�
    }
}

void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //������������������
{
    if(bt) //��������Ϊ��
    {
        while(bt->lflag==SubTree)//�������� 
            bt=bt->left; //�Ӹ������������½ڵ㣬���������еĿ�ʼ�ڵ�
        do{
           oper(bt); //����ڵ� 
           bt=BinTreeNext_LDR(bt);//�������̽ڵ�
        }while(bt);
    }
}
