#include <stdio.h> 
#include "xianTree.c"
void oper(ThreadBinTree *p) //�����������������
{
     printf("%c ",p->data); //�������
     return;
}
ThreadBinTree *InitRoot()  //��ʼ���������ĸ� 
{
    ThreadBinTree *node;
    if(node=(ThreadBinTree *)malloc(sizeof(ThreadBinTree))) //�����ڴ�
    {
        printf("\n������ڵ�����:");
        scanf("%s",&node->data);
        node->left=NULL;
        node->right=NULL;
        return BinTreeInit(node);
    }
    return NULL;
}
void AddNode(ThreadBinTree *bt)
{
     ThreadBinTree *node,*parent;
     DATA data;
     char select;
    if(node=(ThreadBinTree *)malloc(sizeof(ThreadBinTree))) //�����ڴ�
    {
        printf("\n����������ڵ�����:");
        fflush(stdin);//������뻺���� 
        scanf("%s",&node->data);
        node->left=NULL; //������������Ϊ�� 
        node->right=NULL;
        

        printf("���븸�ڵ�����:");
        fflush(stdin);//������뻺���� 
        scanf("%s",&data);
        parent=BinTreeFind(bt,data);//����ָ�����ݵĽڵ� 
        if(!parent)//��δ�ҵ�ָ�����ݵĽڵ� 
        {
            printf("δ�ҵ����ڵ�!\n");
            free(node); //�ͷŴ����Ľڵ��ڴ� 
            return;
         }
         printf("1.��ӵ�������\n2.��ӵ�������\n");
         do{
            select=getch();
            select-='0';
            if(select==1 || select==2)
                BinTreeAddNode(parent,node,select); //��ӽڵ㵽������ 
         }while(select!=1 && select!=2);
    }
    return ;
}
int main() 
{
    ThreadBinTree *root=NULL; //rootΪָ����������ڵ��ָ�� 
    char select;
    void (*oper1)(); //ָ������ָ�� 
    oper1=oper; //ָ���������ĺ��� 
    do{
        printf("\n1.���ö�������Ԫ��    2.��Ӷ������ڵ�\n");
        printf("3.������������������  4.��������������\n");
        printf("0.�˳�\n");
        select=getch();
        switch(select){
        case '1': //���ø�Ԫ�� 
             root=InitRoot();
             break;
        case '2': //��ӽڵ� 
             AddNode(root);
             break;
        case '3'://������������������
             BinTreeThreading_LDR(root);
             printf("\n��������������������ϣ�\n");
             break;
        case '4'://������������������ 
             printf("\n�������������������Ľ����");
             ThreadBinTree_LDR(root,oper1);
             printf("\n");
             break;
        case '0':
             break;
        }
    }while(select!='0');
    BinTreeClear(root);//��ն����� 
    root=NULL;
    getch();
    return 0;
}
