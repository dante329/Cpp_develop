#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL h[N],v[N];
LL sum[N];
LL n;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> h[i] >> v[i];
	
	stack<int> st;
	for(int i=1;i<=n;i++)
	{
		//单调递减栈，从左到右找，存下标 
		while(st.size() && h[st.top()] <= h[i]) st.pop();
		if(st.size()) sum[st.top()] += v[i];
		st.push(i); 
	}
	
	while(st.size()) st.pop();
	
	for(int i=n;i>=1;i--)
	{
		//单调递减栈，从右到左找，存下标 
		while(st.size() && h[st.top()] <= h[i]) st.pop();
		if(st.size()) sum[st.top()] += v[i];
		st.push(i); 
	}
	
	LL ret = 0;
	for(int i=1;i<=n;i++) ret = max(ret,sum[i]);
	cout << ret;
	return 0;
}
