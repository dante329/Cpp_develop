//P3378
//#include <iostream>
//using namespace std;
//
//const int N = 1e6 + 10;
////��ȫ�������洢
//int heap[N];
////n��ڵ�����
//int n; 
//
//void up(int child)
//{
//	int parent = child / 2;
//	while(parent >=1 && heap[child] < heap[parent])
//	{
//		swap(heap[child],heap[parent]);
//		child = parent;
//		parent = child / 2; 
//	}
//}
//
//void down(int parent)
//{
//	int child = parent * 2;
//	while(child <= n)
//	{
//		if(child + 1 <=n && heap[child+1] < heap[child]) child++;
//		if(heap[parent] <= heap[child]) return;
//		swap(heap[parent],heap[child]);
//		parent = child;
//		child = parent * 2;
//	}
//}
//
//void push(int x)
//{
//	heap[++n] = x;
//	up(n); 
//}
//
//void pop()
//{
//	swap(heap[1],heap[n]);
//	n--;
//	down(1); 
//}
//
//int top()
//{
//	return heap[1];
//}
//
//int size()
//{
//	return n;
//}
//int main() 
//{
//	int r; cin >> r;
//	while(r--)
//	{
//		int op; cin >> op;
//		switch(op)
//		{
//			case 1:
//				int x; cin >> x;
//				push(x);
//				break;
//			case 2:
//				if(size()) cout << top() << endl;
//				break;
//			case 3:
//				pop();
//				break; 
//		}
//	}
//	return 0;
//}


//��kС 
//#include<iostream>
//#include<queue>
//using namespace std;
//int n,m,k;
//
//priority_queue<int> pq;
//
//int main()
//{
//    cin >> n >> m >> k; 
//    for(int i=0;i<n;i++)
//    {
//        int x; cin >> x;
//        pq.push(x);
//        if(pq.size() > k) pq.pop();
//    }
//    while(m--)
//    {
//        int op; cin >> op;
//        if(op == 1)
//        {
//            int x; cin >> x;
//            pq.push(x);
//            if(pq.size() > k) pq.pop();
//        }
//        if(op == 2)
//        {
//            if(pq.size() == k) cout << pq.top() << endl;
//            else cout << -1 << endl;
//        }
//    }
//    return 0;
//}

//��2��
//#include<iostream>
//#include<queue>
//
//using namespace std;
//priority_queue<int> pq;
//int n,k;
//
//int main()
//{
//	long long sum = 0;
//    cin >> n >> k;
//    while(n--)
//    {
//        int a; cin >> a;
//        if(a%2 == 0) pq.push(a);
//		else sum += a; 
//    }
//    while(pq.size() && k--)
//    {                               
//        int t = pq.top()/2;
//        pq.pop();
//        if(t%2 == 0) pq.push(t/2);
//        else sum += t/2;
//    }
//    
//    while(!pq.empty())
//    {
//        sum += pq.top();
//    }
//    cout << sum << endl;
//    return 0;
//}

//AC
//#include<iostream>
//#include<queue>
//
//using namespace std;
//priority_queue<int> pq;
//int n,k;
//
//int main()
//{
//	long long sum = 0;
//    cin >> n >> k;
//    while(n--)
//    {
//        int a; cin >> a;
//        if(a%2 == 0) pq.push(a);
//		sum += a; 
//    }
//    while(pq.size() && k--)
//    {                               
//        int t = pq.top()/2;
//        pq.pop();
//        if(t%2 == 0) pq.push(t);
//        sum -= t;
//    }
//    cout << sum << endl;
//    return 0;
//} 

