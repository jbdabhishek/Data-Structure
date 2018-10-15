#include<iostream>
using namespace std;
struct node{
int data;
node *next;
};
void push(node **head,int value)
{
    node *temp=new node;
    temp->data=value;
    temp->next=*head;
    *head=temp;
}
void printList(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}
void duplicate(node *head)
{
    node *ptr1,*ptr2,*dup;
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL)
    {
        ptr2=ptr1;
        while(ptr2!=NULL && ptr2->next!=NULL)
        {
            if(ptr1->data==ptr2->next->data)
            {
                dup=ptr2;
                ptr1->next=ptr2->next->next;
                delete(dup);
            }
            else
                ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}
int main()
{
    node *head=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        push(&head,x);
    }
    printList(head);
    duplicate(head);
    printList(head);
}
