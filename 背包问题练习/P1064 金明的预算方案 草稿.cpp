//�ݸ� 
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
//int cnt; //ͳ���ж��ٸ����� 
//int a[N]; //�����ļ۸� 
//int ap[N]; //������Ҫ��
////vector<PII> b[N]; //������<�۸���Ҫ��>
//
//int b[N]; //���������ϲ���ļ۸� 
//int bp[N];
//int pos;
//
//bool st[N]; //�����Щ����û�и��� 
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
//	//��û�и���������׷�ӵ�ȫ����Ʒ������ 
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

//���˼·�ǽ������͸����ϲ���һ����Ʒ������ֻ�������������У���������Ʒ��һ��01����
//���˼·�ʹ���ֱ�ӰѶ�����ϼ������飬��������ִ���״̬ ����ѡ�ˡ�A + A1������ѡ�ˡ�A + A2��ʵ�����൱�������������� A�����ǲ�����ģ�
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 70, M = 4e4 + 10;

int n,m;

int f[N][M];

int cnt; //ͳ���ж��ٸ����� 
int a[N]; //������Ʒ�ļ۸� 
int ap[N]; //������Ʒ��Ҫ��
vector<PII> b[N]; //������<�۸���Ҫ��> b[i]��i�������ĸ�����Ϣ 

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
		else b[q].push_back({v,p}); //���q������0���洢������Ϣ���������ܵ������� 
	}	
	
	for(int i=1;i<=cnt;i++)
	{
		int tmpv[2], tmpp[2], pos=0; 
		for(auto t:b[i])
		{
			int v = t.first, p = t.second;
			//��һ������ 
			a[++cnt] = v + a[i];
			ap[cnt] = p + ap[i]; 
			tmpv[++pos] = v, tmpp[pos] = p;
		}
		if(pos == 2) //���������������Ҫ������������ 
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
 
//ͬ��˼·������������Ż����ܵõ�40�� 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 70, M = 32010;

int n, m; // n ���ܽ�m ����Ʒ����
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
        // ��������Ӵ�С�������鱳��
        for (int j = n; j >= 0; j--) {
            // ֻ������
            if (j >= mains[i].v)
                f[j] = max(f[j], f[j - mains[i].v] + mains[i].w);

            // ���� + ����1
            if (mains[i].attachments.size() >= 1) {
                int v1 = mains[i].attachments[0].v;
                int w1 = mains[i].attachments[0].w;
                if (j >= mains[i].v + v1)
                    f[j] = max(f[j], f[j - mains[i].v - v1] + mains[i].w + w1);
            }

            // ���� + ����2
            if (mains[i].attachments.size() >= 2) {
                int v2 = mains[i].attachments[1].v;
                int w2 = mains[i].attachments[1].w;
                if (j >= mains[i].v + v2)
                    f[j] = max(f[j], f[j - mains[i].v - v2] + mains[i].w + w2);
            }

            // ���� + ����1 + ����2
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
					
