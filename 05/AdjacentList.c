#include <stdio.h>
#include <malloc.h>
#include <conio.h>

#define VERTEX_MAX 20   //ͼ����󶥵���
typedef struct edgeNode {
    int iVertex; //������Ϣ(��Ż���ĸ) 
    int iWeight; //Ȩֵ
    struct edgeNode *next; //ָ����һ������ָ�� (��ǰ�����ָ�����һ���㹹��һ����) 
} EdgeNode; //�ڽӱ�߽ṹ 

typedef struct {
    EdgeNode *AdjList[VERTEX_MAX]; //ָ��ÿ�������ָ��
    int iVertexNum, iEdgeNum; //ͼ�Ķ���������ͱߵ�����  
    int iGraphType; //ͼ������(0:����ͼ��1:����ͼ)
} ListGraph;  //ͼ�Ľṹ

void createAdjacentList(ListGraph *graph); //����ͼ���ڽӱ�   
void showAdjacentList(ListGraph *graph); //����ڽӱ�

void createAdjacentList(ListGraph *graph)  //�����ڽӱ�ṹͼ
{
    int i, iWeight;
    int start, end;
    EdgeNode *edgeNode;
    for (i = 1; i <= graph->iVertexNum; i++)//��ͼ�и�����ָ����� 
        graph->AdjList[i] = NULL;
    printf("�����빹��ÿ���ߵ����������Ȩֵ���ö��Ÿ�������\n");
    for (i = 1; i <= graph->iEdgeNum; i++) //������ߵ��������� 
    {
        getchar();
        printf("��%d����:", i);
        scanf("%d,%d,%d", &start, &end, &iWeight); //����ߵ������յ�
        edgeNode = (EdgeNode *) malloc(sizeof(EdgeNode)); //���뱣��һ��������ڴ� 
        edgeNode->next = graph->AdjList[start]; //���뵽�ڽӱ��� 
        edgeNode->iVertex = end; //�����յ���
        edgeNode->iWeight = iWeight; //����Ȩֵ 
        graph->AdjList[start] = edgeNode; //�ڽӱ��Ӧ����ָ��õ� 
        if (graph->iGraphType == 0) //��������ͼ���ٲ��뵽�յ�ı�����
        {
            edgeNode = (EdgeNode *) malloc(sizeof(EdgeNode)); //���뱣��һ��������ڴ� 
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
        printf("����%d", i);
        edgeNode = graph->AdjList[i];
        while (edgeNode) {
            printf("->%d(%d)", edgeNode->iVertex, edgeNode->iWeight);
            edgeNode = edgeNode->next;
        }
        printf("\n");
    }
}


int main() {
    ListGraph graph; //���屣���ڽӱ�ṹ��ͼ
    printf("��������ͼ������(0:����ͼ,1:����ͼ):");
    scanf("%d", &graph.iGraphType); //ͼ������
    printf("����ͼ�Ķ��������ͱ�����:");
    scanf("%d,%d", &graph.iVertexNum, &graph.iEdgeNum); //����ͼ�������ͱ���
    printf("���빹�ɸ��ߵ��������㼰Ȩֵ(�ö��ŷָ�):\n");
    createAdjacentList(&graph); //�����ڽӱ�ṹ��ͼ
    printf("���ͼ���ڽӱ�:\n");
    showAdjacentList(&graph);
    getch();
    return 0;
}
