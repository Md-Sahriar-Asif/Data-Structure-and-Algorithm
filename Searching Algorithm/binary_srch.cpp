#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,index=-1;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];

    cout << "Enter a sorted array: ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> x;

    int low=0, high=n-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]==x)
        {
            index=mid;
            break;
        }
        else if(arr[mid]<x)
            low = mid+1;
        else
            high = mid-1;
    }

    if(index==-1){
        cout << "Couldn't found the element" << endl;
    }
    else{
        cout << "Element at index: " << index << endl;
    }


}