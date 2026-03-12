#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node){
    visited[node] = true;

    for(int neigh : adj[node]){
        if(!visited[neigh]){
            dfs(neigh);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1,false);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> comp;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            comp.push_back(i);
            dfs(i);
        }
    }

    cout << comp.size()-1 << endl;

    for(int i=1;i<comp.size();i++){
        cout << comp[i-1] << " " << comp[i] << endl;
    }
}