#include<iostream>
#include<string>
using namespace std;
struct Student
{
	string name;
	string ID;
	int English_scores;
	int Math_scores;
};
int input(Student* p, int num);
int outaverage(Student* p, int num);
int Graderank(Student* p, int num);
int printtable(Student* p, int num);

int main()
{
	int num;
	cout << "�������ж���ѧ��" << endl;
	cin >> num;
	Student* p;
	p = new Student[num];
	if (p == 0)
	{
		cout << "wrong" << endl;
	}
	input(p, num);
	outaverage(p, num);
	Graderank(p, num);
	printtable(p, num);
	delete[]p;
	return 0;
}
int input(Student* p, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << p[i].name << "ͬѧ�����֣�ѧ�ţ�Ӣ��ɼ�����ѧ�ɼ�" << endl;
		cin >> p[i].name >> p[i].ID >> p[i].English_scores >> p[i].Math_scores;
	}
	return 0;
}
int outaverage(Student* p, int num)
{
	float* aver;
	aver = new float[num];
	for (int i = 0; i < num; i++)
	{
		aver[i] = (p[i].English_scores + p[i].Math_scores) / 2.0;
	}
	for (int i = 0; i < num; i++)
	{
		cout << p[i].name << "ͬѧ��ƽ���ɼ�Ϊ" << aver[i] << endl;
	}
	delete[]aver;
	return 0;
}
int Graderank(Student* p, int num)
{
	float* aver;
	aver = new float[num];
	for (int i = 0; i < num; i++)
	{
		aver[i] = (p[i].English_scores + p[i].Math_scores) / 2.0;
	}
	for (int i = 0; i < num - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < num; j++)
		{
			if (aver[j] < aver[min])  // ����Сֵ������Сֵ�������Ҳ�
			{
				min = j;
			}
		}
		if (min != i)
		{
			float t = aver[min];
			aver[min] = aver[i];
			aver[i] = t;
			Student temp = p[min];
			p[min] = p[i];
			p[i] = temp;  // ��Сֵ�ŵ���ǰλ��i����ֵ���Ƶ����
		}
	}
	return 0;
}
int printtable(Student* p, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << p[i].name << "ͬѧ�ĳɼ�Ϊ" << p[i].English_scores << " " << p[i].Math_scores << endl;
	}
	return 0;
}