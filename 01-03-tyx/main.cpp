#include<iostream>
#include"function.h"
#include <cstring> // ����cstringͷ�ļ���ʹ��strlen����
using namespace std;

int main()
{
    int n;
    // ��ʾ�û������ַ���������
    cout << "�������ַ���������: ";
    cin >> n;

    char miyao[1000];
    // ��ʾ�û�������Կ
    cout << "��������Կ: ";
    cin >> miyao;

    // ��̬����һ���ַ�ָ�����飬���ڴ洢����ַ���
    char** strarray = new char* [n];
    for (int i = 0; i < n; i++)
    {
        // Ϊÿ���ַ��������ڴ�
        strarray[i] = new char[1000];
    }

    // ѭ����ȡ�û�������ַ���
    for (int i = 0; i < n; i++)
    {
        cout << "������� " << i + 1 << " ���ַ���: ";
        cin >> strarray[i];
    }

    // ����paixu�������ַ��������������
    paixu(strarray, n);
    cout << "�������ַ�������:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(strarray[i]); j++)
        {
            cout << strarray[i][j];
        }
        cout << endl;
    }

    // ����һ����ά�ַ�ָ�����飬���ڴ洢���ܺ������
    char** miwen;
    // ����jiami�������ַ���������м���
    miwen = jiami(strarray, n, miyao);
    cout << "���ܺ����������:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(strarray[i]); j++)
        {
            // ��ʮ��������ʽ������ܺ���ַ�
            cout << hex << " ox " << int(miwen[i][j]);
        }
        cout << endl;
    }

    // ��̬����һ���������飬���ڴ洢ÿ���ַ����ĳ���
    int* arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = strlen(strarray[i]);
    }

    // ����һ����ά�ַ�ָ�����飬���ڴ洢���ܺ������
    char** mingwen;
    // ����jiemi���������Ľ��н���
    mingwen = jiemi(miwen, n, miyao, arr);
    cout << "���ܺ����������:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(strarray[i]); j++)
        {
            cout << mingwen[i][j];
        }
        cout << endl;
    }

    // �ͷŶ�̬������ڴ棬�����ڴ�й©
    for (int i = 0; i < n; i++)
    {
        delete[] strarray[i];
        delete[] miwen[i];
        delete[] mingwen[i];
    }
    delete[] strarray;
    delete[] miwen;
    delete[] mingwen;
    delete[] arr;

    return 0;
}