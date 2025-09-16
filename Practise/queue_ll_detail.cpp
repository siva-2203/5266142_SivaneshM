// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int n)
    {
        this->val=n;
        this->next=NULL;
    }
};
class Queue_LL
{
    Node *front;
    Node *rear;
    int size;
    
    public:
       Queue_LL()
       {
           front=NULL;
           rear=NULL;
           size=0;
       }
       void enqueue(int val)
       {
           Node *n1=new Node(val);
           if(front==NULL || rear==NULL)
           {
               front=n1;
               rear=n1;
               size++;
               cout<<"Enqueued successfuly\n";
               return;
           }
           rear->next=n1;
           rear=n1;
           size++;
           cout<<"Enqueued successfuly\n";
           return;
       }
       void dequeue()
       {
           if(isEmpty())
           {
               return;
           }
           if(front==NULL)
           {
               rear=NULL;
           }
           Node *temp=front;
           front=front->next;
           size--;
           cout<<"Dequeue Element:"<<temp->val<<"\n";
           delete temp;
           return;
       }
       bool isEmpty()
       {
           if(front==NULL||rear==NULL)
           {
               cout<<"queue is empty\n";
               return true;
           }
           else
           {
               cout<<"queue is not empty\n";
               return false;
           }
       }
       void no_of_elem()
       {
           cout<<"number of elements"<<size<<"\n";
       }
       void front_rear_elem()
       {
           if(isEmpty())
           {
               return;
           }
           cout<<"front elem:"<<front->val<<" ";
           cout<<"rear elem:"<<rear->val<<"\n";
           return;
       }
       void display()
       {
           cout<<"Queue elements:";
           Node *temp=front;
           while(temp!=NULL)
           {
               cout<<temp->val<<" ";
               temp=temp->next;
           }
           cout<<"\n";
           
       }
};

int main() {
    // Write C++ code here
    Queue_LL q=Queue_LL();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.isEmpty();
    q.no_of_elem();
    q.front_rear_elem();

    

    return 0;
}

