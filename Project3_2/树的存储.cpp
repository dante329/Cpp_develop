//vector���� ʵ�ֺ��ӱ�ʾ�� ���޸���/��δ֪�� 
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 1e5 + 10;
//vector<int> edges[N];
//int n;
//
//int main() 
//{
//	cin >> n; //����n���ڵ� 
//	for(int i=1;i<n;i++) //����n-1���� 
//	{
//		//a��b֮����һ���� 
//		int a,b; cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);
//	}
//	return 0;
//}

//��ʽǰ���� ʵ�ֺ��ӱ�ʾ��
//ԭ�򣺵�x��һ������y��ʱ�򣬽�yͷ�嵽x�������� 
//#include <iostream>
//using namespace std;
//
//const int N = 1e5 + 10;
//int h[N],e[N*2],ne[N*2],id; //h�����еĵ�iλ�����䵱��iΪ�׵�����ĵ�ͷ�ڵ� ��e����������ݣ�ne������ź�����Ϣ���൱���Ǻܶ������洢����ͬһ�������� 
//
//int n;
//
//void push_front(int x,int y)
//{
//	id++;
//	e[id] = y;
//	ne[id] = h[x];
//	h[x] = id; 
//}
//
//int main() 
//{
//	cin >> n; //����n���ڵ� 
//	for(int i=1;i<n;i++)
//	{
//		int a,b; cin >> a >> b; //��Ŀ����һ��a��b��������a��b֮����һ���ߣ����ǲ�֪��˭��˭�ĸ��׽ڵ㣬�����ֿ��ܣ�a��b�ĸ��ڵ㣬b��a�ĸ��ڵ㣬���Զ�Ҫ�ֱ���ӵ������Լ���������
//		push_front(a,b);
//		push_front(b,a);
//	}
//	return 0;
//} 




