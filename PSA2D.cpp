#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 5001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int N,Q,a[MAXN][MAXN],psa[MAXN][MAXN],l,r,l2,r2;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            psa[i][j]=psa[i-1][j]+a[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            psa[i][j]+=psa[i][j-1];
        }
    }
    for(int i = 0; i < Q; i++){
        cin>>l>>r>>l2>>r2;
        cout<<psa[l2][r2]+psa[l-1][r-1]-psa[l-1][r2]-psa[l2][r-1]<<"\n";
    }
    return 0;
}
