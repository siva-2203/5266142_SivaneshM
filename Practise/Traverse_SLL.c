// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int val;
    struct Node *next;

}Node;
int main() {
    // Write C code here
    //printf("Try programiz.pro");
//struct Node *head=n1;
    Node *n1 = malloc(sizeof(Node));
    Node *n2 = malloc(sizeof(Node));
    Node *n3 = malloc(sizeof(Node));
        n1->val = 1;
    n2->val = 9;
    n3->val = 7;
n1->next=n2;
n2->next=n3;
n3->next=NULL;
   Node *head = n1;
Node *temp=head;
while(temp!=NULL)
{
    printf("%d",temp->val);
    temp=temp->next;
}
    return 0;
}
