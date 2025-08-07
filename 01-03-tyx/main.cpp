#include<iostream>
#include"function.h"
#include <cstring> // 包含cstring头文件以使用strlen函数
using namespace std;

int main()
{
    int n;
    // 提示用户输入字符串的数量
    cout << "请输入字符串的数量: ";
    cin >> n;

    char miyao[1000];
    // 提示用户输入密钥
    cout << "请输入密钥: ";
    cin >> miyao;

    // 动态分配一个字符指针数组，用于存储多个字符串
    char** strarray = new char* [n];
    for (int i = 0; i < n; i++)
    {
        // 为每个字符串分配内存
        strarray[i] = new char[1000];
    }

    // 循环读取用户输入的字符串
    for (int i = 0; i < n; i++)
    {
        cout << "请输入第 " << i + 1 << " 个字符串: ";
        cin >> strarray[i];
    }

    // 调用paixu函数对字符串数组进行排序
    paixu(strarray, n);
    cout << "排序后的字符串如下:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(strarray[i]); j++)
        {
            cout << strarray[i][j];
        }
        cout << endl;
    }

    // 定义一个二维字符指针数组，用于存储加密后的密文
    char** miwen;
    // 调用jiami函数对字符串数组进行加密
    miwen = jiami(strarray, n, miyao);
    cout << "加密后的密文如下:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(strarray[i]); j++)
        {
            // 以十六进制形式输出加密后的字符
            cout << hex << " ox " << int(miwen[i][j]);
        }
        cout << endl;
    }

    // 动态分配一个整型数组，用于存储每个字符串的长度
    int* arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = strlen(strarray[i]);
    }

    // 定义一个二维字符指针数组，用于存储解密后的明文
    char** mingwen;
    // 调用jiemi函数对密文进行解密
    mingwen = jiemi(miwen, n, miyao, arr);
    cout << "解密后的明文如下:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(strarray[i]); j++)
        {
            cout << mingwen[i][j];
        }
        cout << endl;
    }

    // 释放动态分配的内存，避免内存泄漏
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