#include<bits/stdc++.h>
using namespace std;

int main()
{

    int arr[6] = { 0, 1, 0 ,0 ,1 ,2};

    int l = 0;
    int mid = 0;
    int h = 5;

    while(mid <= h)
    {
       switch(arr[mid])
       {
       case 0:
        swap(arr[l++] , arr [mid++]);
        break;

        case 1:
        mid++;
        break;

        case 2:
            swap(arr[mid] , arr[h--]);
            break;

       }
    }

   for(int i=0; i<6; i++)
   {
       cout<<arr[i]<<" ";
   }

}
