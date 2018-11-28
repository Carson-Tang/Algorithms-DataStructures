#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int N,M,u,v,w,parent[MAXN];
struct edge {
    int u,v,w;
    bool operator<(const edge &a) const{
        return w>a.w;
    }
};
vector<edge>edges,mst;
int Find(int x){
    if(x!=parent[x]){
        parent[x]=Find(parent[x]);
    } return parent[x];
}
void Union(int a, int b){
    parent[Find(a)] = Find(b);
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1; i <= N; i++) parent[i]=i;
    for(int i = 0; i < M; i++){
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    for(edge c : edges){
        if(Find(c.u)!=Find(c.v)){
            mst.push_back(c);
            Union(c.u,c.v);
        }
    }
    for(edge c : mst){
        cout<<c.u<<" "<<c.v<<" "<<c.w<<"\n";
    }
    return 0;
}
