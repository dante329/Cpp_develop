#include<iostream>
#include<map>
#include<string>

using namespace std;

void print(map<string,int>& mp)
{
	for(auto& x:mp)
	{
		cout << "����:" << x.first << " " << "ֵ��" << x.second << endl; 
	}
}

void print(map<char,int>& mp)
{
		for(auto& x:mp)
	{
		cout << "�ַ�:" << x.first << " " << "������" << x.second << endl; 
	}
}

void test_cnt()
{
	string s; getline(cin,s);
	map<char,int> mp;
	for(char x:s)
	{
		mp[x]++;
	}
	print(mp);
}

//int main()
//{
//	map<string,int> mp; //k-v
//	
//	mp.insert({"�����",1});
//	mp.insert({"�����",2});
//	mp.insert({"�ϵ�",3});
//	
//	print(mp); //��ӡmap 
//	
//	//���� [] ��ʹ�� map��������������ʹ�á�
//	cout << mp["�ϵ�"] << endl;
//	mp["�ϵ�"] = 100;
//	cout << mp["�ϵ�"] << endl;
//	
//	cout << "��ѯ��ëǰ��map��" << endl << endl;
//	print(mp);
//	
//	//��������[]��ѯһ��map��û�е�keyʱ�����Ȳ���map��Ȼ���ٲ�ѯ
//	//��������ݣ�key��������������ݣ�value����Ĭ��ֵ 
//	cout << "��ë��ֵ��" ;  
//	cout << mp["��ë"] << endl << endl;
//	 
//	cout << "��ѯ��ë���map��" << endl;
//	print(mp);
//	
//	mp.erase("��ë"); //ɾ��ֻ�ô���keyֵ
//	 
//	//Ϊ�˷�ֹ������������������������������ŵ�ʱ�����ж���û�����Ԫ��
//	if(mp.count("��ë")) cout << mp["��ë"] << endl;
//	else cout << "no" << endl;
//	
//	if(mp.count("�����") && mp["�����"] == 1) cout << "yes" << endl;
//	else cout << "no" << endl;
//	return 0;
//}

int main()
{
	test_cnt();
	return 0;
 } 
