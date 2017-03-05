#include <stdio.h>
#include <conio.h>
#define VERTEX_MAX 26   //ͼ����󶥵���
#define MAX_VALUE0 32767 //���ֵ(����Ϊһ���������)
typedef struct
{
    char Vertex[VERTEX_MAX]; //���涥����Ϣ(��Ż���ĸ)
    int Edges[VERTEX_MAX][VERTEX_MAX]; //����ߵ�Ȩ
    int isTravel[VERTEX_MAX]; //������־
    int iVertexNum; //��������
    int iEdgeNum;//������
    int iGraphType; //ͼ������(0:����ͼ��1:����ͼ)
}AdjacentMatrix; //�����ڽӾ���ͼ�ṹ

// �����ڽӾ���
void createAdjacentMatrix(AdjacentMatrix *graph) {
    int i, j, k, iWeight = 0;
    // �ߵĿ�ͷ�ͽ�β����
    char cEdgeStart, cEdgeEnd;
    printf("��������������Ϣ��\n");
    for (i = 0; i < graph->iVertexNum; i++) {
        // ���붥��
        printf("��%d�����㣺", i + 1);
        fflush(stdin);
        // ���������Ϣ���浽����������
        scanf("%c", &(graph->Vertex[i]));
    }

    printf("�����빹��ÿ���ߵ����������Ȩֵ���ö��Ÿ�������\n");
    for (j = 0; j < graph->iEdgeNum; ++j) {
        // ����ߵ���Ϣ
        printf("��%d���ߣ�", j + 1);
        fflush(stdin);
        scanf("%c,%c,%d", &cEdgeStart, &cEdgeEnd, &iWeight);
        // �����еĶ����в��ҿ�ʼ��
        for (i = 0; cEdgeStart != graph->Vertex[i]; ++i);
        // �����ж����в����յ�
        for (k = 0; cEdgeEnd != graph->Vertex[k]; ++k);
        // �ڱߵĶ�Ӧλ�ñ���Ȩ��
        graph->Edges[i][k] = iWeight;
        // ���������ͼ�����෴��λ��ҲҪ����
        if (graph->iGraphType == 0)
            graph->Edges[k][i] = iWeight;


    }
}

// ����ڽӾ���
void showAdjacentMatrix(AdjacentMatrix *graph) {

    // ������Ϣ
    for (int i = 0; i < graph->iVertexNum; ++i) {
        printf("\t%c", graph->Vertex[i]);
    }
    printf("\n");
    for (int i = 0; i < graph->iVertexNum; ++i) {
        printf("%c", graph->Vertex[i]);
        for (int j = 0; j < graph->iVertexNum; ++j) {
            // ȨֵΪ���ֵ
            if (graph->Edges[i][j] == MAX_VALUE)
                printf("\t��");
            else
                printf("\t%d", graph->Edges[i][j]);
        }

        printf("\n");
    }
}


int main() {
    AdjacentMatrix G; //���屣���ڽӾ���ṹ��ͼ
    int i, j;
    printf("��������ͼ������(0:����ͼ,1:����ͼ):");
    scanf("%d", &G.iGraphType); //ͼ������
    printf("����ͼ�Ķ��������ͱ�����:");
    scanf("%d,%d", &G.iVertexNum, &G.iEdgeNum); //����ͼ�������ͱ���
    for (i = 0; i < G.iVertexNum; i++)  //��վ���
        for (j = 0; j < G.iVertexNum; j++)
            G.Edges[i][j] = MAX_VALUE; //���þ����и�Ԫ�ص�ֵΪ���ֵ
    createAdjacentMatrix(&G); //�������ڽӱ����ͼ
    printf("�ڽӾ�����������:\n");
    showAdjacentMatrix(&G);
    getch();
    return 0;
}
