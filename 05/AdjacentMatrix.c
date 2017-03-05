#include <stdio.h>
#include <conio.h>
#define VERTEX_MAX 26   //图的最大顶点数
#define MAX_VALUE0 32767 //最大值(可设为一个最大整数)
typedef struct
{
    char Vertex[VERTEX_MAX]; //保存顶点信息(序号或字母)
    int Edges[VERTEX_MAX][VERTEX_MAX]; //保存边的权
    int isTravel[VERTEX_MAX]; //遍历标志
    int iVertexNum; //顶点数量
    int iEdgeNum;//边数量
    int iGraphType; //图的类型(0:无向图，1:有向图)
}AdjacentMatrix; //定义邻接矩阵图结构

// 创建邻接矩阵
void createAdjacentMatrix(AdjacentMatrix *graph) {
    int i, j, k, iWeight = 0;
    // 边的开头和结尾顶点
    char cEdgeStart, cEdgeEnd;
    printf("输入各个顶点的信息：\n");
    for (i = 0; i < graph->iVertexNum; i++) {
        // 输入顶点
        printf("第%d个顶点：", i + 1);
        fflush(stdin);
        // 将输入的信息保存到顶点数组中
        scanf("%c", &(graph->Vertex[i]));
    }

    printf("请输入构成每个边的两个顶点和权值（用逗号隔开）：\n");
    for (j = 0; j < graph->iEdgeNum; ++j) {
        // 输入边的信息
        printf("第%d条边：", j + 1);
        fflush(stdin);
        scanf("%c,%c,%d", &cEdgeStart, &cEdgeEnd, &iWeight);
        // 在已有的顶点中查找开始点
        for (i = 0; cEdgeStart != graph->Vertex[i]; ++i);
        // 在已有顶点中查找终点
        for (k = 0; cEdgeEnd != graph->Vertex[k]; ++k);
        // 在边的对应位置保存权重
        graph->Edges[i][k] = iWeight;
        // 如果是无向图，则相反的位置也要保存
        if (graph->iGraphType == 0)
            graph->Edges[k][i] = iWeight;


    }
}

// 输出邻接矩阵
void showAdjacentMatrix(AdjacentMatrix *graph) {

    // 顶点信息
    for (int i = 0; i < graph->iVertexNum; ++i) {
        printf("\t%c", graph->Vertex[i]);
    }
    printf("\n");
    for (int i = 0; i < graph->iVertexNum; ++i) {
        printf("%c", graph->Vertex[i]);
        for (int j = 0; j < graph->iVertexNum; ++j) {
            // 权值为最大值
            if (graph->Edges[i][j] == MAX_VALUE)
                printf("\t∞");
            else
                printf("\t%d", graph->Edges[i][j]);
        }

        printf("\n");
    }
}


int main() {
    AdjacentMatrix G; //定义保存邻接矩阵结构的图
    int i, j;
    printf("输入生成图的类型(0:无向图,1:有向图):");
    scanf("%d", &G.iGraphType); //图的种类
    printf("输入图的顶点数量和边数量:");
    scanf("%d,%d", &G.iVertexNum, &G.iEdgeNum); //输入图顶点数和边数
    for (i = 0; i < G.iVertexNum; i++)  //清空矩阵
        for (j = 0; j < G.iVertexNum; j++)
            G.Edges[i][j] = MAX_VALUE; //设置矩阵中各元素的值为最大值
    createAdjacentMatrix(&G); //创建用邻接表保存的图
    printf("邻接矩阵数据如下:\n");
    showAdjacentMatrix(&G);
    getch();
    return 0;
}
