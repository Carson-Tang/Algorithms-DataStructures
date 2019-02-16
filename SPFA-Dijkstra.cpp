#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 1000001
#define MOD 1000000007
typedef long long ll;
int N,M,a,b,c,start;
struct edge {
    int w,dest;
    bool operator<(const edge& comp)const{
        return w>comp.w;
    }
};
int dis[MAXN];
priority_queue<edge,vector<edge>,greater<edge>>pq;
vector<edge>adj[MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    cin>>start;
    memset(dis,INT_MAX,sizeof(dis));
    dis[0]=0;
    pq.push({start,0});
    while(!pq.empty()){
        edge u = pq.top(); pq.pop();
        for(edge v : adj[u.dest]){
            if(dis[v.dest]>dis[u.dest] + v.w){
                dis[v.dest]=dis[u.dest] + v.w;
                pq.push(v.dest,dis[v.dest]);
            }
        }
    }
    return 0;
}
