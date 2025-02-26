//#include <iostream>
//#include <string>
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//typedef unsigned long long LL;
//LL stk[N];
//int T,round;
//LL x;
//string op;
//
//void push(LL x)
//{
//	stk[++n] = x;
//}
//
//void pop()
//{
//	n--;
//}
//
//LL query()
//{
//	return stk[n];
//}
//
//int size()
//{
//	return n;
//}
//
//int main() 
//{
//	cin >> T;
//	while(T--)
//	{
//		n = 0; 
//		cin >> round;
//		while(round--)
//		{
//			cin >> op;
//			if(op == "push")				
//			{
//				cin >> x;
//				push(x);
//			}
//			else if(op == "pop")
//			{
//				if(size())
//				{
//					pop();
//				}
//				else
//				{
//					cout << "Empty" << endl;
//				}
//			}
//			else if(op == "query")
//			{
//				if(size())
//				{
//					cout << query() << endl;
//				}
//				else
//				{
//					cout << "Anguei!" << endl;
//				}
//			}
//			else if(op == "size")
//			{
//				cout << size() << endl;
//			}
//		}	
//	}
//	
//	return 0;
//}

//
//#include <iostream>
//#include <string>
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//typedef unsigned long long LL;
//LL stk[N];
//int T,round;
//LL x;
//string op;
//
//int main() 
//{
//	cin >> T;
//	while(T--)
//	{
//		n = 0; 
//		cin >> round;
//		while(round--)
//		{
//			cin >> op;
//			if(op == "push")				
//			{
//				cin >> x;
//				stk[++n] = x;
//			}
//			else if(op == "pop")
//			{
//				if(n)
//				{
//					n--;
//				}
//				else
//				{
//					cout << "Empty" << endl;
//				}
//			}
//			else if(op == "query")
//			{
//				if(n)
//				{
//					cout << stk[n] << endl;
//				}
//				else
//				{
//					cout << "Anguei!" << endl;
//				}
//			}
//			else if(op == "size")
//			{
//				cout << n << endl;
//			}
//		}	
//	}
//	
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//typedef unsigned long long LL;
//LL stk[N];
//
//
//int main() 
//{
//	int T; 
//	cin >> T;
//	while(T--)
//	{
//		n = 0; 
//		int round;
//		cin >> round;
//		while(round--)
//		{
//			string op;
//			cin >> op;
//			if(op == "push")				
//			{
//				LL x;
//				cin >> x;
//				stk[++n] = x;
//			}
//			else if(op == "pop")
//			{
//				if(n)
//				{
//					n--;
//				}
//				else
//				{
//					cout << "Empty" << endl;
//				}
//			}
//			else if(op == "query")
//			{
//				if(n)
//				{
//					cout << stk[n] << endl;
//				}
//				else
//				{
//					cout << "Anguei!" << endl;
//				}
//			}
//			else if(op == "size")
//			{
//				cout << n << endl;
//			}
//		}	
//	}
//	
//	return 0;
//}
//"Anguei!"打成了"Aanguei!" 浪费我半天时间 我草。。。

//有效的括号 
//class Solution {
//public:
//    bool isValid(string s) //我一直在想题目给的string，我怎么将string中的每个元素拆分出来，我忘记了string也是一种容器，可以直接范围for，可以下标索引，可以迭代器 
//	{
//        
//    }
//};

//P4387
//#include<iostream>
//#include<stack>
//using namespace std;
//
//int main()
//{
//	stack<int> st;
//	int q;
//	cin >> q;
//	while(q--)
//	{
//		int flag = 1;
//		int n;
//		cin >> n;
//		while(n--)
//		{
//			int x;
//			cin >> x; //能这么写吗，没长脑子吗，cin的结束标志是什么？回车！！ 
//			st.push(x);
//		}
//		while(n--)
//		{
//			int y;
//			cin >> y;
//			if(y == st.top()) st.pop();
//			else flag = 0;
//		}
//		if(flag) cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	
//	return 0;
//}

//P4387 
//#include<iostream>
//#include<stack>
//using namespace std;
//
//const int N = 1e5 + 10; 
//int in[N],out[N];
//
//int main()
//{	
//	int q;
//	cin >> q;
//	while(q--)
//	{
//		stack<int> st; //栈必须放在循环内，要不然每次重新接受数据前要清空栈元素 
//		int n;
//		cin >> n;
//		for(int i=1;i<=n;i++) cin >> in[i];	
//		for(int i=1;i<=n;i++) cin >> out[i];
//		int t = 1; //t指针指向out的第一个元素 
//		for(int i=1;i<=n;i++)
//		{
//			st.push(in[i]);
//			while(t <= n && st.top() == out[t] && st.size()) //极其重要！！！ st.size()的检查一定要放在 st.top() == out[t]的前面，因为栈为空的时候不能调用top接口！！，像左边这样写是错误的。报错runtime error 
//			//t <= n不能丢，要不然两个序列完全匹配的时候t就会加到n+1，那样就死循环了 
//			{
//				st.pop(); 
//				t++;
//			}
//		}
//		if(st.size()) cout << "No" << endl;
//		else cout << "Yes" << endl;
//	}
//	
//	return 0;
//}

