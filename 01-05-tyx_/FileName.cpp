#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include <limits> 
using namespace std;

// 加密类：支持使用异或运算进行简单加密和解密
class encry
{
private:
	char* mingwen = nullptr;  // 存储明文或密文
	int size;              // 字符串长度
public:
	// 构造函数：初始化指定长度的字符数组
	encry(int b = 0)
	{
		size = b;
		mingwen = new char[size + 1];
	}

	// 输入函数：读取用户输入的字符串
	void input()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入" << size << "个字符: ";
		for (int i = 0; i < size; i++)
		{
			cin >> mingwen[i];
		}
	}

	// 下标运算符重载：访问指定位置的字符
	char operator[](int dex)
	{
		if (dex >= size)
		{
			cout << "溢出" << endl;
			exit(2);
		}
		else
		{
			return mingwen[dex];
		}
	}

	// 赋值运算符重载：实现深拷贝
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

	// 加密操作：使用异或运算（curr XOR next）
	friend encry operator+(encry& curr, encry& next)
	{
		encry miwen(curr.size);
		cout << "加密过程: " << endl;
		for (int i = 0; i < curr.size; i++)
		{
			miwen.mingwen[i] = curr.mingwen[i] ^ next.mingwen[i % next.size];
			cout << "明文[" << i << "]: " << curr.mingwen[i]
				<< " XOR 密钥[" << i % next.size << "]: " << next.mingwen[i % next.size]
				<< " = 密文[" << i << "]: " << miwen.mingwen[i] << endl;
		}
		return miwen;
	}

	// 解密操作：使用异或运算（curr XOR next）
	friend encry operator-(encry& curr, encry& next)
	{
		encry ming(curr.size);
		cout << "解密过程: " << endl;
		for (int i = 0; i < curr.size; i++)
		{
			ming.mingwen[i] = curr.mingwen[i] ^ next.mingwen[i % next.size];
			cout << "密文[" << i << "]: " << curr.mingwen[i]
				<< " XOR 密钥[" << i % next.size << "]: " << next.mingwen[i % next.size]
				<< " = 明文[" << i << "]: " << ming.mingwen[i] << endl;
		}
		return ming;
	}
};

int main()
{
	int size1, size2;
	cout << "请输入明文长度和密钥长度: (注意，第一个是明文长度，第二个是密钥长度，不可调换)" << endl;
	cin >> size1 >> size2;

	cout << "已创建明文对象，长度为" << size1 << endl;
	cout << "已创建密钥对象，长度为" << size2 << endl;
	encry c1(size1), c2(size2), c3, c4;

	cout << "\n请输入明文内容:" << endl;
	c1.input();

	cout << "\n请输入密钥内容:" << endl;
	c2.input();

	cout << "\n=== 开始加密 ===" << endl;
	c3 = c1 + c2;

	cout << "\n加密结果(十六进制):" << endl;
	cout << "0x";
	for (int i = 0; i < size1; i++)
	{
		cout << hex << (int)(unsigned char)c3[i];  // 修正格式问题
	}
	cout << endl;

	cout << "\n=== 开始解密 ===" << endl;
	c4 = c3 - c2;

	cout << "\n解密结果(ASCII):" << endl;
	for (int i = 0; i < size1; i++)
	{
		cout << c4[i];
	}
	cout << endl;

	cout << "\n程序执行完毕，按任意键退出..." << endl;
	return 0;
}