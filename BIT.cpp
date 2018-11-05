#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
int N,M,l,r,x,v,cmd,A[MAXN],BIT[MAXN];
void update(int idx, int val){
    while(idx<MAXN){
        BIT[idx]+=val;
        idx+=idx&-idx;
    }
}
ll query(int idx){
    ll sum = 0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=idx&-idx;
    }
    return sum;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 1; i <= N; i++){
        cin>>A[i];
        update(i,A[i]);
    }
    cin>>M;
    for(int i = 0; i < M; i++){
        cin>>cmd;
        if(cmd==1){
            //change xth to v
            cin>>x>>v;
            update(x,v-A[x-1])
            A[x-1]=v;
        } else {
            //range sum
            cin>>l>>r;
            cout << query(r) - query(l-1) << "\n";
        }
    }
    return 0;
}
