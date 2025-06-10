//f[i][j]表示处理（吃或堆）完第i个垃圾后还剩余j生命时所能堆到的最大高度
#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct Node{
	int t,f,h;
}a[105];
int maxt=10;
int ans=INF;
int f[105][3050];
int vis[105][3050];
int maxtt[105]={10};
int cmp(Node a,Node b){
	return a.t<b.t;
}
int main(){
	int d,g;
	scanf("%d%d",&d,&g);
	for(int i=1;i<=g;i++)
	scanf("%d%d%d",&a[i].t,&a[i].f,&a[i].h);
	sort(a+1,a+1+g,cmp);
	int lif=10;
	for(int i=1;i<=g;i++){//计算最大存活时间
		lif-=a[i].t-a[i-1].t;
		if(lif<0) break;
		lif+=a[i].f;
		maxt+=a[i].f;//最大存活时间
		maxtt[i]=maxtt[i-1]+a[i].f;//前i个垃圾的最大存活时间，没用上，但也懒得删了
	}
	vis[0][10]=1;//vis数组用来记录那些状态是能到达的
	for(int i=1;i<=g;i++){
		for(int j=maxt;j>=0;j--){
			if(vis[i-1][j+(a[i].t-a[i-1].t)]){//第i个垃圾用于堆放的情况
				f[i][j]=max(f[i][j],f[i-1][j+(a[i].t-a[i-1].t)]+a[i].h);//如果他的前一个状态是可以到达的，那么就可以从前一状态可以转移到当前状态
				vis[i][j]=1;//因为该状态是可以到达的，打上标记
			}
			if(vis[i-1][j+(a[i].t-a[i-1].t)]){//第i个垃圾用于吃的情况
				f[i][j+a[i].f]=max(f[i][j+a[i].f],f[i-1][j+(a[i].t-a[i-1].t)]);//如果他的前一个状态是可以到达的，那么就可以从前一状态可以转移到当前状态
				vis[i][j+a[i].f]=1;//因为该状态是可以到达的，打上标记
			}	
			if(f[i][j]>=d){//如果高度已经超过了井的深度，那就可以出来了
				ans=a[i].t;//记录时间
				break;//因为排过序了，所以第一个找到的一定是最小的,直接退出即可
			}
		}
		if(ans!=INF) break;
	}
	if(ans==INF) cout<<maxt;//ans没有改动说明不能出来，输出最大存活时间
	else cout<<ans;//否则输出出来时的时间
	return 0;
}
