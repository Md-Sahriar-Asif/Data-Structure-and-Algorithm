#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){  // max heap
    int largest = i;
    int left = 2*i;
    int right = (2*i)+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n=5;
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout << "Printing the array now:- " << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* 
for 1th base indexing:
left child = (2*i)th index
right child = (2*i)+1
parent = i/2

for 0th base indexing:
left child = (2*i)+1
right child = (2*i)+2
parent = ((i+1)/2)-1
*/