#include<iostream>

using namespace std;

const int N = 360, M = 50;

int f[M][M][M][M]; //dp数组 
int n,m;
int cnt[5];
int x[N];

int main()
{
	//读数据 
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> x[i];
	for(int i=1;i<=m;i++)
	{
		int t; cin >> t;
		cnt[t]++;
	}
	
	//初始化
	f[0][0][0][0] = x[1]; //还没走的时候，得分就是起点位置的分数 
	
	//状态转移方程 
	for(int a=0;a<=cnt[1];a++) //从0开始，表示还没有用过这张卡片，到这张卡片的数量上限为止 
		for(int b=0;b<=cnt[2];b++)
			for(int c=0;c<=cnt[3];c++)
				for(int d=0;d<=cnt[4];d++)
				{
					//根据a、b、c、d计算出当前走哪了
					int i = 1 + a + b * 2 + c * 3 + d * 4; //计算位置别忘了加上起点位置的1！！！ 
					int& t = f[a][b][c][d]; //引用，t相当于f[a][b][c][d] 
					
					//每次判断要取最大值，因为你不知道使用哪张卡片得分最大 
					//边界情况也是同样适用的，比如说只有一张b拍，那么其他的条件判断都进不去，只能执行到b牌状态转移方程 
					if(a>=1) t = max(t, f[a-1][b][c][d] + x[i]);
					if(b>=1) t = max(t, f[a][b-1][c][d] + x[i]);
					if(c>=1) t = max(t, f[a][b][c-1][d] + x[i]);
					if(d>=1) t = max(t, f[a][b][c][d-1] + x[i]);
					
					//不能用下面这个判断，是错的 
//					if(a>=1) t = f[a-1][b][c][d] + x[i];
//					if(b>=1) t = f[a][b-1][c][d] + x[i];
//					if(c>=1) t = f[a][b][c-1][d] + x[i];
//					if(d>=1) t = f[a][b][c][d-1] + x[i];
				}
	
	cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
	
	return 0;
} 
