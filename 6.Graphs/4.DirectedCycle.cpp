#include<bits/stdc++.h>
using namespace std;

bool isCyclic(vector<int> adj[], bool visited[], bool recSt[], int parent){
    visited[parent] = true;
    recSt[parent] = true;
    int n = adj[parent].size();
    
    for(int i=0; i<n; i++){
        if(recSt[adj[parent][i]]){
            return true;
        }
    
        else if(!visited[adj[parent][i]] && isCyclic(adj, visited, recSt, adj[parent][i])){
            return true;
        }
    }
    
    recSt[parent] = false;
    
    return false;
}
bool isCycle(int v, vector<int> adj[]) {
    bool visited[v] = {false};
    bool recSt[v] = {false};

    for(int i=0; i<v; i++){
        if(!visited[i] && isCyclic(adj, visited, recSt, i)){
            return true;
        }
    }
    
    return false;
}

int main(){
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(3);

    cout<<isCycle(5, adj)<<endl;

    return 0;
}