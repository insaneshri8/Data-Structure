#include<bits/stdc++.h>
using namespace std;

int main()
{

    //kadane's algo

  int arr[5] = {-1, -4,-3,-5,-7};

  int currentSum = 0;
  int maxSum = INT_MIN;

  for(int i=0; i<5; i++)
  {
      currentSum += arr[i];
      if(currentSum < 0)
        currentSum = 0;

      maxSum = max(maxSum , currentSum);
  }

  cout<<maxSum;

}
