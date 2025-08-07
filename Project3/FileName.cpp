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
	cout << "请输入有多少学生" << endl;
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
		cout << p[i].name << "同学的名字，学号，英语成绩，数学成绩" << endl;
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
		cout << p[i].name << "同学的平均成绩为" << aver[i] << endl;
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
			if (aver[j] < aver[min])  // 找最小值，将最小值交换到右侧
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
			p[i] = temp;  // 最小值放到当前位置i，大值逐渐移到左侧
		}
	}
	return 0;
}
int printtable(Student* p, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << p[i].name << "同学的成绩为" << p[i].English_scores << " " << p[i].Math_scores << endl;
	}
	return 0;
}