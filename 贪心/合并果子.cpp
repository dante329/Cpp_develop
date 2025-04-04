#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
	int n; cin >> n;
	while(n--)
	{
		int x; cin >> x;
		pq.push(x);	
	}
	long long ret = 0;
	while(pq.size() > 1)
	{
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		
		ret += x + y;
		pq.push(x + y); 
	}
	cout << ret;
	return 0;
}
