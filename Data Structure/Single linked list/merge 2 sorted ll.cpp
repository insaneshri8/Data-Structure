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


void removeCycle(node* &head)
{
    node* slow = head;
    node* fast = head;
    
    do{
        // moving slow pointer by 1 step and fast by 2
        slow = slow->next;
        fast = fast->next->next;
        
    }while(fast != slow);
    
    // if both in same node then assign one pointer to the head
    // in my case i assign fast pointer
    
    fast = head;
    while(fast->next != slow->next)  // checking condition both pinter are pointing to same node or not
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    // after they point to same node we come out from loop and then assign slow pointer to null to make cycle free linked list
    slow->next = NULL;
}

int len(node* head)
{
    int len = 0;
    node* temp  = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

node* kappend(node* &head , int k)
{
    node* newhead;
    node* newtail;
    node* temp = head;
    
    int l = len(head);
    
    int count = 1;
    k = k%l;
    while(temp->next != NULL)
    {
        if(count == l-k)
        {
            newtail = temp; // new tail assign last value of node
        }
        
        if(count == l-k+1)
        {
            newhead = temp; // l-k+1 newnode
        }
        
        temp = temp->next;
        count++;
        
    }
    
    newtail->next = NULL; // link newtail to null
    temp->next = head; //  lst element to head
    
    return newhead;
}

node* append(node* &head , int k)
{
    node* newhead;
    node* newtail;
    node* temp = head;
    
    int l  = len(head);
    int count = 1;
    
    k = k%l;
    while(temp->next != NULL)
    {
              if(count == l-k)
              {
                  newtail = temp;
              }
              if(count == l-k+1)
              {
                  newhead = head;
              }
              
              temp = temp->next;
              count++;
    }
    
    newtail->next = NULL;
    temp->next = head;
    
    return newhead;
    
}

int intersection(node* &head1 , node* &head2)
{
    int l1 = len(head1);
    int l2 = len(head2);
    
    int d=0;
    node* ptr1;
    node* ptr2;
    
    if(l1 > l2)
    {
        d = l1 -l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    
    while(d)
    {
        ptr1 = ptr1->next;
        
        if(ptr1 == NULL)
        {
            return -1;
        }
        d--;
        
    }
    
    
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return -1;
    
}

node* merge(node* &head1 , node* &head2)
{
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dummy = new node(-1);
    node* ptr3 = dummy;
    
    while(ptr1 != NULL && ptr2 != NULL)
    {
       if(ptr1->data < ptr2->data)
       {
           ptr3->next = ptr1;
           ptr1 = ptr1->next;
       }
       else
       {
           ptr3->next = ptr2;
           ptr2 = ptr2->next;
       }
       
       ptr3 = ptr3->next;
       
    }
    
       while(ptr1 != NULL)
       {
            ptr3->next = ptr1;
               ptr1 = ptr1->next;
                 ptr3 = ptr3->next;
       
       }
       
       while(ptr2 != NULL)
       {
          ptr3->next = ptr2;
          ptr2 = ptr2->next;
          ptr3 = ptr3->next;
       }
    
    return dummy->next;
}

int main()
{

     node* head1 = NULL;
     
     insertTail(head1 , 1);
      insertTail(head1 , 4);
       insertTail(head1 , 5);
       
        node* head2 = NULL;
        insertTail(head2 , 2);
        insertTail(head2 , 3);
        insertTail(head2 , 6);
        
        
         //for detect cycle you should make cycle first by using makeCycle method
         
        //  makeCycle(head , 3);
        // cout<<detectCycle(head)<<endl;
        // removeCycle(head);
        
        // cout<<detectCycle(head)<<endl;
        
      
         display(head1);
         cout<<endl;
         display(head2);
         
         node* newHead = merge(head1 ,head2);
         cout<<endl;
         display(newHead);
         
        
        // cout<<search(head , 100)<<endl;
     

}
