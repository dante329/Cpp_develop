#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 20;
int a[N][N];
int col[N]; //行的选择靠二进制枚举，列就统计没有枚举的 
int n,m,k;

int calc(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt++;
		x &= x-1;
		//x -= x & -x;
	}
	return cnt;
}

bool cmp(int x1,int x2)
{
	return x1 > x2;
}

int main()
{
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	int ret = 0;
	//枚举行的选择的所有可能 行的选择是确定的，只需要累加，但是列的选择是根据剩余的次数选择前几个最大的列 
	for(int st=0;st<=(1<<n)-1;st++)
	{
		if(k-calc(st)<0) continue; //1的个数大于k非法 
		//合法就看哪一位是1，就对哪一行全部加起来，所以就要用一个变量储存结果
		memset(col,0,sizeof col);
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if((st >> i) & 1) sum += a[i][j];
				else col[j] += a[i][j];
			}
		} 		
		sort(col,col + m,cmp); //cmp升序
		for(int i=0;i<min(k-calc(st),m);i++) sum += col[i]; //k的范围比较大，k-calc(st)有可能超过m
		ret = max(ret,sum);
	}
	cout << ret;
	return 0;
}
