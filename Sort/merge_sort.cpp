#include <iostream>

using namespace std;

int n;
const int N = 1e5 + 10;
int a[N];
int tmp[N];

void merge_sort(int left,int right)
{
	if(left>=right) return;
	int mid = (left + right) >> 1;
	//[left,mid][mid+1,right]
	merge_sort(left,mid);
	merge_sort(mid+1,right);
	
	int cur1 = left, cur2 = mid + 1, cur = left;
	while(cur1 <= mid && cur2 <= right)
	{
		if(a[cur1] <= a[cur2]) tmp[cur++] = a[cur1++];
		else tmp[cur++] = a[cur2++];
	}
	while(cur1 <= mid) tmp[cur++] = a[cur1++];
	while(cur2 <= right) tmp[cur++] = a[cur2++];
	
//	for(int i = 1;i <= n;i++) a[i] = tmp[i]; //����д�� 
	for(int i = left;i <= right;i++) a[i] = tmp[i]; //ÿ�ΰ��Լ������ڵ�tmp�����е����ݿ�����a�����У�������Χ��Ҫ�� 
}

int main()
{
	cin >> n;
	//������ 
	for(int i=1;i<=n;i++) cin >> a[i];
	
	merge_sort(1,n);
	
	//��ӡ��� 
	for(int i=1;i<=n;i++) cout << a[i] << " ";
	
	return 0;
} 


