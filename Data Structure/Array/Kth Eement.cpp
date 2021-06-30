
#include<bits/stdc++.h>
using namespace std;

int KthElement(int arr[] , int l , int e , int k)
{
    priority_queue<int> q;

    for(int i=l; i<=e; i++)
    {
        q.push(arr[i]);

        if(q.size() > k)
            q.pop();

    }

    return q.top();

}

int main(){

     int arr[6] = { 7, 10, 4 ,3 ,20 ,15};

     int x =  KthElement(arr , 0 ,5 , 4 );
     cout<<x;
}
