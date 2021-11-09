#include<bits/stdc++.h>
using namespace std;

bool isCyclic(vector<int> adj[], bool vis[], int src){
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        
        if(vis[temp]){
            return true;
        }

        vis[temp] = true;
        int n = adj[temp].size();

        for(int i=0; i<n; i++){
            if(!vis[adj[temp][i]]){
                q.push(adj[temp][i]);
            }
        }
    }

    return false;
}

bool isCycle(int v, vector<int>adj[]){
    bool vis[v] = {false};
    for(int i=0; i<v; i++){
        if(!vis[i] && isCyclic(adj, vis, i)){
            return true;
        }
    }

    return false;
}

int main(){
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(1);
    adj[4].push_back(3);

    cout<<isCycle(5, adj)<<endl;

    return 0;
}