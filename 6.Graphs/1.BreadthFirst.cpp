#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int v, vector<int> adj[]){
    vector<int> ans;
    queue<int> q;

    bool visited[v] = {false};

    q.push(0);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        visited[temp] = true;
        ans.push_back(temp);
        
        int n = adj[temp].size();
        for(int i=0; i<n; i++){
            if(!visited[adj[temp][i]]){
                q.push(adj[temp][i]);
                visited[adj[temp][i]] = true;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[2].push_back(4);

    vector<int> ans = BFS(5, adj);
    
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}