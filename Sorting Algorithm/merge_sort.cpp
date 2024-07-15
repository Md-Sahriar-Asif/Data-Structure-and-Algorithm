#include<bits/stdc++.h>
using namespace std;

void conquer(int arr[], int start, int mid, int end){
    int merged[end - start + 1];

    int idx1 = start;
    int idx2 = mid+1;
    int x = 0;

    while(idx1 <= mid && idx2 <= end){
      if(arr[idx1] <= arr[idx2]){
        merged[x++] = arr[idx1++];
      }else{
        merged[x++] = arr[idx2++];
      }
    }
    
    while(idx1 <= mid){
        merged[x++] = arr[idx1++];
    }

    while(idx2 <= end){
        merged[x++] = arr[idx2++];
    }

    int sz = sizeof(merged)/sizeof(merged[0]);
    for(int i=0, j = start ; i<sz; i++, j++){
        arr[j] = merged[i];
    }
}

void divide(int arr[], int start, int end){
    if(start >= end)
      return;

    int mid = start + (end-start)/2;

    divide(arr, start, mid);
    divide(arr, mid+1, end); 

    conquer(arr, start, mid, end);
}

int main(){
    int arr[] = {6, 3, 9, 5, 2, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    divide(arr, 0, n-1);
    for(int i = 0; i<n; i++){
      cout << arr[i] << " ";
    }
}

