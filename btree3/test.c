#define _CRT_SECURE_NO_WARNINGS

#include"btree.h"

int main()
{
    BSTree TT = 0; // ������ָ�������

    ElemType arr[] = { 50,66,60,26,21,30,70,68 };

    /*
    // ������arr�е����й�������������TT��
    // �����Ķ��������������£�
                50
             /     \
            26      66
           /  \    /  \
          21  30 60   70
                     /
                    68
    */
    GreateBST(&TT, arr, sizeof(arr) / sizeof(ElemType));

    ElemType ee;

    // ����TT�в���ֵΪee�Ľ�㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ���NULL��
    ee = 30;
    BSTNode* ss = Find(TT, &ee);
    if (ss != NULL) printf("���ҳɹ������ĵ�ַ��%p��ֵ��%d��\n", ss, ss->data);
    else printf("����ʧ�ܡ�\n");

    // �����������������
    printf("����������1��"); InOrder(TT); printf("\n");

    // ����TT��ɾ��ֵΪee�Ľ�㣬�ɹ�����0����㲻���ڷ���1��
    ee = 50;
    printf("������ɾ��ֵΪee�Ľ�㣬Delete()�ķ���ֵ��%d��\n", Delete(&TT, &ee));

    // �����������������
    printf("����������2��"); InOrder(TT); printf("\n");

    return 0;
	return 0;
}