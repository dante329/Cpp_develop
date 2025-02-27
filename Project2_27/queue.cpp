#include<iostream>
#include<queue> 
using namespace std;

typedef pair<int,int> PII;

int main()
{
	queue<PII> q;
	for(int i=1;i<=10;i++)
	{
		q.push({i,i*10});	
	}	
	for(int i=1;i<=10;i++)
	{
		auto t = q.front();
		cout << t.first << " " << t.second << endl;
		q.pop();
	}
	return 0;
}
