#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

     int arr[7] = {1,2,3,4,5,6,7};


     int i=0;
     int j = 6;

     while(i != j)
     {
             swap(arr[i] , arr[j]);
             i++;
             j--;
     }


     for(int i=0; i<7; i++)
     {
         cout<<arr[i]<<" ";
     }

}
