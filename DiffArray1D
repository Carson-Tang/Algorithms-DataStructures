#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 5001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int N,Q,a[MAXN],diff[MAXN],l,r,x;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i = 1; i <= N; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= N; i++){
        diff[i]=a[i]-a[i-1];
    }
    for(int i = 0; i < Q; i++){
        cin>>l>>r>>x;
        diff[l]+=x;
        diff[r+1]-=x;
    }
    return 0;
}
