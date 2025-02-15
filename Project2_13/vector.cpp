#include <iostream>
#include <vector> 
using namespace std;

const int N = 10;

struct node
{
	int a,b,c;
	string str;	
};

//使用模板写一个打印一维数组的print函数 
template <typename T>
void print(vector<T>& vec)
{
	//用size作为边界 
//	for(int i=0;i<vec.size();++i)
//	{
//		cout << vec[i] << " ";
//	} 
//	cout << endl;
	//用范围for
	for (auto elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
    //语法糖范围for的本质会转换成迭代器遍历 
	//auto语法糖 代替了 迭代器类型 vector<int>::iterator 
//	for(auto it = vec.begin();it != vec.end();++it) 
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
}

//重构一个打印二维数组的函数
template <typename T>
void print(vector<vector<T>>& vec)
{
	for(auto row:vec)
	{
		print(row);// 直接调用一维 vector 版本 
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
	vector<int> a1; //创建了一个空的动态顺序表/变长数组a1
	vector<int> a2(N); //创建了一个大小为10的vector，数值默认初始化为0
	vector<int> a3(N,2); //创建了一个大小为10的vector，并且将数据全部初始化为2
	vector<int> a4 = {1,2,3,4,5}; //类似于数组的显式初始化
	vector<int> a5[N]; //创建了一个大小为10的数组，数组的每个元素都是vector，即创建N个vector 
	vector<string> a6; //创建了一个用来存放string的vector
	vector<node> a7; //创建了一个用来存放node的vector
	vector<vector<int>> a8; //创建了一个vector，它的每个元素都是一个vector<int>,可以当作储存int的二维数组来使用 
	
	test_size();
	return 0;
} 
