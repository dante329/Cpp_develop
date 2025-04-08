#include<iostream>
#include<ctime>
using namespace std;
const int N = 5e6 + 10;
int a[N];
int n,k;

int get_radom(int left,int right)
{
	return a[rand() % (right - left + 1) + left];
}

int quick_select(int left,int right,int k)
{
	if(left >= right) return a[left];
	
	int l = left - 1,r = right + 1,i = left;
	
	int p = get_radom(left,right);
	while(i < r)
	{
		if(a[i] < p) swap(a[i++],a[++l]);
		else if(a[i] == p) i++;
		else swap(a[i],a[--r]);
	}	
	
	//将k与各个区间元素个数作比较
	int a = l - left + 1, b = r - 1 - l, c = right - r + 1; 
	if(k <= a) return quick_select(left,l,k);
	else if(k <= a + b) return p;
	else return quick_select(r,right,k-a-b);
}

int main()
{
	//解绑cin、cout 或者使用scanf、printf都可以 
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	srand(time(0));
//	cin >> n >> k;
//	k++;
//	for(int i=1;i<=n;i++) cin >> a[i];
//	cout << quick_select(1,n,k) << endl;

	srand(time(0));
	scanf("%d%d",&n,&k);
	k++;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",quick_select(1,n,k));	
	return 0;
 } 
