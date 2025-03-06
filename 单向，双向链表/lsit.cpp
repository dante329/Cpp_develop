#include<iostream>
#include<list>

using namespace std;

void print(list<int>& l)
{
	for(auto x:l)
	{
		cout << x << " ";
	}
	cout << endl;
}

int main()
{
	list<int> l;
	for(int i=1;i<=5;i++)
	{
		l.push_back(i);
		print(l);
	}
	
	for(int i=1;i<=5;i++)
	{
		l.push_front(i);
		print(l);
	}
	
	for(int i=1;i<=3;i++)
	{
		l.pop_back();
	}
	print(l);
	
	for(int i=1;i<=3;i++)
	{
		l.pop_front();
	}
	print(l);
	return 0;
}
