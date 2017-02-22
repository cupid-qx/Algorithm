//
// Created by qcq on 2017/2/21.
//

void init(SeqList *SL) //��ʼ��˳���
{
    SL->length = 0;     //��ʼ��ʱ������˳�����Ϊ0
}

int length(SeqList *SL)  //����˳����Ԫ������
{
    return SL->length;
}

int add(SeqList *SL, DATA data)  //����Ԫ�ص�˳���β��
{
    if (SL->length >= MAXSIZE)  //˳�������
    {
        printf("˳�����������������ӽ���ˣ�\n");
        return 0;
    }
    SL->ListData[++SL->length] = data;
    return 1;
}

int insert(SeqList *SL, int n, DATA data) {
    int i;
    if (SL->length >= MAXSIZE)   //˳����������ѳ����������
    {
        printf("˳������������ܲ�����!\n");
        return 0;             //����0��ʾ���벻�ɹ�
    }
    if (n < 1 || n > SL->length - 1)  //��������Ų���ȷ
    {
        printf("����Ԫ����Ŵ��󣬲��ܲ���Ԫ�أ�\n");
        return 0;              //����0����ʾ���벻�ɹ�
    }
    for (i = SL->length; i >= n; i--)  //��˳����е���������ƶ�
        SL->ListData[i + 1] = SL->ListData[i];
    SL->ListData[n] = data;        //������
    SL->length++;               //˳�������������1
    return 1;                   //���سɹ�����
}

int delete(SeqList *SL, int n)  //ɾ��˳����е�����Ԫ��
{
    int i;
    if (n < 1 || n > SL->length + 1)  //ɾ��Ԫ����Ų���ȷ
    {
        printf("ɾ�������Ŵ��󣬲���ɾ����㣡\n");
        return 0;              //����0����ʾɾ�����ɹ�
    }
    for (i = n; i < SL->length; i++)  //��˳����е�������ǰ�ƶ�
        SL->ListData[i] = SL->ListData[i + 1];
    SL->length--;               //˳���Ԫ��������1
    return 1;                   //���سɹ�ɾ��
}

DATA *findByNum(SeqList *SL, int n)  //������ŷ�������Ԫ��
{
    if (n < 1 || n > SL->length + 1)  //Ԫ����Ų���ȷ
    {
        printf("�����Ŵ��󣬲��ܷ��ؽ�㣡\n");
        return NULL;              //����0����ʾ���ɹ�
    }
    return &(SL->ListData[n]);
}

int findByKey(SeqList *SL, char *key)  //���ؼ��ֲ�ѯ���
{
    int i;
    for (i = 1; i <= SL->length; i++)
        if (strcmp(SL->ListData[i].key, key) == 0)  //����ҵ�������
            return i;        //���ؽ�����
    return 0;  //��������û���ҵ����򷵻�0
}
