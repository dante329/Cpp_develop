//����̰�Ľⷨ 
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


//��ȷ��Ҫ�ƹ�ʽ
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
	//������˫ѭ�����һ���ڵ�ᳬʱ 
//	LL sum = 0;	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			sum += a[i].t * 2 * a[j].d; //��j����ţ�Բݵ�ʱ���ǰ��������ţ�йأ�������һ���������ۼ�ǰ�����е�ʱ�� 
//		}
//	}

	//�Ż�
	LL sum = 0,t = 0; //t��ʾ��ǰλ��ǰ�����е�ʱ�� 
	for(int i=1;i<=n;i++)
	{
		sum += a[i].d * t; //ץ����ǰţ���������κ�ʱ�䡣��һ�ν���ѭ��ʱ��tΪ0�� 
		t += 2 * a[i].t; //������һ�ε�ʱ�� 
	} 
	cout << sum;
	return 0;
} 
