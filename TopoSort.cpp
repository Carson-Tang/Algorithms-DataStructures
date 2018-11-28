#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int N,M,u,v,indeg[MAXN];
vector<int>adj[MAXN],topo;
queue<int>q;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    for(int i = 1; i <= N; i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        topo.push_back(cur);
        for(int neigh : adj[cur]){
            if(--indeg[neigh]==0) q.push(neigh);
        }
    }
    for(int node : topo) cout<<node<<" ";
    return 0;
}
