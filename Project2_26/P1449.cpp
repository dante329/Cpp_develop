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
//		if (s[i] > '0' && s[i] < '9')	//����д'0'<ch<'9',������python�����ж���䣬��C++�лᰴ�� ���� ��������ñ��ʽ����(1 < a) < 5 
//		{
//			tmp_index = 0;
//			for (int j = i; j != '.'; j++)
//			{
//				tmp[tmp_index++] = s[j]; //ϰ��̫���ˣ���д�����д��룬ֱ�ӷ����±�ȥ��������Ƿǳ�Σ�յģ�Ҫ��+=����push_back������������д�Ĳ��鷳�𣬻�ר��ȥ��һ��int tmp_index = 0;��¼λ�ã���Щ�������˶��Ѿ������
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
//					b = st1.top(); //bֻȡһ�Σ�ʣ�µ�ȫ����һ���ļ�������b 
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
		if (s[i] >= '0' && s[i] <= '9')	//����д'0'<ch<'9',������python�����ж���䣬��C++�лᰴ�� ���� ��������ñ��ʽ����(1 < a) < 5 
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
				string op(1, s[i]); //string op = s[i];����д����ȫ����ģ�s[i]��һ��char���͵����ݣ���stringϣ�����յ���char*���ͣ���c���Է����ַ�����cpp���ϸ����ֵ�˫���ţ�''���ַ��� ""���ַ���
				if (flag)
				{
					b = st1.top(); //aֻȡһ�Σ�ʣ�µ�ȫ����һ���ļ�������b 
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