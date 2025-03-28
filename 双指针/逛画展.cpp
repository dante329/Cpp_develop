//#include <iostream>
//#include <unordered_map>
//using namespace std;
//const int N = 1e6 + 10;
//int a[N];
//int n,m;
//unordered_map<int,int> mp; 
//
//pair<int,int> solve()
//{
//	int left = 1,right = 1,ret = 0;
//	while(right <= n)
//	{
//		//������
//		mp[a[right]]++;
//		//�ж��Ƿ�Ϸ�
//		while(mp[a[right]] > 1)	
//		{
//			mp[a[left++]]--;
//		}
//		ret = max(ret,right-left+1);
//		right++;
//		if(ret >= m) return {left,right};
//		else return {-1,-1};
//		
//	}
//}
//
//int main() 
//{
//	cin >> n >> m; 
//	for(int i=1;i<=n;i++) cin >> a[i];
//	auto ret = solve();
//	cout << ret.first << " " << ret.second;
//	return 0;
//}

#include <iostream>
using namespace std;
const int N = 1e6 + 10,M = 2e3 + 10;
int a[N];
int n,m;
int mp[M],kind; 

int main() 
{
	cin >> n >> m; 
	for(int i=1;i<=n;i++) cin >> a[i];
	//��ʼ��
	int left = 1,right = 1,ret = n,	begin = 1; 
	while(right <= n)
	{
		if(mp[a[right]]++ == 0) kind++; //����++ 
		while(kind == m)
		{			
			if(ret > right-left+1)
			{
				ret = right-left+1;
				begin = left;
			} 
			
			if(mp[a[left++]]-- == 1) kind--;
		}
		right++;
	}
	cout << begin << " " << begin + ret - 1;
	return 0;
}
