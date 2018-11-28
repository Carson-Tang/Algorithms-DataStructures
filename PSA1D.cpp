#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 50001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int N,Q,a[MAXN],psa[MAXN],l,r;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i = 1; i <= N; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= N; i++){
        psa[i]=psa[i-1]+a[i];
    }
    for(int i = 0; i < Q; i++){
        cin>>l>>r;
        cout<<psa[r]-psa[l-1]<<"\n";
    }
    return 0;
}
