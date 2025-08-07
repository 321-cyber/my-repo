#include<iostream>
#include"function.h"
using namespace std;

// ���ַ��������������ĺ���
// arr: ָ���ַ��������ָ�룬ÿ��Ԫ����һ���ַ���
// n: �ַ��������Ԫ�ظ���
void paixu(char** arr, int n)
{
    // ���ѭ������������������ܹ���Ҫ���� n - 1 ��
    for (int i = 0; i < n - 1; i++)
    {
        // �ڲ�ѭ�����ڱȽ����ڵ��ַ��������н���
        for (int j = 0; j < n - 1 - i; j++)
        {
            int t;
            // judge ���ڱ���Ƿ��Ѿ��������ַ�������
            int judge = 0;
            // ����ַ��Ƚ��������ڵ��ַ���
            for (t = 0; t < strlen(arr[j]) && t < strlen(arr[j + 1]); t++)
            {
                // �����ǰ�ַ� arr[j][t] ���� arr[j + 1][t]
                if (arr[j][t] > arr[j + 1][t])
                {
                    // ����Ѿ������˽���
                    judge = 1;
                    // ���������ַ�����ָ��
                    char* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    // һ�������ַ���ͬ���������������ڲ�ѭ��
                    break;
                }
            }
            // ����϶̵��ַ����ǽϳ��ַ�����ǰ׺�����϶̵��ַ�������ǰ��
            if (t == (strlen(arr[j + 1])) && !judge)
            {
                // ���������ַ�����ָ��
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ���ַ���������м��ܵĺ���
// arr: ָ��Ҫ���ܵ��ַ��������ָ��
// n: �ַ��������Ԫ�ظ���
// miyao: ����ʹ�õ���Կ
char** jiami(char** arr, int n, char* miyao)
{
    // ��̬����һ����ά�ַ��������ڴ洢���ܺ������
    char** miwen = new char* [n];
    for (int i = 0; i < n; i++)
    {
        // Ϊÿ�����ܺ���ַ��������ڴ�
        miwen[i] = new char[1000];
    }
    // ����ÿ���ַ���
    for (int i = 0; i < n; i++)
    {
        // �����ַ����е�ÿ���ַ�
        for (int j = 0; j < strlen(arr[i]); j++)
        {
            // ʹ�����������ַ����м���
            miwen[i][j] = arr[i][j] ^ miyao[j % strlen(miyao)];
        }
    }
    // ���ؼ��ܺ����������
    return miwen;
}

// �Լ��ܺ���ַ���������н��ܵĺ���
// miwen: ָ����ܺ���ַ��������ָ��
// n: �ַ��������Ԫ�ظ���
// miyao: ����ʹ�õ���Կ�������ʱ����Կ��ͬ
// arr: �洢ÿ��ԭʼ�ַ������ȵ�����
char** jiemi(char** miwen, int n, char* miyao, int* arr)
{
    // ��̬����һ����ά�ַ��������ڴ洢���ܺ������
    char** mingwen = new char* [n];
    for (int i = 0; i < n; i++)
    {
        // Ϊÿ�����ܺ���ַ��������ڴ�
        mingwen[i] = new char[1000];
    }
    // ����ÿ�����ܺ���ַ���
    for (int i = 0; i < n; i++)
    {
        // �����ַ����е�ÿ���ַ�
        for (int j = 0; j < arr[i]; j++)
        {
            // ʹ�����������ַ����н��ܣ������������Ա�֤���ܽ����ȷ
            mingwen[i][j] = miwen[i][j] ^ miyao[j % strlen(miyao)];
        }
    }
    // ���ؽ��ܺ����������
    return mingwen;
}