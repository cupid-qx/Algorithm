#include <stdio.h>
#include "AdjacentMatrix.c"

#define QUEUE_MAXSIZE 30 //队列的最大容量
typedef struct {
    int Data[QUEUE_MAXSIZE]; //数据域
    int head; //队头指针
    int tail; //队尾指针
} Queue; //队列结构


//队列操作函数 
void init(Queue *q); //初始化一个队列   
int isEmpty(Queue q); //判断队列是否空   
int push(Queue *q, int n); //将一个元素入队列
int pop(Queue *q, int *ch); //将一个元素出队列

//图操作函数 
void DFSTraverse(AdjacentMatrix *G); //深度优先遍历 
void BFSTraverse(AdjacentMatrix *G); //广度优先遍历

void DFS(AdjacentMatrix *G, int i);
void BFS(AdjacentMatrix *G, int i);

void init(Queue *Q)    //队列初始化  
{
    Q->head = Q->tail = 0;
}

int isEmpty(Queue Q)   //判断队列是否已空，若空返回1,否则返回0
{
    return Q.head == Q.tail;
}

int push(Queue *Q, int ch)   //入队列，成功返回1，失败返回0
{
    if ((Q->tail + 1) % QUEUE_MAXSIZE == Q->head) //若队列已满
        return 0;  //返回错误; 
    Q->Data[Q->tail] = ch; //将数据ch入队列
    Q->tail = (Q->tail + 1) % QUEUE_MAXSIZE; //调整队尾指针
    return 1; //成功，返回1 
}

int pop(Queue *Q, int *ch)   //出队列,成功返回1，并用ch返回该元素值，失败返回0
{
    if (Q->head == Q->tail) //若队列为空
        return 0; //返回错误 
    *ch = Q->Data[Q->head]; //返回队首元素
    Q->head = (Q->head + 1) % QUEUE_MAXSIZE; //调整队首指针
    return 1; //成功出队列，返回1   
}

void DFSTraverse(AdjacentMatrix *G) //深度优先遍历 
{
    int i;
    for (i = 0; i < G->iVertexNum; i++) //清除各顶点遍历标志
        G->isTravel[i] = 0;
    printf("深度优先遍历节点:");
    for (i = 0; i < G->iVertexNum; i++)
        if (!G->isTravel[i]) //若该点未遍历
            DFS(G, i); //调用函数遍历
    printf("\n");

}

void DFS(AdjacentMatrix *G, int i) //从第i个结点开始，深度遍历图
{
    int j;
    G->isTravel[i] = 1; //标记该顶点已处理过
    printf("->%c", G->Vertex[i]);//输出结点数据
//    printf("%d->",i); //输出结点序号 

    //添加处理节点的操作 
    for (j = 0; j < G->iVertexNum; j++)
        if (G->Edges[i][j] != MAX_VALUE && !G->isTravel[i])
            DFS(G, j); //递归进行遍历
}

void BFSTraverse(AdjacentMatrix *G) //广度优先
{
    int i;
    for (i = 0; i < G->iVertexNum; i++) //清除各顶点遍历标志
        G->isTravel[i] = 0;
    printf("广度优先遍历节点:");
    for (i = 0; i < G->iVertexNum; i++)
        if (!G->isTravel[i])
            BFS(G, i);
    printf("\n");
}

void BFS(AdjacentMatrix *G, int k) //广度优先遍历
{
    int i, j;
    Queue Q; //创建循环队列 
    init(&Q); //初始化循环队列 

    G->isTravel[k] = 1; //标记该顶点
    printf("->%c", G->Vertex[k]);  //输出第一个顶点

    //添加处理节点的操作 
    push(&Q, k); //入队列
    while (!isEmpty(Q)) //队列不为空 
    {
        pop(&Q, &i); //出队列
        for (j = 0; j < G->iVertexNum; j++)
            if (G->Edges[i][j] != MAX_VALUE && !G->isTravel[j]) {
                printf("->%c", G->Vertex[j]);
                G->isTravel[j] = 1;  //标记该顶点
                //处理顶点 
                push(&Q, j); //出队列
            }
    }
}

int main()
{
    AdjacentMatrix G; //定义保存邻接表结构的图
    int path[VERTEX_MAX];
    int i,j,s,t;
    char select;
    do
    {
        printf("输入生成图的类型(0:无向图,1:有向图):");
        scanf("%d",&G.iGraphType); //图的种类
        printf("输入图的顶点数量和边数量:");
        scanf("%d,%d",&G.iVertexNum,&G.iEdgeNum); //输入图顶点数和边数
        for(i=0;i<G.iVertexNum;i++)  //清空矩阵
            for(j=0;j<G.iVertexNum;j++)
                G.Edges[i][j]=MAX_VALUE; //设置矩阵中各元素的值为0
        createAdjacentMatrix(&G); //生成邻接表结构的图
        printf("邻接矩阵数据如下:\n");
        showAdjacentMatrix(&G); //输出邻接矩阵
        DFSTraverse(&G); //深度优先搜索遍历图
        BFSTraverse(&G); //广度优先搜索遍历图
        printf("图遍历完毕，继续进行吗?(Y/N)");
        scanf(" %c",&select);
    }while(select!='N' && select!='n');
    getch();
    return 0;
}
