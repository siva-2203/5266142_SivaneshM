// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
void display(Node *&head)
{
    Node *temp=head;
    do
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<"\n";
    return;
}
void search(Node *&head,int tar)
{
    int flag=1;
    Node *temp=head;
    do
    {
        if(temp->val==tar)
        {
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
    return;
    
}
void insert_beg(Node *&head,int val)
{
    Node *n0=new Node(val);
    n0->next=head;
    Node *temp=head;
    do
    {
        temp=temp->next;
    }while(temp->next!=head);
    temp->next=n0;
    head=n0;
    return;
}
void insert_end(Node *&head,int val)
{
    if(head==NULL)
    {
        return;
    }
    Node *n5=new Node(val);
    Node *temp=head;
    do
    {
        temp=temp->next;
    }while(temp->next!=head);
    temp->next=n5;
    n5->next=head;
    return;
}
void insert_mid(Node *&head,int val)
{
    if(head==NULL || head->val>val)
    {
        insert_beg(head,val);
        return;
    }
    Node *n6=new Node(val);
    Node *temp=head;
    while(temp->next!=head && temp->next->val<val)
    {
        temp=temp->next;
    }
    if(temp->next==head)
    {
        insert_end(head,val);
        return;
    }
    n6->next=temp->next;
    temp->next=n6;
    return;
    
}
void insert_pos(Node *&head,int val,int pos)
{
    if(head==NULL || pos==0)
    {
        insert_beg(head,val);
        return;
    }
    int count=0;
    Node *n6=new Node(val);
    Node *temp=head;
    while(temp->next!=head && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==head)
    {
        insert_end(head,val);
        return;
    }
    n6->next=temp->next;
    temp->next=n6;
    return;
}
void del_beg(Node *&head)
{
    if(head==NULL)
    {
        return;
    }
    Node *temp=head;
    Node *temp1=head;
    do
    {
        temp=temp->next;
    }while(temp->next!=head);
    head=head->next;
    temp->next=head;
    delete temp1;
    return;
}
void del_end(Node *&head)
{
    if(head==NULL)
    {
        return;
    }
    Node *temp=head;
    do
    {
        temp=temp->next;
    }while(temp->next->next!=head);
    Node *delnode=temp->next;
    temp->next=head;
    delete delnode;
    return;
}
void del_mid(Node *&head,int val)
{
    if(head==NULL || head->val==val)
    {
        del_beg(head);
        return;
    }
    Node *temp=head;
    while(temp->next!=head && temp->next->val<val)
    {
        temp=temp->next;
    }
    if(temp->next==head)
    {
        del_end(head);
        return;
    }
    temp->next=temp->next->next;
    return;
    
}
void del_pos(Node *&head,int val,int pos)
{
    if(head==NULL || pos==0)
    {
        del_beg(head);
        return;
    }
    int count=0;
    Node *temp=head;
    while(temp->next!=head && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==head)
    {
        del_end(head);
        return;
    }
    temp->next=temp->next->next;
    return;
    
}

int main() {
   Node *n1=new Node(1);
   Node *head=n1;
   Node *n2=new Node(2);
   Node *n3=new Node(3);
   //Node *n4=new Node(4);
   n1->next=n2;
   n2->next=n3;
   n3->next=n1;
   //n4->next=n1;
   display(head);
   search(head,3);
   search(head,5);
   cout<<"After Insertion:\n";
   insert_beg(head,0);
   display(head);
   cout<<"After Insertion:\n";
   insert_end(head,5);
   display(head);
   cout<<"After Insertion:\n";
   insert_mid(head,4);
   display(head);
   cout<<"After Insertion:\n";
   insert_mid(head,-1);
   display(head);
   cout<<"After Insertion:\n";
   insert_mid(head,6);
   display(head);
   cout<<"After Insertion:\n";
   insert_pos(head,-2,0);
   display(head);
   cout<<"After Insertion:\n";
   insert_pos(head,7,9);
   display(head);
   cout<<"After Insertion:\n";
   insert_pos(head,0,6);
   display(head);
   cout<<"After Deletion:\n";
   del_beg(head);
   display(head);
   cout<<"After Deletion:\n";
   del_end(head);
   display(head);
   cout<<"After Deletion:\n";
   del_mid(head,6);
   display(head);
   cout<<"After Deletion:\n";
   del_mid(head,-1);
   display(head);
   cout<<"After Deletion:\n";
   del_mid(head,3);
   display(head);
   cout<<"After Deletion:\n";
   del_pos(head,0,0);
   display(head);
   cout<<"After Deletion:\n";
   del_pos(head,0,2);
   display(head);
   cout<<"After Deletion:\n";
   del_pos(head,5,3);
   display(head);
   return 0;
}

