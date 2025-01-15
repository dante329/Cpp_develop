//1.14结构体 
//#include <iostream>
//#include <string>
//#define class_num 2;
//using namespace std;
//
//struct Score
//{
//	int chinese;
//	int math;	
//};
//
//struct Stu
//{
//	string name;
//	Score sc;
//	int total;
//	int avg;
//	void Info_print()
//	{
//		cout << "name:" << name << endl; 
//		cout << "chinese:" << sc.chinese << endl; 
//		cout << "math:" << sc.math << endl; 
//		cout << "total:" << total << endl; 
//		cout << "avg:" << avg << endl;
//	}
//	//构造函数，无返回值，可重构
//	Stu()
//	{
//		cout << "使用构造函数Stu()" << endl;
//		name = "Admin";
//		sc.chinese = 100;
//		sc.math = 100;
//		total = 200;
//		avg = 100;
//	}
//	//析构函数，无返回值无参数，不能重构，用来释放资源 
//	~Stu()
//	{
//		cout << "使用析构函数~Stu()" << endl;
//		//一些释放资源的语句 
//	}
//	 
//	
//};//可以在分号之前创建几个结构体Stu的全局变量 
//
//int main() 
//{
////	//大括号显式初始化 
////	Stu stu1 = {"老表",95,100,0,0}; 
////	//计算得出total和avg
////	stu1.total = stu1.sc.chinese+stu1.sc.math;
////	stu1.avg = stu1.total/class_num; 
//	
////	//通过.访问成员变量的值，并且打印
////	cout << "name:" << stu1.name << endl; 
////	cout << "chinese:" << stu1.sc.chinese << endl; 
////	cout << "math:" << stu1.sc.math << endl; 
////	cout << "total:" << stu1.total << endl; 
////	cout << "avg:" << stu1.avg << endl; 
////	//也可以通过成员函数来打印这些信息，值得注意的是：成员函数中访问成员变量不想需要通过.来访问，是直接访问 
////	stu1.Info_print();
//
//	Stu stu1;
//	stu1.Info_print();
//	
////	{
////		Stu stu1;
////		stu1.Info_print();
////	}
//	
//	return 0;
//}

//1.15运算符重载 
#include <iostream>
#include <string>
using namespace std;

struct Stu
{
	string name;
	int chinese;
	int math;
	int total;
	int avg;
};

//如何直接使用cout << 打印结构体的信息，而不依赖 Info_print()这样的成员函数
//需要重载运算符<<  
ostream& operator<<(ostream& os,Stu& stu)
{
	os << "name:" << stu.name << endl; 
	os << "chinese:" << stu.chinese << endl; 
	os << "math:" << stu.math << endl; 
	os << "total:" << stu.total << endl; 
	os << "avg:" << stu.avg << endl;
	
	return os;
}

int main()
{
	char ch1 = 'a';
	cout << ch1 << endl;
	
	int num = 97;
	cout << num << endl;
	
	Stu stu1 = {"老表",100,100,200,100};
	cout << stu1 << endl;
	return 0;
}
