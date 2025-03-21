//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int N = 2e5 + 10;
//int a[N];
//int n;
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<=n;i++) cin >> a[i]; 
//	int ret = 0;
//	for(int i=1;i<=n-2;i++)
//	{
//		int cnt = 0;
//		if(a[i] > 0)
//		{
//			if(abs(a[i+1])<abs(a[i+2]))
//			{
//				cnt = a[i] + a[i+1] + a[i+2];
//				ret = max(ret,cnt);
//			}
//		}
//	}
//	cout << ret;
//	
//	return 0;
//} 

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL; 
const int N = 2e5 + 10;
int a[N];
int n;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i]; 
	LL ret = -1e6;
	LL sum = 0;
	for(int i=1;i<=n;i++)
	{
		sum += a[i];
		ret = max(ret,sum); //ÿ��һ�����־ͻ���sum��retȡ������Բ��õ��Ĵ���ڽ�sum��0ǰ��ĳһ�κͺܴ��ֵ 
		if(sum < 0) sum = 0;
	}
	cout << ret;
	
	return 0;
} 
