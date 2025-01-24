//������̵�����ʵ�� 
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;      
};

Node* CreatNode(int n)
{
	Node* p = new Node;
	p->data = n;
	p->next = nullptr;
	return p; 
}

void PrintNodes(Node* &ph)
{
	Node* cur = ph;
	while(cur != nullptr)
	{
		cout << cur->data << "--->" ;
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

void PushFront(Node* &ph,int n)
{
	Node* pn = CreatNode(n);
	pn->next = ph;
	ph = pn;
}

void PushBack(Node* &ph,int n)
{
	Node* pn = CreatNode(n);
	if(ph == nullptr)
	{
		ph = pn;
	}
	else
	{
		Node* tail = ph;
		while(tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = pn;
	}
}

void PopFront(Node* &ph)
{
	if(ph == nullptr)
	{
		cout << "����Ϊ�գ��޷�ɾ���ڵ㣡" << endl;
		return; //����Ϊ�վͲ���ɾ�ڵ��ˣ�����Ҫ��ֹ������� 
	}
	else
	{
		Node* tmp = ph; //Ҫ��һ����ʱ������Ҫͷɾ������ڵ㱣��������Ҫ��Ȼ��ɾ�˾��Ҳ����ˣ������Ƚ�phead���¾��Ҳ���Ҫɾ�Ľڵ��� 
		ph = ph->next; 
		delete tmp;
		tmp = nullptr; //delete�ͷſռ���ٽ�ָ���ÿ� 
	}
}

//void PopBack(Node* &ph)
//{
//	Node* tail = ph;
//	while(tail->next != nullptr)
//	{
//		tail = tail->next;
//	}
//	delete tail->next;
//	tail->next = nullptr;
//}

//βɾӦ�ÿ�������������޽ڵ㣬ֻ��һ���ڵ㣬����ڵ�
//������Ҫ�ҵ������ڶ����ڵ㣬��Ϊ������Ҫ�ͷŵ����һ���ڵ㣬���ҽ������ڶ����ڵ��next����ΪNULL ��������tail->next->next != NULL 
void PopBack(Node* &ph)  
{
	if(ph == nullptr)
	{
		cout << "����Ϊ�գ��޷�ɾ���ڵ㣡" << endl;
		return; 
	}
	else if(ph->next == nullptr)
	{
		delete ph;
		ph = nullptr;
	}
	else
	{
		Node* tail = ph;
		while(tail->next->next != nullptr)
		{
			tail = tail->next;
		}
		delete tail->next;
		tail->next = nullptr;
	}
	
}

void Destroy(Node* &ph)
{
	while(ph != nullptr)
	{
		PopFront(ph);
	}
}

int main() 
{
	Node* phead = nullptr;
	PushFront(phead,1);
	PushFront(phead,2);
	PushFront(phead,3);
	PushFront(phead,4);	
	PrintNodes(phead); //4 3 2 1
	PushBack(phead,1);
	PushBack(phead,2);
	PushBack(phead,3);
	PushBack(phead,4);
	PrintNodes(phead); //4 3 2 1 1 2 3 4 
	PopFront(phead);
	PopBack(phead);
	PrintNodes(phead); //3 2 1 1 2 3
	Destroy(phead);
	return 0;
}
