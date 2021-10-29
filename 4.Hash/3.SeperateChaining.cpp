#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> separateChaining(int hashSize, int arr[], int n){
    vector<vector<int>> hash(hashSize);
    for(int i=0; i<n; i++){
        hash[arr[i]%hashSize].push_back(arr[i]);
    }
    return hash;
}

int main() {
	int arr[] = {92, 4, 14, 24, 44, 91};
    int hashSize = 10;

    vector<vector<int>> hash = separateChaining(hashSize, arr, 6);
    for(auto itr: hash){
        for(auto j: itr){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
	return 0;
};