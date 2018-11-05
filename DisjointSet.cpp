#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
int N,M,a,b,cmd,parent[MAXN]
void Union(int a, int b){
    parent[Find(a)]=Find(b);
}
int Find(int v){
    if(parent[v]!=v) parent[v]=Find(parent[v]);
    return parent[v];
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i = 1; i <= N; i++) parent[i]=i;
    for(int i = 0; i < M; i++){
        cin>>cmd>>a>>b;
        if(cmd==1){
            //merge
            Union(a,b);
        } else {
            //check connection
            cout << (Find(a) == Find(b)) << "\n";
        }
    }
    return 0;
}
