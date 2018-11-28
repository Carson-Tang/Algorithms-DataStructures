#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int u,v,N,M,dis[MAXN];
bool vis[MAXN];
vector<int>adj[MAXN];
void dfs(int u){
    vis[u]=1;
    for(int v : adj[u]){
        if(!vis[v]){
            dis[v]=dis[u]+1;
            dfs(v);
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
