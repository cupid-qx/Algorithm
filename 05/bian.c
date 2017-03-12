#include <stdio.h>
#include "AdjacentMatrix.c"

#define QUEUE_MAXSIZE 30 //���е��������
typedef struct {
    int Data[QUEUE_MAXSIZE]; //������
    int head; //��ͷָ��
    int tail; //��βָ��
} Queue; //���нṹ


//���в������� 
void init(Queue *q); //��ʼ��һ������   
int isEmpty(Queue q); //�ж϶����Ƿ��   
int push(Queue *q, int n); //��һ��Ԫ�������
int pop(Queue *q, int *ch); //��һ��Ԫ�س�����

//ͼ�������� 
void DFSTraverse(AdjacentMatrix *G); //������ȱ��� 
void BFSTraverse(AdjacentMatrix *G); //������ȱ���

void DFS(AdjacentMatrix *G, int i);
void BFS(AdjacentMatrix *G, int i);

void init(Queue *Q)    //���г�ʼ��  
{
    Q->head = Q->tail = 0;
}

int isEmpty(Queue Q)   //�ж϶����Ƿ��ѿգ����շ���1,���򷵻�0
{
    return Q.head == Q.tail;
}

int push(Queue *Q, int ch)   //����У��ɹ�����1��ʧ�ܷ���0
{
    if ((Q->tail + 1) % QUEUE_MAXSIZE == Q->head) //����������
        return 0;  //���ش���; 
    Q->Data[Q->tail] = ch; //������ch�����
    Q->tail = (Q->tail + 1) % QUEUE_MAXSIZE; //������βָ��
    return 1; //�ɹ�������1 
}

int pop(Queue *Q, int *ch)   //������,�ɹ�����1������ch���ظ�Ԫ��ֵ��ʧ�ܷ���0
{
    if (Q->head == Q->tail) //������Ϊ��
        return 0; //���ش��� 
    *ch = Q->Data[Q->head]; //���ض���Ԫ��
    Q->head = (Q->head + 1) % QUEUE_MAXSIZE; //��������ָ��
    return 1; //�ɹ������У�����1   
}

void DFSTraverse(AdjacentMatrix *G) //������ȱ��� 
{
    int i;
    for (i = 0; i < G->iVertexNum; i++) //��������������־
        G->isTravel[i] = 0;
    printf("������ȱ����ڵ�:");
    for (i = 0; i < G->iVertexNum; i++)
        if (!G->isTravel[i]) //���õ�δ����
            DFS(G, i); //���ú�������
    printf("\n");

}

void DFS(AdjacentMatrix *G, int i) //�ӵ�i����㿪ʼ����ȱ���ͼ
{
    int j;
    G->isTravel[i] = 1; //��Ǹö����Ѵ����
    printf("->%c", G->Vertex[i]);//����������
//    printf("%d->",i); //��������� 

    //��Ӵ���ڵ�Ĳ��� 
    for (j = 0; j < G->iVertexNum; j++)
        if (G->Edges[i][j] != MAX_VALUE && !G->isTravel[i])
            DFS(G, j); //�ݹ���б���
}

void BFSTraverse(AdjacentMatrix *G) //�������
{
    int i;
    for (i = 0; i < G->iVertexNum; i++) //��������������־
        G->isTravel[i] = 0;
    printf("������ȱ����ڵ�:");
    for (i = 0; i < G->iVertexNum; i++)
        if (!G->isTravel[i])
            BFS(G, i);
    printf("\n");
}

void BFS(AdjacentMatrix *G, int k) //������ȱ���
{
    int i, j;
    Queue Q; //����ѭ������ 
    init(&Q); //��ʼ��ѭ������ 

    G->isTravel[k] = 1; //��Ǹö���
    printf("->%c", G->Vertex[k]);  //�����һ������

    //��Ӵ���ڵ�Ĳ��� 
    push(&Q, k); //�����
    while (!isEmpty(Q)) //���в�Ϊ�� 
    {
        pop(&Q, &i); //������
        for (j = 0; j < G->iVertexNum; j++)
            if (G->Edges[i][j] != MAX_VALUE && !G->isTravel[j]) {
                printf("->%c", G->Vertex[j]);
                G->isTravel[j] = 1;  //��Ǹö���
                //������ 
                push(&Q, j); //������
            }
    }
}

int main()
{
    AdjacentMatrix G; //���屣���ڽӱ�ṹ��ͼ
    int path[VERTEX_MAX];
    int i,j,s,t;
    char select;
    do
    {
        printf("��������ͼ������(0:����ͼ,1:����ͼ):");
        scanf("%d",&G.iGraphType); //ͼ������
        printf("����ͼ�Ķ��������ͱ�����:");
        scanf("%d,%d",&G.iVertexNum,&G.iEdgeNum); //����ͼ�������ͱ���
        for(i=0;i<G.iVertexNum;i++)  //��վ���
            for(j=0;j<G.iVertexNum;j++)
                G.Edges[i][j]=MAX_VALUE; //���þ����и�Ԫ�ص�ֵΪ0
        createAdjacentMatrix(&G); //�����ڽӱ�ṹ��ͼ
        printf("�ڽӾ�����������:\n");
        showAdjacentMatrix(&G); //����ڽӾ���
        DFSTraverse(&G); //���������������ͼ
        BFSTraverse(&G); //���������������ͼ
        printf("ͼ������ϣ�����������?(Y/N)");
        scanf(" %c",&select);
    }while(select!='N' && select!='n');
    getch();
    return 0;
}
