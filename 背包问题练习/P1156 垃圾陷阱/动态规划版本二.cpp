//f[i][j]��ʾ�����Ի�ѣ����i��������ʣ��j����ʱ���ܶѵ������߶�
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
	for(int i=1;i<=g;i++){//���������ʱ��
		lif-=a[i].t-a[i-1].t;
		if(lif<0) break;
		lif+=a[i].f;
		maxt+=a[i].f;//�����ʱ��
		maxtt[i]=maxtt[i-1]+a[i].f;//ǰi�������������ʱ�䣬û���ϣ���Ҳ����ɾ��
	}
	vis[0][10]=1;//vis����������¼��Щ״̬���ܵ����
	for(int i=1;i<=g;i++){
		for(int j=maxt;j>=0;j--){
			if(vis[i-1][j+(a[i].t-a[i-1].t)]){//��i���������ڶѷŵ����
				f[i][j]=max(f[i][j],f[i-1][j+(a[i].t-a[i-1].t)]+a[i].h);//�������ǰһ��״̬�ǿ��Ե���ģ���ô�Ϳ��Դ�ǰһ״̬����ת�Ƶ���ǰ״̬
				vis[i][j]=1;//��Ϊ��״̬�ǿ��Ե���ģ����ϱ��
			}
			if(vis[i-1][j+(a[i].t-a[i-1].t)]){//��i���������ڳԵ����
				f[i][j+a[i].f]=max(f[i][j+a[i].f],f[i-1][j+(a[i].t-a[i-1].t)]);//�������ǰһ��״̬�ǿ��Ե���ģ���ô�Ϳ��Դ�ǰһ״̬����ת�Ƶ���ǰ״̬
				vis[i][j+a[i].f]=1;//��Ϊ��״̬�ǿ��Ե���ģ����ϱ��
			}	
			if(f[i][j]>=d){//����߶��Ѿ������˾�����ȣ��ǾͿ��Գ�����
				ans=a[i].t;//��¼ʱ��
				break;//��Ϊ�Ź����ˣ����Ե�һ���ҵ���һ������С��,ֱ���˳�����
			}
		}
		if(ans!=INF) break;
	}
	if(ans==INF) cout<<maxt;//ansû�иĶ�˵�����ܳ�������������ʱ��
	else cout<<ans;//�����������ʱ��ʱ��
	return 0;
}
