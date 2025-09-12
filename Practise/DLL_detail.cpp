#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int n){
        this->val=n;
        this->next=NULL;
        this->prev=NULL;
    }
};
void display(Node *&head)
{
    cout<<"\n";
    cout<<"Forward Traversal\n";
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<"\n";
    cout<<"Backward Traversal\n";
    Node *temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    while(temp1!=NULL)
    {
        cout<<temp1->val<<" ";
        temp1=temp1->prev;
    }
    return;
}
void search(Node *&head,int tar)
{
    int flag=1;
    cout<<"\nForward Search\n";
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->val==tar)
        {
            cout<<"YES"<<" ";
            flag=0;
        }
        temp=temp->next;
    }
    if(flag==1){
    cout<<"NO"<<" ";}
    cout<<"\n";
    int flag1=1;
    cout<<"Backward Search\n";
    Node *temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    while(temp1!=NULL)
    {
        if(temp1->val==tar)
        {
           cout<<"YES"<<" ";
           flag1=0; 
        }
        temp1=temp1->prev;
    }
    if(flag1==1){
    cout<<"NO"<<" ";}
    return;
}
void insert_beg(Node *&head,int val)
{
    Node *n0=new Node(val);
    n0->next=head;
    head->prev=n0;
    head=n0;
    return;
}
void insert_end(Node *&head,int val)
{
    Node *n8=new Node(val);
    Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n8;
    n8->prev=temp;
    return;
}
void insert_mid(Node *&head,int val)
{
    if(head==NULL ||head->val>val)
    {
        insert_beg(head,val);
        return;
    }
    Node *n4=new Node(val);
    Node *temp=head;
    while(temp->next!=NULL && temp->next->val<val)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        insert_end(head,val);
        return;
    }
    n4->next=temp->next;
    temp->next->prev=n4;
    temp->next=n4;
    n4->prev=temp;
    return;
}
void insert_pos(Node *&head,int val,int pos)
{
    if(head==NULL ||pos==0)
    {
        insert_beg(head,val);
        return;
    }
    int count=0;
    Node *n4=new Node(val);
    Node *temp=head;
    while(temp->next!=NULL && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        insert_end(head,val);
        return;
    }
    n4->next=temp->next;
    temp->next->prev=n4;
    temp->next=n4;
    n4->prev=temp;
    return;
}
int main() {
    Node *n1=new Node(1);
    Node *head=n1;
    Node *n3=new Node(3);
    Node *n5=new Node(5);
    Node *n7=new Node(7);
    n1->next=n3;
    n3->next=n5;
    n5->next=n7;
    n7->prev=n5;
    n5->prev=n3;
    n3->prev=n1;
    display(head);
    search(head,1);
    search(head,2);
    cout<<"\nAfter Insertion:";
    insert_end(head,8);
    display(head);
    cout<<"\nAfter Insertion:";
    insert_mid(head,4);
    display(head);
    cout<<"\nAfter Insertion:";
    insert_mid(head,0);
    display(head);
    cout<<"\nAfter Insertion:";
    insert_mid(head,9);
    display(head);
    cout<<"\nAfter Insertion:";
    insert_pos(head,2,2);
    display(head);
    cout<<"\nAfter Insertion:";
    insert_pos(head,-1,0);
    display(head);
    cout<<"\nAfter Insertion:";
    insert_pos(head,6,7);
    display(head);
    return 0;
}

