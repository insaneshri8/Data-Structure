#include<bits/stdc++.h>
using namespace std;

int main()
{

    int arr[5] = {1, 2, 3,5,6};
    int brr[5] = {2,1,45,23,12};

    set<int> s;

    for(int i=0; i<5; i++)
      s.insert(arr[i]);

        for(int i=0; i<5; i++)
         s.insert(brr[i]);

         cout<<s.size();
}
