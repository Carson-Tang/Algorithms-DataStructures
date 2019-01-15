#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define INFINITE 0x3f3f3f3f
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int>ii;
int n,q,bs,arr[100001],cmd,l,r,u,x; ll block[317],ans;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    // blocks storing sum 
    cin>>n>>q;
    // block size
    bs = sqrt(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        block[i/bs]+=arr[i];
    }
    while(q--){
        cin>>cmd;
        // 1 - query sum of arr[l-r]
        // 2 - update arr[u] to x
        if(cmd==1){
            cin>>l>>r;
            ans = 0;
            // start block - end block
            int sb = (l+bs-1)/bs, eb = r/bs;
            for(int i = sb; i < eb; i++) ans+=block[i];
            for(int i = l; i < sb*bs; i++) ans+=arr[i];
            for(int i = eb*bs; i < r; i++) ans+=arr[i];
            cout<<ans<<"\n";
        } else {
            cin>>u>>x;
            block[u/bs]-=arr[u];
            arr[u]=x;
            block[u/bs]+=arr[u];
        }
    }
    return 0;
}
