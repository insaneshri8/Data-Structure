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
    cout<<"NULL";
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

void Delete_Head(node* &head)
{
    node* tempDel = head;
    
    
    head = head->next;
    
    delete tempDel;
    
}


void Deletion(node* &head , int val)
{
    if(head == NULL)
    {
        cout<<" List is empty"<<endl;
            return;
    
    }
    
    if(head->next == NULL)
    {
        Delete_Head(head);
    }

           
    node* temp = head;
    
    while(temp->next->data != val)
    {
        temp = temp->next;
    }
    
    node* todelete = temp->next;
    temp->next = temp->next->next;
 
  delete todelete;
    
}

node* reverse(node* &head)
{
    node* Pre = NULL;
    node* Current = head;
    node* next;
    
    while(Current != NULL)
    {
        next = Current->next;
        Current->next  = Pre;
        
        
        // move pointer forward
        Pre = Current;
        Current = next;
    }
    
    return Pre;
}
    
node* reverseRecursive(node* &head)
{
    
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node* newHead = reverseRecursive(head->next);
    
    head->next->next = head;
    head->next = NULL;
    return newHead;
    
    
}

node* reverseKth(node* &head , int k)
{
    node* pre = NULL;
    node* current = head;
    node* next;
    
    int count = 0;
    while(current != NULL && count < k)
    {
        next = current->next;
        current->next = pre;
        
        pre = current;
        current = next;
        count++;
    }
    if(next != NULL)
    head->next = reverseKth(next , k);
    
    
     return pre;
}


void makeCycle(node* &head , int pos)
{
    node* temp = head;
    node* startNode;
    int count = 1;
    while(temp->next != NULL)
    {
        if(count == pos)
        {
            startNode = temp;
        }
        
        temp = temp->next;
        
       count++;
    }
    
       temp->next = startNode;
}


bool detectCycle(node* &head)
{
   node* slow = head;
   node* fast = head;
   
   while(fast != NULL && fast->next != NULL)
   {
       slow = slow->next;
       fast = fast->next->next;
       if(slow == fast)
       return true;
   }
   
   return false;
}
int main()
{

     node* head = NULL;
     
     insertTail(head , 10);
      insertTail(head , 20);
       insertTail(head , 30);
        insertTail(head , 40);
        insertTail(head , 60);
        insertTail(head , 70);
        
         //for detect cycle you should make cycle first by using makeCycle method
        cout<<detectCycle(head);
  
        
        // cout<<search(head , 100)<<endl;
     

}
