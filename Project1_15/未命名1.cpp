////1.sortĬ������ (ֻ�ô�����������Ĭ��������)
//#include <iostream>
//#include <algorithm> //ʹ��sort��Ҫͷ�ļ� algorithm
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


////2.�Զ���sort(��������������������Ǻ������߷º���)
////2.1.�������� 
//#include <iostream>
//#include <algorithm> 
//using namespace std;
//
//bool Cmp(int x,int y)
//{
//	return x > y; //�������true ������һ��Ԫ�����ڵڶ���Ԫ��ǰ�� 
//}
////���� x=2 y=5 ��x > yΪtrue�������Ž��� 
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

////2.2.�º��� 
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
//}cmp; //����һ��ȫ�ֵ�Cmp�ṹ����� ���Ȼ�ֱ���� 
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

//3.����Žṹ�壨�ڽṹ����ѡ��һ����׼����(����ֻ��ʾ����������)�� 
//#include <iostream>
//#include <algorithm> 
//#include <string>
//using namespace std;
//
////����һ���ṹ������������
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
        int hours;      // Сʱ
        int minutes;    // ����

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
