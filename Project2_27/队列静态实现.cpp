#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N],h,t; //h指向第一个有效元素的前一个位置，下标0位置不存放元素，t指向最后一个元素                                                                    

void push(int x)
{
	a[++t] = x;	
}

void pop()
{
	h++;
}

int front()
{
	return a[h+1];
}

int back()
{
	return a[t];
}

int size()
{
	return t-h;
}

bool empty()
{	
	return t==h;
}

int main()
{
	for(int i=1;i<=10;i++)
	{
		push(i);
	}
	for(int i=1;i<=10;i++)
	{
		cout << front() << " " << back() << endl;
		pop();
	}
	
	return 0;
}
