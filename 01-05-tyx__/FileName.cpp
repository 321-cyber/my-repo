#define _CRT_SECURE_NO_WARNINGS // ����VS�İ�ȫ��������
#include<iostream>          // ���������
#include<string>            // �ַ���������δʹ�ã���������
#include<cstring>           // C����ַ�������
#include <limits>           // �������뻺��������

using namespace std;         // ��׼�����ռ�

// �����ඨ��
class encry {
private:
    char* mingwen = nullptr; // ����/���Ĵ洢ָ�루��̬���䣩
    int size;                // �ַ����鳤��
public:
    // ���캯������ʼ�����鳤�Ȳ������ڴ棨+1���ڴ洢'\0'��
    encry(int b = 0) {
        size = b;
        mingwen = new char[size + 1]; // �����1�ֽ������ַ�����ֹ��
    }

    // ���뺯������ȡ�û�������ַ�������
    void input() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺����
        for (int i = 0; i < size; i++) {
            cin >> mingwen[i]; // ����ַ���ȡ���������ո�
        }
    }

    // �±���������أ�����ָ��λ�õ��ַ������Խ��
    char operator[](int dex) {
        if (dex >= size) { // Խ����
            cout << "���" << endl;
            exit(2); // ��ֹ����
        }
        else {
            return mingwen[dex]; // ���ض�Ӧλ���ַ�
        }
    }

    // ��ֵ��������أ����������ǳ�������µ��ڴ����⣩
    encry operator=(const encry& n) {
        if (this == &n) { // �Ը�ֵ���
            return *this;
        }
        if (mingwen != nullptr) { // �ͷ�ԭ���ڴ�
            delete[] mingwen;
        }
        if (n.mingwen != nullptr) { // ����Դ��������
            mingwen = new char[n.size + 1]; // �����㹻�ڴ�
            strcpy(mingwen, n.mingwen); // �����ַ���
        }
        else {
            mingwen = nullptr; // Դ����������ʱ�ÿ�
        }
        size = n.size; // ͬ������
        return *this;
    }

    // ��Ԫ���������ܲ�����������㣩
    friend encry operator+(encry& curr, encry& next) {
        encry miwen(curr.size); // ����ͬ�������Ķ���
        for (int i = 0; i < curr.size; i++) {
            // �����ܣ����� ^ ��Կ����Կѭ��ʹ�ã�
            miwen.mingwen[i] = curr.mingwen[i] ^ next.mingwen[i % next.size];
        }
        return miwen; // �������Ķ���
    }

    // ��Ԫ���������ܲ�����������㣬������߼���ͬ��
    friend encry operator-(encry& curr, encry& next) {
        encry ming(curr.size); // ����ͬ�������Ķ���
        for (int i = 0; i < curr.size; i++) {
            // �����ܣ����� ^ ��Կ���ָ����ģ�
            ming.mingwen[i] = curr.mingwen[i] ^ next.mingwen[i % next.size];
        }
        return ming; // �������Ķ���
    }
};

int main() {
    int size1, size2; // ���ĳ��Ⱥ���Կ����
    cout << "���������ĳ��Ⱥ���Կ����: (ע�⣬��һ�������ĳ��ȣ��ڶ�������Կ���ȣ����ɵ���)" << endl;
    cin >> size1 >> size2; // ��ȡ����

    // ��������c1�����ģ���c2����Կ����c3�����ģ���c4�����ܽ����
    encry c1(size1), c2(size2), c3, c4;

    cout << "������������Կ:" << endl;
    c1.input(); // ��������
    c2.input(); // ������Կ

    c3 = c1 + c2; // ִ�м�������

    cout << "���ܽ��" << endl;
    for (int i = 0; i < size1; i++) {
        cout << hex << " ox " << int(c3[i]); // ʮ������������ģ�ע�⣺oxӦΪ0x��
    }
    cout << endl;

    c4 = c3 - c2; // ִ�н�������

    cout << "���ܽ��" << endl;
    for (int i = 0; i < size1; i++) {
        cout << c4[i]; // ������ܺ������
    }
    cout << endl;

    return 0;
}