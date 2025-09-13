// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* prev;
	Node* next;
	Node(int n){this->val=n;this->prev=NULL;this->next=NULL;}
};
void display(Node *&head,Node *&tail)
{
    cout<<"\n";
    cout<<"Forward Traversal\n";
    Node *temp=head;
    do
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<"\n";
    cout<<"Backward Traversal\n";
    Node *temp1=tail;
    do
    {
        cout<<temp1->val<<" ";
        temp1=temp1->prev;
    }while(temp1!=tail);
    return;
}
void Search(Node *&head,Node *&tail,int tar)
{
    cout<<"\n";
    cout<<"Forward Traversal\n";
    int flag=1;
    Node *temp=head;
    do
    {
        if(temp->val==tar){
        cout<<"YES"<<" ";
        flag=0;
        }
        temp=temp->next;
    }while(temp!=head);
    if(flag==1)
    {
        cout<<"NO"<<" ";
    }
    cout<<"\n";
    cout<<"Backward Traversal\n";
    int flag1=1;
    Node *temp1=tail;
    do
    {
         if(temp1->val==tar){
        cout<<"YES"<<" ";
        flag1=0;
        }
        temp1=temp1->prev;
    }while(temp1!=tail);
    if(flag1==1)
    {
        cout<<"NO"<<" ";
    }
    return;
}
void insert_beg(Node *&head,Node *&tail,int val)
{
    Node *n1=new Node(val);
    n1->next=head;
    head->prev=n1;
    head=n1;
    tail->next=n1;
    n1->prev=tail;
    return;
}
void insert_end(Node *&head,Node *&tail,int val)
{
    if(head==NULL)
    {
        return;
    }
    Node *n1=new Node(val);
    tail->next=n1;
    n1->prev=tail;
    tail=n1;
    tail->next=head;
    head->prev=tail;
    return;
}
OAvoid insert_mid(Node *&head,Node *&tail,int val)
{
    if(head==NULL || head->val>val)
OA    {
        insert_beg(head,tail,val);
OA        return;
    }
    Node *n1=new Node(val);
    Node *temp=head;
    while(temp->next!=head && temp->next->val<val)
OA    {
        temp=temp->next;
    }
    if(temp->next==head)
    {
        insert_end(head,tail,val);
        return;
    }
    n1->next=temp->next;
    temp->next=n1;
    n1->next->prev=n1;
    n1->prev=temp;
    return;
}
void insert_pos(Node *&head,Node *&tail,int val,int pos)
{
    if(head==NULL || pos==0)
    {
        insert_beg(head,tail,val);
        return;
    }
    int count=0;
    Node *n1=new Node(val);
    Node *temp=head;
    while(temp->next!=head && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==head)
    {
        insert_end(head,tail,val);
        return;
    }
    n1->next=temp->next;
    temp->next=n1;
    n1->next->prev=n1;
    n1->prev=temp;
    return;
}
void del_beg(Node *&head,Node *&tail)
{
    if(head ==NULL)
    {
        return;
    }
    Node *temp=head;
    head=head->next;
    tail->next=head;
    head->prev=tail;
    delete temp;
    return;
}
void del_end(Node *&head,Node *&tail)
{
    if(head==NULL)
    {
        return;
    }
    Node *temp=tail;
    tail=tail->prev;
    head->prev=tail;
    tail->next=head;
    delete temp;
    return;
}
void del_mid(Node *&head,Node *&tail,int val)
{
    if(head->val==val)
    {
        del_beg(head,tail);
        return;
    }
    Node *temp=head;
    while(temp->next->next!=head && temp->next->val<val)
    {
        temp=temp->next;
    }
    if(temp->next->next==head)
    {
        del_end(head,tail);
        return;
    }
    Node *delnode=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete delnode;
    return;
}
void del_pos(Node *&head,Node *&tail,int pos)
{
    if(pos==0)
    {
        del_beg(head,tail);
        return;
    }
    int count=0;
    Node *temp=head;
    while(temp->next->next!=head && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next->next==head)
    {
        del_end(head,tail);
        return;
    }
    Node *delnode=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete delnode;
    return;
}
int main() {
   Node *n1=new Node(1);
   Node *n3=new Node(3);
   Node *n5=new Node(5);
   Node *n7=new Node(7);
   Node *head=n1;
   n1->next=n3;
   n3->next=n5;
   n5->next=n7;
   n7->next=n1;
   n7->prev=n5;
   n5->prev=n3;
   n3->prev=n1;
   n1->prev=n7;
   Node *tail=head->prev;
   display(head,tail);
   Search(head,tail,3);
   Search(head,tail,4);
   cout<<"\nAfter Insertion";
   insert_beg(head,tail,0);
   display(head,tail);
   cout<<"\nAfter Insertion";
   insert_end(head,tail,8);
   display(head,tail);
   cout<<"\nAfter Insertion";
   insert_mid(head,tail,-1);
   display(head,tail);
   cout<<"\nAfter Insertion";
   insert_mid(head,tail,2);
   display(head,tail);
   cout<<"\nAfter Insertion";
   insert_mid(head,tail,9);
   display(head,tail);
   cout<<"\nAfter Insertion";
   insert_pos(head,tail,-2,0);
   display(head,tail);
   cout<<"\nAfter Insertion";
   insert_pos(head,tail,10,10);
   display(head,tail);
   cout<<"\nAfter Insertion";
   insert_pos(head,tail,4,6);
   display(head,tail);
   cout<<"\n After Deletion:";
   del_beg(head,tail);
   display(head,tail);
   cout<<"\n After Deletion:";
   del_end(head,tail);
   display(head,tail);
   cout<<"\n After Deletion:";
   del_mid(head,tail,-1);
   display(head,tail);
    cout<<"\n After Deletion:";
   del_mid(head,tail,9);
   display(head,tail);
    cout<<"\n After Deletion:";
   del_mid(head,tail,3);
   display(head,tail);
   cout<<"\n After Deletion:";
   del_pos(head,tail,0);
   display(head,tail);
   cout<<"\n After Deletion:";
   del_pos(head,tail,5);
   display(head,tail);
   cout<<"\n After Deletion:";
   del_pos(head,tail,2);
   display(head,tail);
    return 0;
}

