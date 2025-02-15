#include <iostream>
#include <vector> 
using namespace std;

const int N = 10;

struct node
{
	int a,b,c;
	string str;	
};

//ʹ��ģ��дһ����ӡһά�����print���� 
template <typename T>
void print(vector<T>& vec)
{
	//��size��Ϊ�߽� 
//	for(int i=0;i<vec.size();++i)
//	{
//		cout << vec[i] << " ";
//	} 
//	cout << endl;
	//�÷�Χfor
	for (auto elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
    //�﷨�Ƿ�Χfor�ı��ʻ�ת���ɵ��������� 
	//auto�﷨�� ������ ���������� vector<int>::iterator 
//	for(auto it = vec.begin();it != vec.end();++it) 
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
}

//�ع�һ����ӡ��ά����ĺ���
template <typename T>
void print(vector<vector<T>>& vec)
{
	for(auto row:vec)
	{
		print(row);// ֱ�ӵ���һά vector �汾 
	} 
	cout << endl;
} 

void test_size()
{
	vector<int> a1(6,8);
	cout << a1.size() << endl;
	print(a1);
	vector<vector<int>> a2(10,vector<int>(5,2));
	cout << a2.size() << endl;
	print(a2);
}

int main()
{
	vector<int> a1; //������һ���յĶ�̬˳���/�䳤����a1
	vector<int> a2(N); //������һ����СΪ10��vector����ֵĬ�ϳ�ʼ��Ϊ0
	vector<int> a3(N,2); //������һ����СΪ10��vector�����ҽ�����ȫ����ʼ��Ϊ2
	vector<int> a4 = {1,2,3,4,5}; //�������������ʽ��ʼ��
	vector<int> a5[N]; //������һ����СΪ10�����飬�����ÿ��Ԫ�ض���vector��������N��vector 
	vector<string> a6; //������һ���������string��vector
	vector<node> a7; //������һ���������node��vector
	vector<vector<int>> a8; //������һ��vector������ÿ��Ԫ�ض���һ��vector<int>,���Ե�������int�Ķ�ά������ʹ�� 
	
	test_size();
	return 0;
} 
