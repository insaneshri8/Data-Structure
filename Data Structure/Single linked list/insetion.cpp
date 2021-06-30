#include<iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;


    node(int val)
    {
        data = val;
        next = NULL;
    }
    
};

void athead(node* &head , int val)
{
    node* n = new node(val);
    
    n->next = head;
    head = n;
}

void insertTail(node* &head , int val)
{
    node* n  = new node(val);
    
   if(head == NULL)
   {
       head = n;
       return; 
   }

   node* temp = head;

   while(temp->next != NULL)
   {
       temp = temp->next;
   }

   temp->next = n;
    

}

void display(node* head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    
    }
}


bool search(node* head, int key)
{
    node* temp = head;
    
    while(temp != NULL)
    {
        if(temp->data == key)
        return true;
        
        temp = temp->next;
    }
    
    return false;
}

void atIndex(node* &head , int index , int val)
{
   node* n  = new node(val);
   
   node* prev = NULL; 
   node* current = head;
   int tempPos = 0;
   
   if(head != NULL)
   {
       while(current->next != NULL && tempPos != index)
       {
           prev = current;
           current = current->next;
           tempPos++;
       }
       if(head == NULL || index == 0)
       {
           athead(head , val);
       }
       else if(current->next == NULL && index == tempPos+1)
       {
           insertTail(head , val);
       }
       else
       {
           prev->next = n;
           n->next = current;
           
           cout<<" NODE ADDED AT POS : "<<index<<endl;
           
       }
       
   }
   
}

int main()
{

     node* head = NULL;
     
     insertTail(head , 10);
      insertTail(head , 20);
       insertTail(head , 30);
        insertTail(head , 40);
        
        
        atIndex(head , 4 , 500);
        display(head);
        
        // cout<<search(head , 100)<<endl;
     

}