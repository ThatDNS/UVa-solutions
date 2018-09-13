/*input
10
10 4 16 2 7 9 3 14 8 1
*/
// Heap sort using max heap
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
void HeapSort(int arr[], int n);
void BuildMaxHeap(int arr[], int n);
void MaxHeapify(int arr[], int parIndex, int n);
void PrintHeap(int arr[], int n);
int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];
  HeapSort(arr, n);
  PrintHeap(arr, n);
  return 0;
}

void HeapSort(int arr[], int n){
  if(n<=1)
    return;
  BuildMaxHeap(arr, n);
  int temp;
  temp = arr[0];
  arr[0] = arr[n-1];
  arr[n-1] = temp;
  HeapSort(arr, n-1);
}

void BuildMaxHeap(int arr[], int n){
  for(int i=n/2-1; i>=0; i--)
    MaxHeapify(arr, i, n);
  return;
}

void MaxHeapify(int arr[], int parIndex, int n){
  if(parIndex > n/2-1)
    return;
  int temp;
  int leftChilIndex = 2*parIndex+1;
  int rightChildIndex = 2*parIndex+2;
  if(leftChilIndex<=n-1 && arr[leftChilIndex] > arr[parIndex]){
    temp = arr[leftChilIndex];
    arr[leftChilIndex] = arr[parIndex];
    arr[parIndex] = temp;
    MaxHeapify(arr, leftChilIndex, n);
  }
  if(rightChildIndex<=n-1 && arr[rightChildIndex] > arr[parIndex]){
    temp = arr[rightChildIndex];
    arr[rightChildIndex] = arr[parIndex];
    arr[parIndex] = temp;
    MaxHeapify(arr, rightChildIndex, n);
  }
  return;
}

void PrintHeap(int arr[], int n){
  for(int i=0; i<n; i++)
    cout << arr[i] << " ";
  cout << "\n";
}
