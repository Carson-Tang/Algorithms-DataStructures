#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 50001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int N,Q,l,r,st[16][MAXN],x;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i = 1; i <= N; i++){
        cin>>st[0][i];
    }
    for(int k = 1; k < 16; k++){
        for(int i = 1; i + (1<<k)-1 <= N; i++){
            st[k][i] = max(st[k-1][i],st[k-1][i+(1<<(k-1))]);
        }
    }
    for(int i = 1; i <= Q; i++){
        cin>>l>>r;
        x = (int)log2(r-l+1);
        cout << max(st[x][l],st[x][r-(1<<x)+1])<<"\n";
    }
    return 0;
}
