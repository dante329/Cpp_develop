//错误贪心解法 
//#include<iostream> 
//#include<algorithm> 
//using namespace std;
//typedef long long LL;
//const int N = 1e5 + 10;
//struct node
//{
//	int t,d;	
//}a[N];
//int n;
//
//bool cmp(node n1,node n2)
//{
//	if(n1.t < n2.t) return true;
//	else if(n1.t == n2.t) return n1.d > n2.d;
//	else return false;
//}
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<=n;i++) cin >> a[i].t >> a[i].d;
//	sort(a+1,a+n+1,cmp);
//	LL sum = 0;
//	for(int i=1;i<=n;i++)
//	{
////		sum += a[i].t * a[i].d;
//		for(int j=i+1;j<=n;j++)
//		{
//			sum += a[i].t * 2 * a[j].d;
//		}
//	}
//	cout << sum;
//	return 0;
//}


//正确的要推公式
#include<iostream> 
#include<algorithm> 
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
struct node
{
	int t,d;	
}a[N];
int n;

bool cmp(node n1,node n2)
{
	return n1.t * n2.d < n2.t * n1.d;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].t >> a[i].d;
	sort(a+1,a+n+1,cmp);
	//这样的双循环最后一个节点会超时 
//	LL sum = 0;	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			sum += a[i].t * 2 * a[j].d; //第j个奶牛吃草的时间跟前面所有奶牛有关，可以用一个变量来累加前面所有的时间 
//		}
//	}

	//优化
	LL sum = 0,t = 0; //t表示当前位置前面所有的时间 
	for(int i=1;i<=n;i++)
	{
		sum += a[i].d * t; //抓捕当前牛不会消耗任何时间。第一次进入循环时，t为0。 
		t += 2 * a[i].t; //更新下一次的时间 
	} 
	cout << sum;
	return 0;
} 
