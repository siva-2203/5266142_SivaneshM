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
class stack_LL
{
    Node *head;
    public:
    void push(Node *&head,int val)
    {
        Node *n1=new Node(val);
        n1->next=head;
        head=n1;
        cout<<"Insertion done successfully\n";
        return;
    }
    bool isEmpty(Node *&head)
    {
        if(head == NULL)
        {
            cout<<"Empty stack\n";
            return true;
        }
        else
        {
            cout<<"Stack is not empty\n";
            return false;
        }
    }
    void pop(Node *&head)
    {
       if(isEmpty(head))
       {
           cout<<"Underflow\n";
           return;
       }
       Node *temp=head;
       cout<<"Element:"<<temp->val<<"popped\n";
       head=head->next;
       delete temp;
       return;
    }
    void peek(Node *&head)
    {
        cout<<"Top element"<<head->val<<"\n";
        return;
    }
};

int main() {
    // Write C++ code here
    Node *head=NULL;
    stack_LL s=stack_LL();
    s.push(head,4);
    s.push(head,3);
    s.push(head,2);
    s.push(head,1);
    s.pop(head);
    s.pop(head);
    s.peek(head);
    s.pop(head);
    s.peek(head);
    s.pop(head);
    s.pop(head);
    

    return 0;
}
