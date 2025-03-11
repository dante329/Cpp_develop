//#include<iostream>
//#include<map> 
//using namespace std;
//
//int n,p;
//map<string,int> mp1,mp2; //mp1用来存储高级词汇，mp2存储英语作文 
//
//const int N = 60;
//char ch[N];
//
//int main()
//{
//	cin >> n >> p;
//	for(int i = 1;i <= n;i++)
//	{
//		string str;
//		int value;
//		cin >> str >> value;
//		mp1.insert({str,value}); 
//	}	
//	int i = 1;
//	char t;
//	while(cin >> t)
//	{
//		if(t == ' ' || t == '.' || t == ',' || t == '!' || t == '?')
//		{
//			string str; 
//			for(int j=1;j<=i;j++)
//			{
//				str += ch[j];
//			}
//			mp2[str]++; 
//			i = 1;
//			continue;
//		}
//		else
//		{
//			ch[i++] = t;
//		}
//
//	}
//	long long sum = 0;
//	for(auto x:mp1)
//	{
//		int count = mp2.count(x.first);
//		int value = x.second;
//		sum += count * value;
//	}
//	cout << sum % p << endl;
//	return 0;
//}


//#include<iostream>
//#include<map> 
//using namespace std;
//
//int n, p;
//map<string, int> mp1;
//
//int main()
//{
//	cin >> n >> p;
//	for (int i = 1; i <= n; i++)
//	{
//		string str;
//		int value;
//		cin >> str >> value;
//		mp1.insert({str,value});
////		mp1[str] = value;
//	}
//	char t;
//	string str = "";
//	long long sum = 0;
//	while (scanf("%c",&t) != EOF) //这里是不能用cin的，cin不读空白字符
//	{
//		if ((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9'))
//		{
//			str += t;
//		}
//		else
//		{
//			sum += mp1[str]; 
////			sum = (sum + mp1[str]) % p;
//			str = "";
//		}
//	}
//	
//	cout << sum % p << endl;
////	cout << sum << endl;
//	return 0;
//}
//

//#include<iostream>
//#include<map>
//
//using namespace std;
//map<string,int> mp;
//int n,p;
//
//int main()
//{
//	cin >> n >> p;
//	for(int i=1;i<=n;i++)
//	{
//		string s; int a;
//		cin >> s >> a;
//		mp.insert({s,a});
//	}
//	char ch;
//	string t;
//	long long sum = 0;
//	while(scanf("%c",&ch) != EOF)
//	{
//		if((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <= '9')) 
//		{
//			t += ch;
//		}
//		else
//		{
//			sum += mp[t];
//			t = "";
//		}
//	}
//	cout << sum % p << endl;
//	return 0;
// } 


//P2234
//#include<iostream>
//#include<set>
//using namespace std; 
//const int INF = 1e7;
//int n,ret;
//set<int> mp;
//
//int main()
//{
//	cin >> n;
//	cin >> ret;
//	mp.insert(ret); 
//	mp.insert(INF);
//	mp.insert(-INF);
//	for(int i=2;i<=n;i++)
//	{
//		int t;
//		cin >> t;
//		auto it = mp.lower_bound(t);
//		if(*it == t) continue;
//		
//		auto tmp = it;
//		tmp--;
//		
//		ret += min(abs(*it-t),abs(*tmp-t));
//		mp.insert(t); 
//	}
//	cout << ret << endl;
//	return 0;
//}

//P5250
//#include<iostream>
//#include<set>
//#include<cmath>
//using namespace std;
//
//int INF = 1e10;
//
//int n;
//set<int> mp;
//
//int main()
//{
//	cin >> n;
//	mp.insert(INF); mp.insert(-INF);
//	while(n--)
//	{
//		int op,len;
//		cin >> op >> len;
//		if(op == 1)
//		{
//			if(mp.count(len) == 0) mp.insert(len);
//			else cout << "Already Exist" << endl;	
//		}
//		else
//		{
//			auto it = mp.lower_bound(len);
//			auto tmp = it; tmp--;
//			if(abs(len-*tmp) == abs(len-*it)) 
//			{
//				cout << *tmp << endl;
//				mp.erase(tmp);				
//			}
//			else 
//			{		
//				int ret = min(abs(len-*tmp),abs(len-*it));
//				if(ret <= pow(10,9)) 
//				{
//					if(abs(len-*tmp) < abs(len-*it))
//					{
//						cout << *tmp << endl;
//						mp.erase(tmp);
//					} 
//					else
//					{
//						cout << *it << endl;
//						mp.erase(it);
//					}
//					
//				}
//				else
//				{
//					cout << "Empty" << endl;
//				 } 
//			}
//		}
//	}
//	
//	return 0;
//}

#include<iostream>
#include<set>

using namespace std;

const long long INF = 1e10 + 10;

int n;
set<long long> mp;

int main()
{
	cin >> n;
	mp.insert(INF); mp.insert(-INF);
	while(n--)
	{
		int op,len;
		cin >> op >> len;
		if(op == 1)
		{
			if(mp.count(len) == 0) mp.insert(len);
			else cout << "Already Exist" << endl;	
		}
		else
		{
			auto it = mp.lower_bound(len);
			auto tmp = it; tmp--;
			if(mp.size() == 2)
			{
				cout << "Empty" << endl;
			} 
			else if(abs(len-*tmp) <= abs(len-*it)) 
			{
				cout << *tmp << endl;
				mp.erase(tmp);				
			}
			else 
			{		
				cout << *it << endl;
				mp.erase(it);			
			}
		}
	}
	
	return 0;
}    