//P1449
//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//
//stack<int> st1;
//stack<char> st2;
//
//string s;
//
//int f(int a,int b,string op)
//{
//	if(op == "+") return a+b;
//	else if(op == "-") return a-b;
//	else if(op == "*") return a*b;
//	else return a/b;
//}
//
//int main()
//{
//	cin >> s;
//	string tmp;
//	int tmp_index = 0;
//	for(int i=0;s[i]!='@';i++)
//	{
//		if(s[i]>'0'&&s[i]<'9')	//不能写'0'<ch<'9',这种是python风格的判断语句，在C++中会按照 左结合 规则解析该表达式，即(1 < a) < 5 
//		{
//			tmp_index = 0;
//			for(int j=i;j!='.';j++)
//			{
//				tmp[tmp_index++] = s[j];
//			}
//			int num = stoi(tmp);
//			st1.push(num);
//		}
//		else
//		{
//			if(s[i] = '.') continue;
//			else st2.push(s[i]);
//		}
//	}
//	
//	int b = st1.top(); //b只取一次，剩下的全是上一步的计算结果当b 
//	st1.pop();
//	while(st1.size() && st2.size())
//	{		
//		int a = st1.top();
//		st1.pop();
//		string op = st2.top();
//		st2.pop();
//		b = f(a,b,op);	
//	}
//	return 0;
//}

//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//
//stack<int> st1;
//
//string s;
//
//int b;
//int f(int a,int b,string op)
//{
//	if(op == "+") return a+b;
//	else if(op == "-") return a-b;
//	else if(op == "*") return a*b;
//	else return a/b;
//}
//
//int main()
//{
//	cin >> s;
//	string tmp;
//	int tmp_index = 0;
//	int flag = 1;
//	for(int i=0;s[i]!='@';i++)
//	{
//		if(s[i]>'0'&&s[i]<'9')	//不能写'0'<ch<'9',这种是python风格的判断语句，在C++中会按照 左结合 规则解析该表达式，即(1 < a) < 5 
//		{
//			tmp_index = 0;
//			for(int j=i;j!='.';j++)
//			{
//				tmp[tmp_index++] = s[j];
//			}
//			int num = stoi(tmp);
//			st1.push(num);
//		}
//		else
//		{
//			if(s[i] = '.') continue;
//			else
//			{
//				string op(1,s[i]);
//				if(flag)
//				{
//					b = st1.top(); //b只取一次，剩下的全是上一步的计算结果当b 
//					st1.pop();
//					flag = 0;
//				}
//				if(st1.size())
//				{		
//					int a = st1.top();
//					st1.pop();					
//					b = f(a,b,op);	
//				}
//			}
//		}
//	}
//	
//	
//	return 0;
//}

//#include<iostream>
//#include<stack>
//
//using namespace std;
//stack<int> st;
//int main()
//{
//	char ch;
//	int num = 0;
//	while(cin >> ch)
//	{
//		if(ch == '@') break;
//		else if(ch >= '0' && ch <= '9')
//		{
//			num = num*10 + ch -'0';
//		}
//		else if(ch == '.')
//		{
//			st.push(num);
//			num = 0;
//		}
//		else
//		{
//			int b = st.top(); st.pop();
//			int a = st.top(); st.pop();
//			if(ch == '+') st.push(a+b);
//			else if(ch =='-') st.push(a-b);
//			else if(ch == '*') st.push(a*b);
//			else st.push(a/b); 
//		}
//	}
//	cout << st.top() << endl;
//	return 0;
// } 

//P1241 
//1.遍历整个字符串，左括号入栈，遇到右括号的时候，看top能不能匹配，能就标记两个位置True，不能就不管，本身就全部初始化为False
//2.补全所有位置为False的括号 
#include<iostream>
#include<stack>

using namespace std;
const int N = 110;
bool st[N];
int main()
{
	string s;
	cin >> s;
	stack<int> stk;
	for(int i=0;i<s.size();i++)
	{
		char ch = s[i];
		if(ch == '(' || ch == '[') stk.push(i);
		else
		{
			if(stk.empty()) continue;
			int j = stk.top(); //调用top()前一定要确保栈不为空 
			char left = s[j];
			if( (ch == ')' && left == '(') || (ch == ']' && left == '[') )
			{
				st[i] = true;
				st[j] = true;
				stk.pop(); 
			}
		}
	}
	
	string res = "";
	for(int i=0;i<s.size();i++)
	{
		char ch = s[i];
		if(!st[i])
		{
			if( ch == '('|| ch == ')') res+="()";
			else if(ch == '['|| ch == ']') res+="[]";
		}
		else
		{
			res+=ch;
		}
	}
	cout << res << endl;
	return 0;
 } 

