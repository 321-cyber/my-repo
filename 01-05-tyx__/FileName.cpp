#define _CRT_SECURE_NO_WARNINGS // 禁用VS的安全函数警告
#include<iostream>          // 输入输出流
#include<string>            // 字符串处理（虽未使用，但包含）
#include<cstring>           // C风格字符串函数
#include <limits>           // 用于输入缓冲区清理

using namespace std;         // 标准命名空间

// 加密类定义
class encry {
private:
    char* mingwen = nullptr; // 明文/密文存储指针（动态分配）
    int size;                // 字符数组长度
public:
    // 构造函数：初始化数组长度并分配内存（+1用于存储'\0'）
    encry(int b = 0) {
        size = b;
        mingwen = new char[size + 1]; // 多分配1字节用于字符串终止符
    }

    // 输入函数：读取用户输入的字符到数组
    void input() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空输入缓冲区
        for (int i = 0; i < size; i++) {
            cin >> mingwen[i]; // 逐个字符读取（不包含空格）
        }
    }

    // 下标运算符重载：访问指定位置的字符并检查越界
    char operator[](int dex) {
        if (dex >= size) { // 越界检查
            cout << "溢出" << endl;
            exit(2); // 终止程序
        }
        else {
            return mingwen[dex]; // 返回对应位置字符
        }
    }

    // 赋值运算符重载：深拷贝（避免浅拷贝导致的内存问题）
    encry operator=(const encry& n) {
        if (this == &n) { // 自赋值检查
            return *this;
        }
        if (mingwen != nullptr) { // 释放原有内存
            delete[] mingwen;
        }
        if (n.mingwen != nullptr) { // 拷贝源对象数据
            mingwen = new char[n.size + 1]; // 分配足够内存
            strcpy(mingwen, n.mingwen); // 复制字符串
        }
        else {
            mingwen = nullptr; // 源对象无数据时置空
        }
        size = n.size; // 同步长度
        return *this;
    }

    // 友元函数：加密操作（异或运算）
    friend encry operator+(encry& curr, encry& next) {
        encry miwen(curr.size); // 创建同长度密文对象
        for (int i = 0; i < curr.size; i++) {
            // 异或加密：明文 ^ 密钥（密钥循环使用）
            miwen.mingwen[i] = curr.mingwen[i] ^ next.mingwen[i % next.size];
        }
        return miwen; // 返回密文对象
    }

    // 友元函数：解密操作（异或运算，与加密逻辑相同）
    friend encry operator-(encry& curr, encry& next) {
        encry ming(curr.size); // 创建同长度明文对象
        for (int i = 0; i < curr.size; i++) {
            // 异或解密：密文 ^ 密钥（恢复明文）
            ming.mingwen[i] = curr.mingwen[i] ^ next.mingwen[i % next.size];
        }
        return ming; // 返回明文对象
    }
};

int main() {
    int size1, size2; // 明文长度和密钥长度
    cout << "请输入明文长度和密钥长度: (注意，第一个是明文长度，第二个是密钥长度，不可调换)" << endl;
    cin >> size1 >> size2; // 读取长度

    // 创建对象：c1（明文）、c2（密钥）、c3（密文）、c4（解密结果）
    encry c1(size1), c2(size2), c3, c4;

    cout << "输入明文与密钥:" << endl;
    c1.input(); // 输入明文
    c2.input(); // 输入密钥

    c3 = c1 + c2; // 执行加密运算

    cout << "加密结果" << endl;
    for (int i = 0; i < size1; i++) {
        cout << hex << " ox " << int(c3[i]); // 十六进制输出密文（注意：ox应为0x）
    }
    cout << endl;

    c4 = c3 - c2; // 执行解密运算

    cout << "解密结果" << endl;
    for (int i = 0; i < size1; i++) {
        cout << c4[i]; // 输出解密后的明文
    }
    cout << endl;

    return 0;
}