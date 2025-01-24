//������������ʵ��
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;      
};

class List
{
//��Ա���� 
private:
	Node* phead;

//��Ա����	
	//�����½ڵ�ķ�������ϣ�����û�ֱ��ʹ�ã�����private 
	Node* CreatNode(int n)
	{
		Node* p = new Node;
		p->data = n;
		p->next = nullptr;
		return p; 
	}	
public:
	//���췽��
	List()
	{
		phead = nullptr;
	} 
	//�������� 
	//��ʹ�ڳ������ǰû�е���Destroy�ͷŵ���������нڵ㣬Ҳ��������ڴ�й©����Ϊ�����������Զ������ͷ��ڴ� 
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
			cout << "����Ϊ�գ��޷�ɾ���ڵ㣡" << endl;
			return; //����Ϊ�վͲ���ɾ�ڵ��ˣ�����Ҫ��ֹ������� 
		}
		else
		{
			Node* tmp = phead; //Ҫ��һ����ʱ������Ҫͷɾ������ڵ㱣��������Ҫ��Ȼ��ɾ�˾��Ҳ����ˣ������Ƚ�phead���¾��Ҳ���Ҫɾ�Ľڵ��� 
			phead = phead->next; 
			delete tmp;
			tmp = nullptr; //delete�ͷſռ���ٽ�ָ���ÿ� 
		}
	}
	
	void PopBack()  
	{
		if(phead == nullptr)
		{
			cout << "����Ϊ�գ��޷�ɾ���ڵ㣡" << endl;
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
