//unorderd set

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    s.insert(20); // duplicate value is not allowed
    
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " " << &(*it) << " "  << (&it) << endl;
    }
    // &(*it) will return the memory add of the value
    // (&it) will return the memory add of the iterator
    cout << "number of elements: " << s.size() << endl;

    //s.clear(); // it will clear all the ele of the set
    //cout << "number of elements: " << s.size() << endl;

    /* //finding a key
    int key = 5;
    if(s.find(key) == s.end()){
        cout << "key not found" << endl;
    }else{
        cout << "key found" << endl;
    } */

    /*  //deleting a key
    int deleted_key = 15; 
    s.erase(deleted_key);
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " "  << (&it) << endl;
    }
    cout << "number of elements: " << s.size() << endl; */

    /* / finding a key and if it is present in the set then delete it
    int key = 5;
    if(s.find(key) == s.end())
    {
        cout << "key not found" << endl;
    }else{
        auto temp = s.find(key);
        s.erase(temp);
    }
    cout << "number of elements: " << s.size() << endl; */

    // if number is present then count will return 1 otherwise 0
    if(s.count(5))
        cout << "key found" << endl;
    else
        cout << "key not found" << endl;
}