#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = (2*i)+1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main(){
    int arr[] = {-1 ,55, 53, 54, 52, 50};
    int n = 5;
    heapSort(arr, n);
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Algo:
(1) swap root with last node
(2) size--
(3) check if our current root node is in correct position
(4) repeat 1,2, & 3
*/