//#include<iostream>
//#include<list>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//struct node
//{
//    char sex;
//    int num,able;
//};
//
//struct output
//{
//    int num1,num2,value;
//    bool operator<(const output& other) const
//    {
//        return value > other.value;
//    }
//};
//
//list<node> ls;
//int n;
//vector<char> sex;
//vector<int> able;
//priority_queue<output> pq;
//
//int main()
//{
//    cin >> n;
//    sex.resize(n+10);
//    able.resize(n+10);
//    //���������д����ݵ�vector
//    for(int i=1;i<=n;i++) cin >> sex[i];
//    for(int i=1;i<=n;i++) cin >> able[i];
//
//    //vector�浽����
//    for(int i=1;i<=n;i++)    
//    {
//        ls.push_back({sex[i],i,able[i]});
//    }
//
//    int flag = 1; // flagһֱ���Ƶ�������û�����ڵ�BGΪֹ
//    while(flag)
//    {
//        flag = 0;
//        for(auto i=ls.begin();i!=prev(ls.end());)
//        {
//            auto next_i = next(i);
//            if((i->sex == 'B' && next_i->sex == 'G') || (i->sex == 'G' && next_i->sex == 'B'))
//            {
//                int a = abs(i->able - next_i->able);
//                pq.push({i->num,i->num+1,a});
//                i = ls.erase(i);
//                i = ls.erase(i);
//                flag = 1;
//            }
//            else
//            {
//                i++;
//            }
//        }
//    }
//    
//    cout << pq.size() << endl;
//    while(pq.size())
//    {
//        auto tmp = pq.top();
//        cout << tmp.num1 << " " << tmp.num2 << endl;
//        pq.pop();
//    }
//    return 0;
//}
//
//////////////////////////
//
//#include <iostream>
//#include <list>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//struct Node {
//    char sex;
//    int num, able;
//    Node* prev;
//    Node* next;
//};
//
//struct Output {
//    int num1, num2, value;
//    bool operator<(const Output& other) const {
//        return value > other.value;  // С����
//    }
//};
//
//list<Node> ls;
//vector<Node*> nodes;  // ���ڿ��ٷ��ʽڵ�
//priority_queue<Output> pq;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<char> sex(n + 1);
//    vector<int> able(n + 1);
//
//    // �����Ա������ֵ
//    for (int i = 1; i <= n; i++) cin >> sex[i];
//    for (int i = 1; i <= n; i++) cin >> able[i];
//
//    // ��ʼ������
//    for (int i = 1; i <= n; i++) {
//        ls.push_back({sex[i], i, able[i], nullptr, nullptr});
//    }
//
//    // ����ǰ��ָ��
//    for (auto it = ls.begin(); it != ls.end(); ++it) {
//        if (it != ls.begin()) it->prev = &(*prev(it));
//        if (next(it) != ls.end()) it->next = &(*next(it));
//        nodes.push_back(&(*it));
//    }
//
//    // ��ʼ�����ȶ���
//    for (int i = 0; i < n - 1; i++) {
//        if (nodes[i]->sex != nodes[i + 1]->sex) {
//            int a = abs(nodes[i]->able - nodes[i + 1]->able);
//            pq.push({nodes[i]->num, nodes[i + 1]->num, a});
//        }
//    }
//
//    vector<pair<int, int>> result;
//    while (!pq.empty()) {
//        auto tmp = pq.top();
//        pq.pop();
//
//        int num1 = tmp.num1, num2 = tmp.num2;
//        Node* node1 = nodes[num1 - 1];
//        Node* node2 = nodes[num2 - 1];
//
//        // ����Ƿ���Ȼ����
//        if (node1->next != node2 || node2->prev != node1) continue;
//
//        // ��¼���
//        result.push_back({min(num1, num2), max(num1, num2)});
//
//        // ɾ�� node1 �� node2
//        if (node1->prev) node1->prev->next = node2->next;
//        if (node2->next) node2->next->prev = node1->prev;
//
//        // ����µ����ڶ�
//        if (node1->prev && node2->next && node1->prev->sex != node2->next->sex) {
//            int a = abs(node1->prev->able - node2->next->able);
//            pq.push({node1->prev->num, node2->next->num, a});
//        }
//    }
//
//    // ������
//    cout << result.size() << endl;
//    for (auto& p : result) {
//        cout << p.first << " " << p.second << endl;
//    }
//
//    return 0;
//}

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
	int d;
	int l,r;
	
	bool operator<(const node& x) const
	{
		if(d != x.d) return d > x.d;
		else return l > x.l;
		
	}
};
 
priority_queue<node> pq;

const int N = 2e5 + 10;

bool st[N];

int e[N],pre[N],ne[N];
int s[N]; //��¼�Ա� 
int n;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) //���Ա� 
	{
		char ch; cin >> ch;
		if(ch == 'B') s[i] = 1; 
	}
	for(int i=1;i<=n;i++) //������ 
	{
		cin >> e[i];
		pre[i] = i-1;
		ne[i] = i+1;
	}
	pre[1] = ne[n] = 0;
	
	for(int i=2;i<=n;i++) //������ 
	{
		if(s[i] != s[i-1])
		{
			pq.push({abs(e[i]-e[i-1]),i-1,i});
		}
	}
	
	vector<node> ret;
	
	while(pq.size())
	{
		auto t = pq.top(); pq.pop();
		int d = t.d, l = t.l, r = t.r;
		if(st[l] || st[r]) continue;
		ret.push_back(t);
		st[l] = st[r] = true;
		
		ne[pre[l]] = ne[r];
		pre[ne[r]] = pre[l];
		
		int left = pre[l], right = ne[r];
		if(left && right && s[left] != s[right])
		{
			pq.push({abs(e[left] - e[right]),left,right}); 
		 } 
	}
	
	cout << ret.size() << endl;
	for(auto& i:ret)
	{
		cout << i.l << " " << i.r << endl;
	}
	
	return 0; 
}






