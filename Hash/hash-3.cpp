// unordered map

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> umap;
    umap["prince"] = 44;
    umap["sa"] = 56;
    umap["helloworld"] = 90;

    umap.insert(make_pair("mobile", 17000)); 

    // for(auto x : umap)
       // cout << x.first << " " << x.second << endl;

    for(auto itr = umap.begin(); itr != umap.end(); itr++)
        cout << itr->first << " " << itr->second << endl;

    /* // finding value
    string key = "prince";
    if(umap.find(key) != umap.end())
        cout << "key found" << endl;
    else
        cout << "key not found" << endl;
    
    if(umap.find(key) != umap.end()){
        auto temp = umap.find(key);
        cout << "key is: " << temp->first << endl;
        cout << "value is: " << temp->second << endl;
    }

    cout << "size is: " << umap.size() << endl; */

    // deleting key value pair
    string key2 = "helloworld";
    umap.erase(key2);

    for(auto itr = umap.begin(); itr != umap.end(); itr++)
        cout << itr->first << " " << itr->second << endl;

    cout << "size is: " << umap.size() << endl;

    //counting the frequency of number in an array
    int arr[] = {7, 1, 0, 3, 5, 0, 1, 3, 2, 5, 7, 3, 8, 9, 9};
    unordered_map<int, int> unmaped;

    for(int i=0; i<15; i++)
    {
        int key = arr[i];
        unmaped[key]++;
    }
    cout << endl;
    for(auto itr = unmaped.begin(); itr != unmaped.end(); itr++)
        cout << itr->first << " " << itr->second << endl;   
}