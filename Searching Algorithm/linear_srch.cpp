#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,index=-1;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];

    cout << "Enter the array: ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> x;

    for(int i=0; i<n; i++){
        if(arr[i]==x){
            index=i;
        }
    }

    if(index==-1)
        cout << "Element couldn't found" << endl;
    else
        cout << "Element found at index: " << index << endl;

}