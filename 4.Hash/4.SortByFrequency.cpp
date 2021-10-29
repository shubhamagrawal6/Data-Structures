#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> sortByFreq(int arr[], int n){
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    vector<pair<int,int>> vv(mp.begin(),mp.end());
    sort(vv.begin(), vv.end(), cmp);

    vector<int> v;
    for(auto it: vv){
        int m = it.second;
        while(m--){
            v.push_back(it.first);
        }
    }

    return v;
}

int main(){
    int arr[] = {5, 5, 4, 6, 4};
    
    vector<int> ans = sortByFreq(arr, 5);
    
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
	
    return 0;
}