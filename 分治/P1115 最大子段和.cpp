#include<iostream>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;

int dfs(int left,int right)
{
	if(left == right) return a[left];
	
	int mid = (left + right) / 2;
	int ret = max(dfs(left,mid),dfs(mid+1,right));
	
	//�������������Ӷκ� 
	
	//�������
	//ʹ�� lmax �� rmax ��ʾ�������ͣ���ʼ��Ϊ 0��
	//���ܵ����߼��������������Ϊ������lmax �� rmax �ᱻ����ظ�ֵΪ 0������ʵ�ʵ�������ͣ��� 
//	int sum = 0, lmax = 0;
//	for(int i=mid;i>=left;i--)
//	{
//		sum += a[i];
//		lmax = max(sum,lmax);
//	}
//	sum = 0; int rmax = 0;
//	for(int i = mid+1;i<=right;i++)
//	{
//		sum += a[i];
//		rmax = max(sum,rmax);
//	}
//	
//	ret = max(ret,lmax+rmax);
//	return ret;

	int sum = a[mid], lmax = sum;
	for(int i=mid-1;i>=left;i--)
	{
		sum += a[i];
		lmax = max(sum,lmax);
	}
	sum = a[mid+1]; int rmax = sum;
	for(int i = mid+2;i<=right;i++)
	{
		sum += a[i];
		rmax = max(sum,rmax);
	}
	
	ret = max(ret,lmax+rmax);
	return ret;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	cout << dfs(1,n) << endl; 
	return 0;
 } 
