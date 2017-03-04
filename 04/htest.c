#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "Huffman.c"
int main()
{
    int i,n=4,m; 
    char test[]="DBDBDABDCDADBDADBDADACDBDBD";
    char code[100],code1[100];
    char alphabet[]={'A','B','C','D'}; //4���ַ�
    int w[]={5,7,2,13} ;//4���ַ���Ȩ�� 
    HuffmanTree *ht;
    HuffmanCode *hc;    
    m=2*n-1;    
    ht=(HuffmanTree *)malloc((m+1)*sizeof(HuffmanTree)); //�����ڴ棬����շ����� 
    if(!ht)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(0);    
    }
    hc=(HuffmanCode *)malloc(n*sizeof(char*));
    if(!hc)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(0);    
    }
    
    CreateTree(ht,n,w); //�����շ����� 
    HuffmanCoding(ht,n,hc); //���ݺշ��������ɺշ������� 
    for(i=1;i<=n;i++) //ѭ������շ������� 
        printf("��ĸ:%c,Ȩ��:%d,����Ϊ %s\n",alphabet[i-1],ht[i].weight,hc[i-1]);
    
    Encode(hc,alphabet,test,code); //���ݺշ����������ɱ����ַ��� 
    printf("\n�ַ���:\n%s\nת����Ϊ:\n%s\n",test,code); 
    
    Decode(ht,n,code,alphabet,code1); //���ݱ����ַ������ɽ������ַ��� 
    printf("\n����:\n%s\nת����Ϊ:\n%s\n",code,code1); 
    getch();
    glClear()
    return 0;
}

