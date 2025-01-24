//面向过程的链表实现 
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
		cout << "链表为空！无法删除节点！" << endl;
		return; //链表为空就不能删节点了，并且要中止这个函数 
	}
	else
	{
		Node* tmp = ph; //要用一个临时变量将要头删的这个节点保存下来，要不然先删了就找不到了，或者先将phead更新就找不到要删的节点了 
		ph = ph->next; 
		delete tmp;
		tmp = nullptr; //delete释放空间后再将指针置空 
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

//尾删应该考虑三种情况：无节点，只有一个节点，多个节点
//我们需要找到倒数第二个节点，因为我们需要释放掉最后一个节点，并且将倒数第二个节点的next设置为NULL 条件就是tail->next->next != NULL 
void PopBack(Node* &ph)  
{
	if(ph == nullptr)
	{
		cout << "链表为空！无法删除节点！" << endl;
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
