//Problem Statement: Given an array of N integers, write a program to implement the Selection sorting algorithm.
/*
Approach:

The algorithm steps are as follows:
First, we will select the range of the unsorted array using a loop (say i) that indicates the starting index of the range.
The loop will run forward from 0 to n-1. The value i = 0 means the range is from 0 to n-1, and similarly, i = 1 means the range is from 1 to n-1, and so on.
(Initially, the range will be the whole array starting from the first index.)
Now, in each iteration, we will select the minimum element from the range of the unsorted array using an inner loop.
After that, we will swap the minimum element with the first element of the selected range(in step 1). 
Finally, after each iteration, we will find that the array is sorted up to the first index of the range. 
Note: Here, after each iteration, the array becomes sorted up to the first index of the range. 
That is why the starting index of the range increases by 1 after each iteration. 
This increment is achieved by the outer loop and the starting index is represented by variable i in the following code. 
And the inner loop(i.e. j) helps to find the minimum element of the range [i…..n-1].
*/

#include<bits/stdc++.h>

using namespace std;
void selection_sort(int arr[], int n) {
  // selection sort
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }

  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}
int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before selection sort: " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  selection_sort(arr, n);
  return 0;
}

/*
Time complexity: O(N2), (where N = size of the array), for the best, worst, and average cases.
Reason: If we carefully observe, we can notice that the outer loop, say i, is running from 0 to n-2 i.e. n-1 times, and for each i, the inner loop j runs from i to n-1. 
For, i = 0, the inner loop runs n-1 times, for i = 1, the inner loop runs n-2 times, and so on. 
So, the total steps will be approximately the following: (n-1) + (n-2) + (n-3) + ……..+ 3 + 2 + 1. 
The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). 
Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). 
Here the value of n is N i.e. the size of the array.

Space Complexity: O(1)
*/