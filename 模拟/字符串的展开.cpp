//ʺɽ 
//#include<iostream>
//using namespace std;
//
//
//string str;
//int p1,p2,p3;
//
//void process(char ch1,char ch2)
//{
//	if((!isalpha(ch1) && isalpha(ch2)) || (isalpha(ch1) && !isalpha(ch2)))
//	{
//		cout << '-' ;
//		return; 
//	 } 
//	if(ch2 == ch1 + 1) return;
//	if(ch2 <= ch1) 
//	{
//		cout << '-';
//		return;
//	}
//	
//	if(p3 == 1)
//	{
//		if(p1 == 1)
//		{
//			for(char ch=ch1+1;ch<ch2;ch++)
//			{
//				for(int i=1;i<=p2;i++)
//				{
//					cout << char(tolower(ch));
//				}
//			} 
//		}
//		else if(p1 == 2)
//		{
//			for(char ch=ch1+1;ch<ch2;ch++)
//			{
//				for(int i=1;i<=p2;i++)
//				{
//					cout << char(toupper(ch));
//				}
//			 } 
//		}
//		else 
//		{
//			for(char ch=ch1+1;ch<ch2;ch++)
//			{
//				for(int i=1;i<=p2;i++)
//				{
//					cout << '*';
//				}
//			 } 
//		}
//	}
//	else
//	{
//		if(p1 == 1)
//		{
//			for(char ch=ch2-1;ch>ch1;ch--)
//			{
//				for(int i=1;i<=p2;i++)
//				{
//					cout << char(tolower(ch));
//				}
//			} 
//		}
//		else if(p1 == 2)
//		{
//			for(char ch=ch2-1;ch>ch1;ch--)
//			{
//				for(int i=1;i<=p2;i++)
//				{
//					cout << char(toupper(ch));
//				}
//			 } 
//		}
//		else 
//		{
//			for(char ch=ch2-1;ch>ch1;ch--)
//			{
//				for(int i=1;i<=p2;i++)
//				{
//					cout << '*';
//				}
//			 } 
//		}
//	}
//}
//
//int main()
//{
//	cin >> p1 >> p2 >> p3;
//	cin >> str;
//	for(int i = 0;i<str.length();i++)
//	{
//		if(str[i] == '-' && i == 0 || str[i] == '-' && i == str.length()-1)
//		{
//			cout << '-' 
//		}
//		else if(str[i] == '-')
//		{
//			process(str[i-1],str[i+1]);
//		}
//		else cout << str[i];
//	}
//	return 0;
//}

#include<iostream>
#include<algorithm>

using namespace std;

string str,ret; //str�����룬ret��� 
int p1,p2,p3; 

//�Ƿ�ΪСд�ַ� 
bool islet(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

//���������������ʱ���һ����Ҫչ������� 

//����д���ֳ�ʺɽ�� 
//void process(char ch1,char ch2) 
//{
//	if(p1 == 1) //��Сд 
//	{
//		for(char ch = ch1 + 1;ch < ch2;ch++)
//		{
//			char tmp = ch;
//			for(int i=1;i<=p2;i++)
//			{
//				ret += tmp;
//			}	
//		}	
//	}	
//	else if(p1 == 2)
//	{
//		for(char ch = ch1 + 1;ch < ch2;ch++)
//		{
//			char tmp = ch;
//			tmp = toupper(ch);
//			for(int i=1;i<=p2;i++)
//			{
//				ret += tmp;
//			}	
//		}
//	}
//	else
//	{
//		for(char ch = ch1 + 1;ch < ch2;ch++)
//		{
//			char tmp = ch;
//			tmp = '*';
//			for(int i=1;i<=p2;i++)
//			{
//				ret += tmp;
//			}	
//		}
//	}
//}

void process(char ch1,char ch2) 
{
	string t; //��ʱ�ַ�����Ŀ�ľ���Ϊ�˷������� 
	for(char ch = ch1 + 1;ch < ch2;ch++)
	{
		char tmp = ch;
		if(p1 == 2 && islet(tmp)) tmp -= 32;
		else if(p1 == 3) tmp = '*'; 
		
		for(int i=1;i<=p2;i++)
		{
			t += tmp;
		}	
	}	
	
//	if(p3 == 2) reverse(ret.begin(),ret.end()); //�㴦���ֻ��һ�����ַ�����������ΪʲôҪ���������ַ����� 
	if(p3 == 2) reverse(t.begin(),t.end());
	
	ret += t;
}

int main()
{
	//д�ÿ���ٲ��亯�� 
	cin >> p1 >> p2 >> p3 >> str;
	int n = str.size();
	for(int i=0;i<n;i++)
	{
		char tmp = str[i];
		if(tmp != '-' || i == 0 || i == n-1)  ret += tmp;
		else
		{
			char left = str[i-1],right = str[i+1];
			//�ж��Ƿ�����Ҫչ�� 
			if(islet(left) && islet(right) && right > left || //isalpha
				isdigit(left) && isdigit(right) && right > left)
				{
					process(left,right);
				 } 
			else ret += tmp;  
		}	
	} 
	cout << ret << endl;
	
	return 0;
 } 
