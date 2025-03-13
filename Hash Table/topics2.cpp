//#include<iostream>
//#include<unordered_set>
//#include<vector>
//
//using namespace std;
//
//
//
//int main()
//{
//	int T; cin >> T;
//	while(T--)
//	{
//		unordered_set<int> mp;
//		vector<int> ret;	
//		int n; cin >> n;
//		for(int i=1;i<=n;i++)
//		{
//			int tmp; cin >> tmp;
//			if(mp.count(tmp) == 0)
//			{
//				ret.push_back(tmp);
//				mp.insert(tmp);  
//			}
//		}
//		for(int x:ret)
//		{
//			cout << x << " ";
//		}
//		cout << endl;
//
//	}			
//	return 0;
//}

//#include<iostream>
//#include<unordered_set>
//#include<vector>
//
//using namespace std;
//
//unordered_set<int> mp;
//vector<int> ret;
//
//int main()
//{
//	int T; scanf("%d",&T);
//	while(T--)
//	{
//		int n; scanf("%d",&n);
//		for(int i=1;i<=n;i++)
//		{
//			int tmp; scanf("%d",&tmp);;
//			if(mp.count(tmp) == 0)
//			{
//				ret.push_back(tmp);
//				mp.insert(tmp);  
//			}
//		}
//	}	
//	
//	for(int x:ret)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<set>
//#include<unordered_map>
//using namespace std;
//unordered_map<string,set<int>> mp;
//
//int main()
//{
//	int T; cin >> T;
//	while(T--)
//	{
//		int n; cin >> n;
//		for(int i=1;i<=n;i++)
//		{
//			string s; cin >> s;
//			mp[s].insert(i);
//		}		 
//	}
//	int T2; cin >> T2;
//	while(T2--)
//	{
//		string s; cin >> s;
//		if(mp[s].size() == 0) cout << endl;
//		else
//		{
//			for(auto it=mp[s].begin();it!=--mp[s].end();it++)
//			{
//				cout << *it << " ";
//			}
//			cout << *(--mp[s].end()) << endl;
//		} 
//	}
//	return 0;
//}

//#include<iostream>
//#include<set>
//#include<unordered_map>
//using namespace std;
//unordered_map<string,set<int>> mp;
//
//int main()
//{
//	int T1; cin >> T1;
//	for(int i = 1;i <= T1;i++)
//	{
//		int n; cin >> n;
//		for(int j=1;j<=n;j++)
//		{
//			string s; cin >> s;
//			mp[s].insert(i);
//		}		 
//	}
//	int T2; cin >> T2;
//	while(T2--)
//	{
//		string s; cin >> s;
//		for(auto x:mp[s]) 
//		{
//			cout << x << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//P1102
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//typedef long long LL;
//
//unordered_map<int,int> mp;
//
//const int N = 2e5 + 10;
//int a[N];
//
//int main()
//{
//	int n,c; 
//	cin >> n >> c;
//	for(int i=1;i<=n;i++)
//	{
//		cin >> a[i];
//		mp[a[i]]++;	
//	}	
//	LL ret = 0;
//	for(int i=1;i<=n;i++)
//	{
//		ret += mp[a[i] + c];
//	}
//	cout << ret;
//	return 0; 
//}    

//P3405
//#include<iostream>
//#include<unordered_map>
//
//using namespace std;
//unordered_map<string,int> mp;
//
//void print(unordered_map<string,int>& mp)
//{
//	for(auto x:mp)
//	{
//		cout << x.first << " " << x.second;
//	}
// } 
// 
//int main()
//{
//	//unordered_map 的键是唯一的，这意味着你不能插入具有相同键的多个元素。当你尝试插入一个已经存在的键时，插入操作不会生效，原有的键值对不会被替换或修改。
//	mp.insert({"张三",10});	
//	mp.insert({"张三",1});
//	mp.insert({"张三",143});
//	mp.insert({"张三",10});
//	print(mp);			
//	
//	return 0;
//}	

#include<iostream>
#include<unordered_map>

using namespace std;
unordered_map<string,int> mp;

int main()
{
	int n; cin >> n;
	int ret = 0;
	while(n--) //一遍存储数据一边对数据进行匹配，免得存储完了还要遍历 
	{
		string a,b;
		cin >> a >> b;
		a = a.substr(0,2);
		if(a == b) continue;
		mp[a+b]++;
		ret += mp[ b+a];
	}
	cout << ret << endl;
	return 0;
																																																																																																																																																																																																																																																																																																																										  }																																																																																																																																																												                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
