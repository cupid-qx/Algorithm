#include <stdio.h>
#include <malloc.h>
#include <conio.h>

#define VERTEX_MAX 20   //图的最大顶点数
typedef struct edgeNode {
    int iVertex; //顶点信息(序号或字母) 
    int iWeight; //权值
    struct edgeNode *next; //指向下一个顶点指针 (当前顶点和指向的下一顶点构成一条边) 
} EdgeNode; //邻接表边结构 

typedef struct {
    EdgeNode *AdjList[VERTEX_MAX]; //指向每个顶点的指针
    int iVertexNum, iEdgeNum; //图的顶点的数量和边的数量  
    int iGraphType; //图的类型(0:无向图，1:有向图)
} ListGraph;  //图的结构

void createAdjacentList(ListGraph *graph); //生成图的邻接表   
void showAdjacentList(ListGraph *graph); //输出邻接表

void createAdjacentList(ListGraph *graph)  //构造邻接表结构图
{
    int i, iWeight;
    int start, end;
    EdgeNode *edgeNode;
    for (i = 1; i <= graph->iVertexNum; i++)//将图中各顶点指针清空 
        graph->AdjList[i] = NULL;
    printf("请输入构成每个边的两个顶点和权值（用逗号隔开）：\n");
    for (i = 1; i <= graph->iEdgeNum; i++) //输入各边的两个顶点 
    {
        getchar();
        printf("第%d条边:", i);
        scanf("%d,%d,%d", &start, &end, &iWeight); //输入边的起点和终点
        edgeNode = (EdgeNode *) malloc(sizeof(EdgeNode)); //申请保存一个顶点的内存 
        edgeNode->next = graph->AdjList[start]; //插入到邻接表中 
        edgeNode->iVertex = end; //保存终点编号
        edgeNode->iWeight = iWeight; //保存权值 
        graph->AdjList[start] = edgeNode; //邻接表对应顶点指向该点 
        if (graph->iGraphType == 0) //若是无向图，再插入到终点的边链中
        {
            edgeNode = (EdgeNode *) malloc(sizeof(EdgeNode)); //申请保存一个顶点的内存 
            edgeNode->next = graph->AdjList[end];
            edgeNode->iVertex = start;
            edgeNode->iWeight = iWeight;
            graph->AdjList[end] = edgeNode;
        }
    }
}

void showAdjacentList(ListGraph *graph) {
    int i;
    EdgeNode *edgeNode;
    for (i = 1; i <= graph->iVertexNum; i++) {
        printf("顶点%d", i);
        edgeNode = graph->AdjList[i];
        while (edgeNode) {
            printf("->%d(%d)", edgeNode->iVertex, edgeNode->iWeight);
            edgeNode = edgeNode->next;
        }
        printf("\n");
    }
}


int main() {
    ListGraph graph; //定义保存邻接表结构的图
    printf("输入生成图的类型(0:无向图,1:有向图):");
    scanf("%d", &graph.iGraphType); //图的种类
    printf("输入图的顶点数量和边数量:");
    scanf("%d,%d", &graph.iVertexNum, &graph.iEdgeNum); //输入图顶点数和边数
    printf("输入构成各边的两个顶点及权值(用逗号分隔):\n");
    createAdjacentList(&graph); //生成邻接表结构的图
    printf("输出图的邻接表:\n");
    showAdjacentList(&graph);
    getch();
    return 0;
}
