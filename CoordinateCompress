#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
unordered_map<int,int>compress;
int N,v;
vector<int>values;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0; i < N; i++){
       cin>>v;
       values.push_back(v); 
    }
    sort(values.begin(),values.end());
    values.erase(unique(values.begin(),values.end()),values.end());
    int val = 0;
    for(int x : values){
        compress[x]=val++;
    }
    return 0;
}
