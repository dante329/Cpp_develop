//1.14�ṹ�� 
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
//	//���캯�����޷���ֵ�����ع�
//	Stu()
//	{
//		cout << "ʹ�ù��캯��Stu()" << endl;
//		name = "Admin";
//		sc.chinese = 100;
//		sc.math = 100;
//		total = 200;
//		avg = 100;
//	}
//	//�����������޷���ֵ�޲����������ع��������ͷ���Դ 
//	~Stu()
//	{
//		cout << "ʹ����������~Stu()" << endl;
//		//һЩ�ͷ���Դ����� 
//	}
//	 
//	
//};//�����ڷֺ�֮ǰ���������ṹ��Stu��ȫ�ֱ��� 
//
//int main() 
//{
////	//��������ʽ��ʼ�� 
////	Stu stu1 = {"�ϱ�",95,100,0,0}; 
////	//����ó�total��avg
////	stu1.total = stu1.sc.chinese+stu1.sc.math;
////	stu1.avg = stu1.total/class_num; 
//	
////	//ͨ��.���ʳ�Ա������ֵ�����Ҵ�ӡ
////	cout << "name:" << stu1.name << endl; 
////	cout << "chinese:" << stu1.sc.chinese << endl; 
////	cout << "math:" << stu1.sc.math << endl; 
////	cout << "total:" << stu1.total << endl; 
////	cout << "avg:" << stu1.avg << endl; 
////	//Ҳ����ͨ����Ա��������ӡ��Щ��Ϣ��ֵ��ע����ǣ���Ա�����з��ʳ�Ա����������Ҫͨ��.�����ʣ���ֱ�ӷ��� 
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

//1.15��������� 
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

//���ֱ��ʹ��cout << ��ӡ�ṹ�����Ϣ���������� Info_print()�����ĳ�Ա����
//��Ҫ���������<<  
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
	
	Stu stu1 = {"�ϱ�",100,100,200,100};
	cout << stu1 << endl;
	return 0;
}
