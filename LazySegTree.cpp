#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
int N,Q,l,r,x,A[MAXN];
ll tree[3*MAXN], lazy[3*MAXN];
void build(int node, int s, int e){
    if(s==e){
        tree[node]=A[s];
    } else if(s<e){
        int mid = (s+e)/2;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}
void update(int node, int s, int e, int l, int r, int val){
    if(lazy[node]!=0){
        tree[node]+=lazy[node];
        if(s!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(s>e||s>r||l>e) return;
    if(s>=l&&e<=r){
        tree[node]+=val;
        if(s!=e){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    int mid = (s+e)/2;
    update(node*2,s,mid,l,r,val);
    update(node*2+1,mid+1,e,l,r,val);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ll query(int node, int s, int e, int l, int r){
    if(lazy[node]!=0){
        if(tree[node]>0){
            tree[node]+=lazy[node];
        }
        if(s!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(s>e||s>r||l>e) return 0;
    if(s>=l&&e<=r) return tree[node];
    int mid = (s+e)/2;
    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N; cin>>Q;
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }
    build(1,0,N-1);
    for(int i = 0; i < Q; i++){
         cin>>cmd>>l>>r;
         if(cmd==1){
              //range sum
              cout << query(1,0,N-1,l-1,r-1) << "\n";
         } else {
              //update
              cin>>x;
              update(1,0,N-1,l-1,r-1,x);
         }
    }
    return 0;
}
