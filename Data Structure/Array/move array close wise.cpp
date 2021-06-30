#include<bits/stdc++.h>
using namespace std;

int main()
{

   int arr[6] = { 1, 2, 3 ,4,5 ,6};

   int x = arr[5];

   for(int i=5; i>0; i--)
   {
       arr[i] = arr[i-1];
   }

   arr[0] = x;

   for(int i=0; i<6; i++)
    cout<<arr[i]<<" ";

}
