#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 5001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int N,Q,d[MAXN][MAXN],v,x1,x2,y1,y2;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>x1>>y1>>x2>>y2>>v;
        d[x1][y1]+=v;
        d[x2][y2]+=v;
        d[x1][y2]-=v;
        d[x2][y1]-=v;
    }
    for(int i = 0; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
             d[i][j] += d[i][j-1];
        }
    }
    for(int i = 1; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
             d[i][j] += d[i-1][j];
        }
    }
    return 0;
}
