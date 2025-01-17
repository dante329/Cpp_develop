////1.sort默认排序 (只用传两个参数，默认排升序)
//#include <iostream>
//#include <algorithm> //使用sort需要头文件 algorithm
//using namespace std;
//
//int main()
//{
//	int arr[] = {4,5,2,8,7,0,9,1,3,6};
//	int sz = sizeof(arr)/sizeof(int);
//	sort(arr,arr+sz);
//	for(int i:arr)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	return 0;
//}


////2.自定义sort(传入第三个参数，可以是函数或者仿函数)
////2.1.传函数名 
//#include <iostream>
//#include <algorithm> 
//using namespace std;
//
//bool Cmp(int x,int y)
//{
//	return x > y; //如果返回true ，将第一个元素排在第二个元素前面 
//}
////传入 x=2 y=5 ，x > y为true，则是排降序 
//
//int main()
//{
//	int arr[] = {4,5,2,8,7,0,9,1,3,6};
//	int sz = sizeof(arr)/sizeof(int);
//	sort(arr,arr+sz,Cmp);
//	for(int i:arr)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	return 0;
//}

////2.2.仿函数 
//#include <iostream>
//#include <algorithm> 
//using namespace std;
//
//struct Cmp
//{
//	bool operator()(int x,int y)
//	{
//		return x > y;
//	}	
//}cmp; //创建一个全局的Cmp结构体变量 ，等会直接用 
//
//int main()
//{
//	int arr[] = {4,5,2,8,7,0,9,1,3,6};
//	int sz = sizeof(arr)/sizeof(int);
//	sort(arr,arr+sz,cmp);
//	for(int i:arr)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	return 0;
//}

//3.如何排结构体（在结构体中选择一个标准来排(这里只演示传函数排序)） 
//#include <iostream>
//#include <algorithm> 
//#include <string>
//using namespace std;
//
////定义一个结构体来对他排序
//struct Stu 
//{
//	string name;
//	int age;	
//};
//
//bool Cmp_by_age(Stu stu1,Stu stu2)
//{
//	return stu1.age > stu2.age;
//} 
//
//int main()
//{
//	Stu arr[] = {{"dante",20},{"haoge",19},{"morbee",13}};
//	int sz = sizeof(arr)/sizeof(Stu);
//	sort(arr,arr+sz,Cmp_by_age);
//	for(Stu i:arr)
//	{
//		cout << i.name << ":" << i.age << " ";
//	}
//	cout << endl;
//	return 0;
//}

#include <iostream>
using namespace std;

class Time {

    public:
        int hours;      // 小时
        int minutes;    // 分钟

        Time() {
            hours = 0;
            minutes = 0;
        }

        Time(int h, int m) {
            this->hours = h;
            this->minutes = m;
        }

        void show() {
            cout << hours << " " << minutes << endl;
        }

        // write your code here.....
        bool operator<(Time t)
        {
            if(hours<t.hours)   
                return true;
            else if(hours==t.hours && minutes < t.minutes)
                return true;
            else
                return false;
        }
};

int main() 
{
    int h, m;
    cin >> h;
    cin >> m;

    Time t1(h, m);
    Time t2(6, 6);
	
    if (t1<t2) 
		cout<<"yes"; 
	else 
		cout<<"no";
    return 0;
} 
