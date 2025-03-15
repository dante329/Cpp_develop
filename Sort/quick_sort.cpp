#include <iostream>
#include <ctime>

using namespace std;

int n;
const int N = 1e5 + 10;
int a[N];

int get_random(int left,int right) //���ѡ��׼ֵ 
{
	return a[rand() % (right - left + 1) + left];
}

void quick_sort(int left,int right)
{
	if(left >= right) return;
	int p = get_random(left,right); //ѡ��׼ֵp 
	int l = left - 1, i = left, r = right + 1;
	while(i < r)
	{
		if(a[i] > p) swap(a[--r],a[i]); //����p�����ұߵĽ�����i���ܼӣ��»�����Ԫ�ػ�û�ж� 
		else if(a[i] < p) swap(a[++l],a[i++]); //С��p������ߵĽ��� 
		else i++; //��p��ȣ�i++  
	}
	//[left,l][l+1,r-1][r,right]
	quick_sort(left,l);
	quick_sort(r,right);
} 

int main()
{
	srand(time(0));
	cin >> n;
	//������ 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	quick_sort(1,n);
	//��ӡ��� 
	for(int i=1;i<=n;i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}
