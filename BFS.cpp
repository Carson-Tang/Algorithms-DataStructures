#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
int N,M,a,b,start,u,v;
queue<int>q;
vector<int>adj[MAXN];
int dis[MAXN];
bool vis[MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>start;
    q.push(start);
    while(!q.empty()){
        u = q.front(); q.pop();
        vis[u]=1;
        for(int v : adj[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    return 0;
}
