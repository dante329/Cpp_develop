//草稿 
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int N = 70, M = 4e4 + 10;
//
//int n,m;
//
//int f[N][M];
//
//int cnt; //统计有多少个主件 
//int a[N]; //主件的价格 
//int ap[N]; //主件重要度
////vector<PII> b[N]; //附件的<价格，重要度>
//
//int b[N]; //主件附件合并后的价格 
//int bp[N];
//int pos;
//
//bool st[N]; //标记哪些主件没有附件 
//
////int main()
////{
////	cin >> m >> n;
////	
////	for(int i=1;i<=n;i++)
////	{
////		int v,p,q; cin >> v >> p >> q;
////		if(q == 0) 
////		{
////			a[++cnt] = v; 
////			ap[cnt] = p;
////		}
////		else a[q].push_back({v,p}); 
////	}	
////	
////	for(int i=1;i<=cnt;i++)
////	{
////		for(auto t:b[i])
////	}
////	
////	return 0;
//// } 
// 
//int main()
//{
//	cin >> m >> n;
//	
//	for(int i=1;i<=n;i++)
//	{
//		int v,p,q; cin >> v >> p >> q;
//		if(q == 0) 
//		{
//			a[++cnt] = v; 
//			ap[cnt] = p;
//		}
//		else 
//		{
//			b[++pos] = v + a[q];
//			bp[pos] = p + ap[q];
//			st[q] = true;
//		 } 
//	}	
//	
//	//将没有附件的主件追加到全部物品数组中 
//	for(int i=1;i<=cnt;i++)
//	{
//		if(!st[i])
//		{
//			b[++pos] = a[i];
//			bp[pos] = ap[i];
//		}
//	}
//	
//	for(int i=1;i<=pos;i++) 
//	{
////		cout << "cnt:" << cnt << endl;
////		cout << "pos:" << pos << endl;
//		cout << "b[i]:" << b[i] << " ";
//		cout << "bp[i]:" << bp[i] << " " << endl;
//	}
//	
//	for(int i=1;i<=pos;i++)
//	{
//		for(int j=0;j<=m;j++)
//		{
//			f[i][j] = f[i-1][j];
//			if(j >= b[i])
//			{
//				f[i][j] = max(f[i][j],f[i-1][j-b[i]] + b[i] * bp[i]);
//			}
//		}	
//	}
//	
////	for(int i=1;i<=pos;i++)
////	{
////		for(int j=0;j<=m;j++)
////		{
////			cout << f[i][j] << " ";
////		}	
////		cout << endl;
////	}
//	
//	cout << f[pos][m];
//	
//	return 0;
// } 
// 	

//这个思路是将主键和附件合并成一个物品，放入只有主件的数组中，对所有物品做一次01背包
//这个思路就错在直接把多种组合加入数组，会出现这种错误状态 ：既选了「A + A1」，又选了「A + A2」实际上相当于用了两次主件 A，这是不允许的！
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 70, M = 4e4 + 10;

int n,m;

int f[N][M];

int cnt; //统计有多少个主件 
int a[N]; //所有物品的价格 
int ap[N]; //所有物品重要度
vector<PII> b[N]; //附件的<价格，重要度> b[i]：i号主件的附件信息 

int main()
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++)
	{
		int v,p,q; cin >> v >> p >> q;

		if(q == 0)
		{
			a[++cnt] = v; 
			ap[cnt] = p;
		}		
		else b[q].push_back({v,p}); //如果q不等于0，存储附件信息，附件不能单独购买 
	}	
	
	for(int i=1;i<=cnt;i++)
	{
		int tmpv[2], tmpp[2], pos=0; 
		for(auto t:b[i])
		{
			int v = t.first, p = t.second;
			//买一个附件 
			a[++cnt] = v + a[i];
			ap[cnt] = p + ap[i]; 
			tmpv[++pos] = v, tmpp[pos] = p;
		}
		if(pos == 2) //如果有两个附件就要考虑两个都买 
		{
			a[++cnt] = tmpv[1] + tmpv[2] + a[i];
			ap[cnt] = tmpp[1] + tmpp[2] + ap[i];
		}
	}
	
//	for(int i=1;i<=cnt;i++) 
//	{
//		cout << "cnt:" << cnt << endl;
//		cout << "a[i]:" << a[i] << " ";
//		cout << "ap[i]:" << ap[i] << " " << endl;
//	}
	
	for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= a[i])
			{
				f[i][j] = max(f[i][j],f[i-1][j-a[i]] + a[i] * ap[i]);
			}
		}	
	}
	
	cout << f[cnt][m];
	
	return 0;
 } 
 
//同上思路，代码进行了优化，能得到40分 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 70, M = 32010;

int n, m; // n 是总金额，m 是物品个数
int f[M];

struct Item {
    int v, w;
};

struct MainItem {
    int v, w;
    vector<Item> attachments;
};

MainItem mains[N];

int main() {
    cin >> n >> m;

    int idx = 0;
    for (int i = 1; i <= m; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        if (q == 0) {
            mains[++idx].v = v;
            mains[idx].w = v * p;
        } else {
            mains[q].attachments.push_back({v, v * p});
        }
    }

    for (int i = 1; i <= idx; i++) {
        // 遍历体积从大到小，做分组背包
        for (int j = n; j >= 0; j--) {
            // 只买主件
            if (j >= mains[i].v)
                f[j] = max(f[j], f[j - mains[i].v] + mains[i].w);

            // 主件 + 附件1
            if (mains[i].attachments.size() >= 1) {
                int v1 = mains[i].attachments[0].v;
                int w1 = mains[i].attachments[0].w;
                if (j >= mains[i].v + v1)
                    f[j] = max(f[j], f[j - mains[i].v - v1] + mains[i].w + w1);
            }

            // 主件 + 附件2
            if (mains[i].attachments.size() >= 2) {
                int v2 = mains[i].attachments[1].v;
                int w2 = mains[i].attachments[1].w;
                if (j >= mains[i].v + v2)
                    f[j] = max(f[j], f[j - mains[i].v - v2] + mains[i].w + w2);
            }

            // 主件 + 附件1 + 附件2
            if (mains[i].attachments.size() == 2) {
                int v1 = mains[i].attachments[0].v, w1 = mains[i].attachments[0].w;
                int v2 = mains[i].attachments[1].v, w2 = mains[i].attachments[1].w;
                if (j >= mains[i].v + v1 + v2)
                    f[j] = max(f[j], f[j - mains[i].v - v1 - v2] + mains[i].w + w1 + w2);
            }
        }
    }

    cout << f[n] << endl;
    return 0;
}
					
