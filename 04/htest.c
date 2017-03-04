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
    char alphabet[]={'A','B','C','D'}; //4个字符
    int w[]={5,7,2,13} ;//4个字符的权重 
    HuffmanTree *ht;
    HuffmanCode *hc;    
    m=2*n-1;    
    ht=(HuffmanTree *)malloc((m+1)*sizeof(HuffmanTree)); //申请内存，保存赫夫曼树 
    if(!ht)
    {
        printf("内存分配失败！\n");
        exit(0);    
    }
    hc=(HuffmanCode *)malloc(n*sizeof(char*));
    if(!hc)
    {
        printf("内存分配失败！\n");
        exit(0);    
    }
    
    CreateTree(ht,n,w); //创建赫夫曼树 
    HuffmanCoding(ht,n,hc); //根据赫夫曼树生成赫夫曼编码 
    for(i=1;i<=n;i++) //循环输出赫夫曼编码 
        printf("字母:%c,权重:%d,编码为 %s\n",alphabet[i-1],ht[i].weight,hc[i-1]);
    
    Encode(hc,alphabet,test,code); //根据赫夫曼编码生成编码字符串 
    printf("\n字符串:\n%s\n转换后为:\n%s\n",test,code); 
    
    Decode(ht,n,code,alphabet,code1); //根据编码字符串生成解码后的字符串 
    printf("\n编码:\n%s\n转换后为:\n%s\n",code,code1); 
    getch();
    glClear()
    return 0;
}

