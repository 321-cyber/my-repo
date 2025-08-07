#include<iostream>
using namespace std;
struct point
{
	int score;
	int student_number;
	point* next;
};
point* conlin(int n)
{
point* head = (point*)malloc(sizeof(point));
	head->next = NULL;
	point* tail = head;
	for (int i = 0; i < n; i++)
	{
		point* newpoint = (point*)malloc(sizeof(point));
		cin >> newpoint->score >> newpoint->student_number;
		newpoint->next = NULL;
		tail->next = newpoint;
		tail = newpoint;
	}
	return head;
}
int main()
{
	int m;
	int n;
	cin >> n >> m;
	point* a=conlin(n);
	point* b=conlin(m);
	point* tail1 = NULL;
	point* tail2 = NULL;
	tail1 = a->next;
	tail2 = b->next;
	a = a->next;
	b = b->next;
	for (int i = 0; i < n-1; i++)
	{
		tail1 = tail1-> next;
		
	}
	for (int i = 0; i < m - 1; i++)
	{
		tail2 = tail2->next;
	}
	if (tail1->student_number > b->student_number)
	{
		tail1->next = b;
		for (int i = 0; i < m + n; i++)
		{
			cout << a->score << " " << a->student_number;
		}
	}
	else
	{
		tail2->next = a;
		for (int i = 0; i < m + n; i++)
		{
			cout << b->score << " " << b->student_number;
		}
	}
}