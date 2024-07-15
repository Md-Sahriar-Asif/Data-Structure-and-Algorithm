// Array contains both positive and negative numbers
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

bool hashTable[MAX + 1][2];

bool search(int x)
{
    if (x >= 0)
    {
        if (hashTable[x][0] == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        x = abs(x);
        if (hashTable[x][1] == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void insert(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            hashTable[a[i]][0] = 1;
        }
        else
        {
            hashTable[abs(a[i])][1] = 1;
        }
    }
}
int main()
{
    int arr[] = {-1, 9, 2, -5, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insert(arr, n);

    int find = 3;
    if(search(find))
        cout << "Element is present" << endl;
    else
    {
        cout << "Element is not present" << endl;
    }
}