//P2085
//#include<iostream>
//#include<queue>
//using namespace std;
//
//priority_queue<int,vector<int>,greater<int>> pq; 
//
////int fun(int A,int B,int C)
////{
//////	int axis = -(B/(2*A)); axisһ��С��0��fun����Ȼ��������� 
////	for(int i=1;i<=10^4;i++) //��������д 10^4  Ӧ���� pow(10, 4) ��ʾ 10 �� 4 ����
////	{
////		int ret = A*i*i + B*i + C;
////		pq.push(ret);
////	} 
////}
//
//int main()
//{
//	int n,m;
//	cin >> n >> m;
//	while(n--)
//	{
//		int A,B,C; cin >> A >> B >> C;
////		fun(A,B,C);
//		for(int i=1;i<=10000;i++)
//		{
//			int ret = A*i*i + B*i + C;
//			pq.push(ret);
//		} 
//	}
//	while(m--)
//	{
//		if(pq.size())
//		{
//			cout << pq.top() << " ";
//			pq.pop();
//		} 
//	} 
//	return 0;
//}

//#include<iostream>
//#include<queue>
//using namespace std;
//
////�����������������������������Ժ�������Ȼ�������ϵ������� 
////����Ҫ��ǰm����С�ĺ���ֵ����x=1��ʼ����ֵ����
//
//struct node
//{
//	int fun; //���������ֵ 
//	int num; //�����ı�� 
//	int x;   //��ǰ��xֵ����1��ʼ 
//	
//	bool operator<(const node& other) const
//	{
//		return this->fun > other.fun;
//	}
//};
//
//priority_queue<node> pq;
//
//const int N = 1e4 + 10;
// 
//int a[N],b[N],c[N]; //�洢����������ŵĶ�Ӧ��A B C�������� 
// 
//int calc(int i,int x)
//{
//	return a[i]*x*x + b[i]*x + c[i];
//}
//
//int main()
//{
//	int n,m;
//	cin >> n >> m;
//	for(int i=1;i<=n;i++)
//	{
//		cin >> a[i] >> b[i] >> c[i];
//	}
//	for(int i=1;i<=n;i++) //�Ȱ�x=1��ʱ��n��������ֵ��ӵ�pq�У������ó���һ������� 
//	{
//		pq.push({calc(i,1),i,1});
//	}
//	while(m-- && pq.size())
//	{
//		auto tmp = pq.top();
//		cout << tmp.fun << " ";
//		int num = tmp.num; int x = tmp.x + 1;
//		pq.pop();
//		pq.push({calc(num,x),num,x});
//	}
//	return 0;
//}

//P1631 ���кϲ�
//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//struct node{
//	int ai,bi;
//	int value;
//	
//	bool operator<(const node& other) const
//	{
//		return value > other.value;
//	}
//};
//
//priority_queue<node> pq;
//
//int N;
//
////int A[N],B[N];
//
////Ҳ������vector 
////vector<int> A,B;
////
////int main()
////{
////	cin >> N;
////	A.resize(N+1);
////    B.resize(N+1);
////}
//
//int main()
//{
//	cin >> N;
//	int A[N],B[N];
//	//�����������ȸ���A���������У��ٸ���B���������У����۾�Ϲ�˸�һ��cin�� 
////	for(int i=1;i<=N;i++) 
////	{
////		cin >> A[i] >> B[N];
////	}
//	for(int i=1;i<=N;i++) //�����ݵ����� 
//	{
//		cin >> A[i];
//	}
//	for(int i=1;i<=N;i++) //�����ݵ����� 
//	{
//		cin >> B[i];
//	}
//	
//	//A�ĵ�һ��Ԫ�طֱ���B�ĸ���Ԫ����ˣ��浽pq 
//	for(int i=1;i<=N;i++)
//	{
//		int res = A[1] + B[i];
//		pq.push({1,i,res});
//	}
//	//�ó�ǰN��С��Ԫ�� 
//	while(N-- && pq.size())
//	{
//		auto tmp = pq.top(); pq.pop();
//		cout << tmp.value << " ";
//		//int ai = tmp.ai + 1, bi = tmp.bi;
//		int ai = tmp.ai, bi = tmp.bi;
//		if(ai+1 <= N) pq.push({ai+1,bi,A[ai] + B[bi]});	//�ж�һ�·�ֹ����Խ�� 
//	}
//	
//	return 0;
//}












