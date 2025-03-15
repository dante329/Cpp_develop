#include <iostream>
#include <ctime>

using namespace std;

int n;
const int N = 1e5 + 10;
int a[N];

int get_random(int left,int right) //随机选基准值 
{
	return a[rand() % (right - left + 1) + left];
}

void quick_sort(int left,int right)
{
	if(left >= right) return;
	int p = get_random(left,right); //选基准值p 
	int l = left - 1, i = left, r = right + 1;
	while(i < r)
	{
		if(a[i] > p) swap(a[--r],a[i]); //大于p，与右边的交换，i不能加，新换来的元素还没判断 
		else if(a[i] < p) swap(a[++l],a[i++]); //小于p，与左边的交换 
		else i++; //与p相等，i++  
	}
	//[left,l][l+1,r-1][r,right]
	quick_sort(left,l);
	quick_sort(r,right);
} 

int main()
{
	srand(time(0));
	cin >> n;
	//读数据 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	quick_sort(1,n);
	//打印结果 
	for(int i=1;i<=n;i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}
