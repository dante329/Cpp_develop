//#include <iostream>
//using namespace std;
//
//const int N = 1e5 + 10;
//
////class �ĳ�ԱĬ���� private���� struct �ĳ�ԱĬ���� public
//class SqList
//{
//	int a[N]; //�������� 
//	int n; //��¼���� 
//public:
//	SqList()
//	{
//		n = 0;
//	}
//	//��ӡ 
//	void Print()
//	{
//		for(int i=1;i<=n;++i) //�±�Ϊ0��λ�ò��������� 
//		{
//			cout << a[i] << " ";
//		}
//		cout << endl;
//	}
//	//ͷ��
//	void Push_Front(int x)
//	{
//		for(int i=n;i>=1;--i) //�Ӻ���ǰÿ��Ԫ�����Ųһλ 
//		{
//			a[n+1] = a[n];
//		}
//		a[1] = x;
//		n++;
//	} 
//	//β��
//	void Push_Back(int x)
//	{
//		a[++n] = x;
//	} 
//	//ͷɾ
//	void Pop_Front()
//	{
//		for(int i=1;i<=n-1;i++)
//		{
//			a[i] = a[i+1];
//		}
//		n--;
//	 } 
//	//βɾ
//	void Pop_Back()
//	{
//		n--;
//	 } 
//	//����λ�ò���
//	void Insert(int p,int x)
//	{
//		for(int i=p;i<=x-1;++i)
//		{
//			a[i+1] = a[i];
//		}
//		a[p] = x;
//		++n;
//	}
//	//���
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

