
#include<bits/stdc++.h>
using namespace std;

int main(){

     int arr[7] = {1,2,3,4,5,6,7};

   int maxx = INT_MIN;
   int minn = INT_MAX;

   for(int i=0; i<7; i++)
   {
       if(arr[i] > maxx)
        maxx = arr[i];


       if(arr[i] < minn)
        minn  = arr[i];
   }

   cout<<maxx<<" "<<minn;

}
