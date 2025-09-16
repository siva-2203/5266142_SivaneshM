// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class stack
{
  int n;
  int top;
  int *arr;
  public:
    stack(int size)
    {
        n=size;
        arr=new int(n);
        top=-1;
        
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            cout<<"Stack is empty\n";
            return true;
        }
        else
        {
            cout<<"Stack is not empty\n";
            return false;
        }
    }
    bool isFull()
    {
        if(top==n-1)
        {
            cout<<"Stack is Full\n";
            return true;
        }
        else
        {
            cout<<"Stack is not Full\n";
            return false;
        }
    }
    void push(int elem)
    {
        if(isFull())
        {
            cout<<"Overflow\n";
        }
        arr[++top]=elem;
        cout<<"Pushed successfully\n";
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"underflow\n";
        }
        int pop_elem=arr[top--];
        cout<<"Element "<<pop_elem<<" Popped successfully\n";
    }
    void peek()
    {
        cout<<"peek element:"<<arr[top]<<"\n";
    }
    
};
int main() {
    stack s=stack(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.pop();
    s.isEmpty();
    s.isFull();
    s.peek();
    cout<<"Displaying final elements\n";
    while(!s.isEmpty())
    {
        s.peek();
        s.pop();
    }
    return 0;
}

