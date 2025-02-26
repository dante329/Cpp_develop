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
//int f(int a, int b, string op)
//{
//	if (op == "+") return a + b;
//	else if (op == "-") return a - b;
//	else if (op == "*") return a * b;
//	else return a / b;
//}
//
//int main()
//{
//	cin >> s;
//	string tmp;
//	int tmp_index = 0;
//	int flag = 1;
//	for (int i = 0; s[i] != '@'; i++)
//	{
//		if (s[i] > '0' && s[i] < '9')	//不能写'0'<ch<'9',这种是python风格的判断语句，在C++中会按照 左结合 规则解析该表达式，即(1 < a) < 5 
//		{
//			tmp_index = 0;
//			for (int j = i; j != '.'; j++)
//			{
//				tmp[tmp_index++] = s[j]; //习惯太差了，能写出这中代码，直接访问下标去添加内容是非常危险的，要用+=或者push_back，而且你这样写的不麻烦吗，还专门去搞一个int tmp_index = 0;记录位置，这些东西别人都已经搞好了
//			}
//			int num = stoi(tmp);
//			st1.push(num);
//		}
//		else
//		{
//			if (s[i] = '.') continue;
//			else
//			{
//				string op(1, s[i]);
//				if (flag)
//				{
//					b = st1.top(); //b只取一次，剩下的全是上一步的计算结果当b 
//					st1.pop();
//					flag = 0;
//				}
//				if (st1.size())
//				{
//					int a = st1.top();
//					st1.pop();
//					b = f(a, b, op);
//				}
//			}
//		}
//	}
//
//
//	return 0;
//}

#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<int> st1;

string s;

int a,b;
int f(int a, int b, string op)
{
	if (op == "+") return a + b;
	else if (op == "-") return a - b;
	else if (op == "*") return a * b;
	else return a / b;
}

int main()
{
	cin >> s;
	string tmp;
	int flag = 1;
	for (int i = 0; s[i] != '@'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')	//不能写'0'<ch<'9',这种是python风格的判断语句，在C++中会按照 左结合 规则解析该表达式，即(1 < a) < 5 
		{
			tmp = "";
			/*for (int j = i; s[j] != '.'; j++,i++)*/
			for ( ;s[i] != '.'; i++)
			{
				tmp.push_back(s[i]);
			}
			int num = stoi(tmp);
			st1.push(num);
		}
		else
		{
			if (s[i] == '.') continue;
			else
			{
				string op(1, s[i]); //string op = s[i];这样写是完全错误的，s[i]是一个char类型的数据，而string希望接收的是char*类型，即c语言风格的字符串，cpp中严格区分单双引号，''是字符， ""是字符串
				if (flag)
				{
					b = st1.top(); //a只取一次，剩下的全是上一步的计算结果当b 
					st1.pop();
					a = st1.top();
					st1.pop();
					a = f(a, b, op);
					flag = 0;
				}
				else
				{
					if ((st1.size()))
					{
						b = st1.top();
						a = f(a, b, op);
					}
				}
			}
		}
	}
	cout << a << endl;

	return 0;
}