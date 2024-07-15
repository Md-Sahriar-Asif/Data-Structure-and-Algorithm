#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<=high-1; j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = pivot;
    arr[high] = temp;
    return i;  //pivot index
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pidx = partition(arr, low, high);

        quickSort(arr, low, pidx-1);
        quickSort(arr, pidx+1, high);
    }
}

int main(){
    int arr[] = {6, 3, 9, 5, 2, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

//worst case occurs in quickSort when pivot is always the
//   smallest or the largest elements