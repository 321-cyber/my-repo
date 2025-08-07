#include<iostream>
#include"function.h"
using namespace std;

// 对字符串数组进行排序的函数
// arr: 指向字符串数组的指针，每个元素是一个字符串
// n: 字符串数组的元素个数
void paixu(char** arr, int n)
{
    // 外层循环控制排序的轮数，总共需要进行 n - 1 轮
    for (int i = 0; i < n - 1; i++)
    {
        // 内层循环用于比较相邻的字符串并进行交换
        for (int j = 0; j < n - 1 - i; j++)
        {
            int t;
            // judge 用于标记是否已经进行了字符串交换
            int judge = 0;
            // 逐个字符比较两个相邻的字符串
            for (t = 0; t < strlen(arr[j]) && t < strlen(arr[j + 1]); t++)
            {
                // 如果当前字符 arr[j][t] 大于 arr[j + 1][t]
                if (arr[j][t] > arr[j + 1][t])
                {
                    // 标记已经进行了交换
                    judge = 1;
                    // 交换两个字符串的指针
                    char* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    // 一旦发现字符不同并交换，就跳出内层循环
                    break;
                }
            }
            // 如果较短的字符串是较长字符串的前缀，将较短的字符串排在前面
            if (t == (strlen(arr[j + 1])) && !judge)
            {
                // 交换两个字符串的指针
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 对字符串数组进行加密的函数
// arr: 指向要加密的字符串数组的指针
// n: 字符串数组的元素个数
// miyao: 加密使用的密钥
char** jiami(char** arr, int n, char* miyao)
{
    // 动态分配一个二维字符数组用于存储加密后的密文
    char** miwen = new char* [n];
    for (int i = 0; i < n; i++)
    {
        // 为每个加密后的字符串分配内存
        miwen[i] = new char[1000];
    }
    // 遍历每个字符串
    for (int i = 0; i < n; i++)
    {
        // 遍历字符串中的每个字符
        for (int j = 0; j < strlen(arr[i]); j++)
        {
            // 使用异或运算对字符进行加密
            miwen[i][j] = arr[i][j] ^ miyao[j % strlen(miyao)];
        }
    }
    // 返回加密后的密文数组
    return miwen;
}

// 对加密后的字符串数组进行解密的函数
// miwen: 指向加密后的字符串数组的指针
// n: 字符串数组的元素个数
// miyao: 解密使用的密钥，与加密时的密钥相同
// arr: 存储每个原始字符串长度的数组
char** jiemi(char** miwen, int n, char* miyao, int* arr)
{
    // 动态分配一个二维字符数组用于存储解密后的明文
    char** mingwen = new char* [n];
    for (int i = 0; i < n; i++)
    {
        // 为每个解密后的字符串分配内存
        mingwen[i] = new char[1000];
    }
    // 遍历每个加密后的字符串
    for (int i = 0; i < n; i++)
    {
        // 遍历字符串中的每个字符
        for (int j = 0; j < arr[i]; j++)
        {
            // 使用异或运算对字符进行解密，异或运算的特性保证解密结果正确
            mingwen[i][j] = miwen[i][j] ^ miyao[j % strlen(miyao)];
        }
    }
    // 返回解密后的明文数组
    return mingwen;
}