#include <iostream>
using namespace std;


class Node{
	public:
		int data;
		Node *next;
};


class LinkList{
	Node *head,*tail;
	public:
		LinkList(){
			head=tail=NULL;
		}
		void addNode(int d)
		{
			Node *ptr=new Node;
			Node *newnode=new Node;
			newnode->data=d;
			newnode->next=NULL;
			if (head==NULL && tail==NULL)
			{
				head=newnode;
				tail=newnode;
			}else{
				tail->next=newnode;
				tail=newnode;
			}
			
		}
		
		Node* getHead()
		{
			return head;
		}
		
		Node* getTail()
		{
			return tail;
		}
		
		void display()
		{
			Node *ptr=new Node;
			ptr=head;
			while(ptr!=NULL)
			{
				cout<<ptr->data<<"->";
				ptr=ptr->next;
			}
			cout<<"NULL";
		}
		
	LinkList* Modify_LinkList(LinkList *L)
	{
		LinkList L1;
		Node *ptr=L->getHead();
		while(ptr!=NULL)
		{
			if (ptr->data%2==0)
			{
				L1.addNode(ptr->data);
			}
			ptr=ptr->next;
		}
		
		ptr=L->getHead();

		while(ptr!=NULL)
		{
			if (ptr->data%2 !=0 )
			{
				L1.addNode(ptr->data);
			}
			ptr=ptr->next;
		}
		return &L1;	
	}	
};


int main(){
	LinkList obj;
	obj.addNode(17);
	obj.addNode(15);
	obj.addNode(8);
	obj.addNode(12);
	obj.addNode(10);
	obj.addNode(5);
	obj.addNode(4);
	obj.addNode(1);
	obj.addNode(7);
	obj.addNode(6);
	cout<<"Input: ";
	obj.display();
	cout<<endl<<endl;
	cout<<"Output: ";
	LinkList *LL=obj.Modify_LinkList(&obj);
	LL->display();
}
