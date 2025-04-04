//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//vector<int> a;
//int w,n;
//
//int main()
//{
//	cin >> w >> n;
//	for(int i=1;i<=n;i++) 
//	{
//		int x; cin >> x;
//		a.push_back(x);	
//	} 	
//	sort(a.begin(),a.end());
//	int cnt = 0;
//	for(int i=0;i<=a.size();i++)
//	{
//		int j=a.size()-1;
//		while(j>=0 && a[j]+a[i]>w) j--;
//		a.erase(a.begin() + j - 1); 
//		cnt++;
//	}
//	while(!a.empty())
//	{
//		a.pop_back();
//		cnt++;	
//	} 
//	cout << cnt;
//	return 0;
//}

#include<iostream>
#include<algorithm>

using namespace std;
const int N = 3e4 + 10;
int a[N];
int w,n;

int main()
{
	cin >> w >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int cnt = 0;
	int left = 1,right = n;
	while(left <= right)
	{
		if(a[left] + a[right] <= w) cnt++,left++,right--;
		else cnt++,right--;
	}
	
	cout << cnt;
	return 0;
}
