//面向对象的链表实现
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;      
};

class List
{
//成员变量 
private:
	Node* phead;

//成员方法	
	//创建新节点的方法，不希望被用户直接使用，所以private 
	Node* CreatNode(int n)
	{
		Node* p = new Node;
		p->data = n;
		p->next = nullptr;
		return p; 
	}	
public:
	//构造方法
	List()
	{
		phead = nullptr;
	} 
	//析构方法 
	//即使在程序结束前没有调用Destroy释放掉链表的所有节点，也不会造成内存泄漏，因为析构方法会自动帮你释放内存 
	~List()
	{
		while(phead != nullptr)
		{
			PopFront();
		}
	}
	
	void PrintNodes()
	{
		Node* cur = phead;
		while(cur != nullptr)
		{
			cout << cur->data << "--->" ;
			cur = cur->next;
		}
		cout << "NULL" << endl;
	}
	
	void PushFront(int n)
	{
		Node* pn = CreatNode(n);
		pn->next = phead;
		phead = pn;
	}
	
	void PushBack(int n)
	{
		Node* pn = CreatNode(n);
		if(phead == nullptr)
		{
			phead = pn;
		}
		else
		{
			Node* tail = phead;
			while(tail->next != nullptr)
			{
				tail = tail->next;
			}
			tail->next = pn;
		}
	}
	
	void PopFront()
	{
		if(phead == nullptr)
		{
			cout << "链表为空！无法删除节点！" << endl;
			return; //链表为空就不能删节点了，并且要中止这个函数 
		}
		else
		{
			Node* tmp = phead; //要用一个临时变量将要头删的这个节点保存下来，要不然先删了就找不到了，或者先将phead更新就找不到要删的节点了 
			phead = phead->next; 
			delete tmp;
			tmp = nullptr; //delete释放空间后再将指针置空 
		}
	}
	
	void PopBack()  
	{
		if(phead == nullptr)
		{
			cout << "链表为空！无法删除节点！" << endl;
			return; 
		}
		else if(phead->next == nullptr)
		{
			delete phead;
			phead = nullptr;
		}
		else
		{
			Node* tail = phead;
			while(tail->next->next != nullptr)
			{
				tail = tail->next;
			}
			delete tail->next;
			tail->next = nullptr;
		}
		
	}	
	void Destroy()
	{
		while(phead != nullptr)
		{
			PopFront();
		}
	}
};

int main() 
{
	List list;
	list.PushBack(1); 
	list.PushBack(2); 
	list.PushBack(3); 
	list.PushBack(4); 
	list.PushBack(5); 
	list.PrintNodes();
	return 0;
}
