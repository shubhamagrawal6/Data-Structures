#include<bits/stdc++.h>
using namespace std;

void DFSUtil(int node, vector<int> adj[], vector<bool>& vis, vector<int>& ans){
    vis[node] = true;
    ans.push_back(node);
    
    int n = adj[node].size();
    for(int i=0; i<n; i++){
        if(!vis[adj[node][i]]){
            DFSUtil(adj[node][i], adj, vis, ans);
        }
    }
}

vector<int> DFS(int v, vector<int> adj[]){
    vector<bool> vis(v, 0);
    vector<int> ans;
    
    DFSUtil(0, adj, vis, ans);
    
    return ans;
}

int main(){
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[2].push_back(4);

    vector<int> ans = DFS(5, adj);
    
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}