//#include <iostream>
//using namespace std;
//
//const int N = 1e5 + 10;
//
////class 的成员默认是 private，而 struct 的成员默认是 public
//class SqList
//{
//	int a[N]; //储存数据 
//	int n; //记录长度 
//public:
//	SqList()
//	{
//		n = 0;
//	}
//	//打印 
//	void Print()
//	{
//		for(int i=1;i<=n;++i) //下标为0的位置不储存数据 
//		{
//			cout << a[i] << " ";
//		}
//		cout << endl;
//	}
//	//头插
//	void Push_Front(int x)
//	{
//		for(int i=n;i>=1;--i) //从后往前每个元素向后挪一位 
//		{
//			a[n+1] = a[n];
//		}
//		a[1] = x;
//		n++;
//	} 
//	//尾插
//	void Push_Back(int x)
//	{
//		a[++n] = x;
//	} 
//	//头删
//	void Pop_Front()
//	{
//		for(int i=1;i<=n-1;i++)
//		{
//			a[i] = a[i+1];
//		}
//		n--;
//	 } 
//	//尾删
//	void Pop_Back()
//	{
//		n--;
//	 } 
//	//任意位置插入
//	void Insert(int p,int x)
//	{
//		for(int i=p;i<=x-1;++i)
//		{
//			a[i+1] = a[i];
//		}
//		a[p] = x;
//		++n;
//	}
//	//清空
//	void clear()
//	{
//		n = 0;
//	} 
//};
//
//int main()
//{
//	
//	SqList s1,s2;
//	for(int i=1;i<=5;++i)
//	{
//		s1.Push_Back(i);
//		s2.Push_Back(i * 2);
//	}
//	s1.Print();
//	s2.Print();
//	return 0;
//}

