#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include <limits> 
using namespace std;

// �����ࣺ֧��ʹ�����������м򵥼��ܺͽ���
class encry
{
private:
	char* mingwen = nullptr;  // �洢���Ļ�����
	int size;              // �ַ�������
public:
	// ���캯������ʼ��ָ�����ȵ��ַ�����
	encry(int b = 0)
	{
		size = b;
		mingwen = new char[size + 1];
	}

	// ���뺯������ȡ�û�������ַ���
	void input()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������" << size << "���ַ�: ";
		for (int i = 0; i < size; i++)
		{
			cin >> mingwen[i];
		}
	}

	// �±���������أ�����ָ��λ�õ��ַ�
	char operator[](int dex)
	{
		if (dex >= size)
		{
			cout << "���" << endl;
			exit(2);
		}
		else
		{
			return mingwen[dex];
		}
	}

	// ��ֵ��������أ�ʵ�����
	encry operator=(const encry& n)
	{
		if (this == &n)
		{
			return *this;
		}
		if (mingwen != nullptr)
		{
			delete[]mingwen;
			if (n.mingwen != nullptr)
			{
				mingwen = new char[n.size + 1];
				strcpy(mingwen, n.mingwen);
			}
		}
		else
		{
			if (n.mingwen != nullptr)
			{
				mingwen = new char[n.size + 1];
				strcpy(mingwen, n.mingwen);
			}
			else mingwen = nullptr;
		}
		size = n.size;
		return *this;
	}

	// ���ܲ�����ʹ��������㣨curr XOR next��
	friend encry operator+(encry& curr, encry& next)
	{
		encry miwen(curr.size);
		cout << "���ܹ���: " << endl;
		for (int i = 0; i < curr.size; i++)
		{
			miwen.mingwen[i] = curr.mingwen[i] ^ next.mingwen[i % next.size];
			cout << "����[" << i << "]: " << curr.mingwen[i]
				<< " XOR ��Կ[" << i % next.size << "]: " << next.mingwen[i % next.size]
				<< " = ����[" << i << "]: " << miwen.mingwen[i] << endl;
		}
		return miwen;
	}

	// ���ܲ�����ʹ��������㣨curr XOR next��
	friend encry operator-(encry& curr, encry& next)
	{
		encry ming(curr.size);
		cout << "���ܹ���: " << endl;
		for (int i = 0; i < curr.size; i++)
		{
			ming.mingwen[i] = curr.mingwen[i] ^ next.mingwen[i % next.size];
			cout << "����[" << i << "]: " << curr.mingwen[i]
				<< " XOR ��Կ[" << i % next.size << "]: " << next.mingwen[i % next.size]
				<< " = ����[" << i << "]: " << ming.mingwen[i] << endl;
		}
		return ming;
	}
};

int main()
{
	int size1, size2;
	cout << "���������ĳ��Ⱥ���Կ����: (ע�⣬��һ�������ĳ��ȣ��ڶ�������Կ���ȣ����ɵ���)" << endl;
	cin >> size1 >> size2;

	cout << "�Ѵ������Ķ��󣬳���Ϊ" << size1 << endl;
	cout << "�Ѵ�����Կ���󣬳���Ϊ" << size2 << endl;
	encry c1(size1), c2(size2), c3, c4;

	cout << "\n��������������:" << endl;
	c1.input();

	cout << "\n��������Կ����:" << endl;
	c2.input();

	cout << "\n=== ��ʼ���� ===" << endl;
	c3 = c1 + c2;

	cout << "\n���ܽ��(ʮ������):" << endl;
	cout << "0x";
	for (int i = 0; i < size1; i++)
	{
		cout << hex << (int)(unsigned char)c3[i];  // ������ʽ����
	}
	cout << endl;

	cout << "\n=== ��ʼ���� ===" << endl;
	c4 = c3 - c2;

	cout << "\n���ܽ��(ASCII):" << endl;
	for (int i = 0; i < size1; i++)
	{
		cout << c4[i];
	}
	cout << endl;

	cout << "\n����ִ����ϣ���������˳�..." << endl;
	return 0;
}