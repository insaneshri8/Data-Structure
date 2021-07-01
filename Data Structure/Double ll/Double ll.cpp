// Example program
#include <iostream>
#include <string>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* pre;
    
    
    node(int val)
    {
        data = val;
        next = NULL;
        pre = NULL;
    }
};

void onHead(node* &head , int val)
{
    node* n = new node(val);
    
    n->next = head;
    
    if(head != NULL)
    head->pre = n;
    
    head = n;
    
    
}

void onTail(node* &head , int val)
{
    node* n = new node(val);
    node* temp = head;
    
    if(head == NULL)
    {
        onHead(head , val);
        return;
    }
    
    while(temp->next  != NULL)
    {
        temp = temp-> next;
    }
    
    temp->next = n;
    n->pre = temp;
    
}

void deleteFirst(node* &head)
{
    node* todelete  = head;
    head = head->next;
    head->pre = NULL;
    
    delete todelete;
    
}

void deletion(node* &head , int pos)
{
    if(pos == 1)
    {
        deleteFirst(head);
        return;
    }
    
    node* temp = head;
    int tempPos = 1;
    while(temp != NULL && tempPos < pos)
    {
        temp = temp->next;
        tempPos++;
    }
    
    temp->pre->next = temp->next;
    
    if(temp->next != NULL)
    temp->next->pre = temp->pre;
    
    delete temp;
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    
}
int main()
{
    node* head = NULL;
     onTail(head , 100);
     onTail(head, 200);
     onTail(head , 400);
     onTail(head, 600);
     
     deletion(head, 4);
     display(head);
}
