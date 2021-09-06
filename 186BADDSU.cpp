#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

vector <ull> dp = vector <ull> (2e8,-1);

ull LFG (ull k) {
    if (k <= 55)
        return dp[k] = ((100003 - (200003 * k) + (300007*k*k*k)) % 1000000);

    if (dp[k] != -1) return dp[k];

    return dp[k] = (dp[k-24] + dp[k-55]) % 1000000;
}

ull par[1000001];
ull siz[1000001];
 
ull find(ull x) {
    while(par[x] != -1 && par[x] != x) x=par[x];
    return x;
}
 
bool same(ull x,ull y) {
    return find(x)==find(y);
}
   
void unite(ull a,ull b) {
    a=find(a);
    b=find(b);
    if(siz[a]>siz[b]) swap(a,b);
    par[b]=a;
    siz[a]+=siz[b];
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    for (int i = 0;i<1e6+1;i++) par[i] = -1,siz[i]=1;
    
    ull res = 0;
    for (ull x = 1;x < 1e6;x++){
        ull caller = LFG(2*x-1);
        ull called = LFG(2*x);

        if (caller == called)
            continue;

        unite (caller,called);
    }

    // cout << siz [200007] << ' ' << siz [find(200007)] << endl;

    ull ma = 0;
    for (ull l : siz)
        ma = max (ma,l);

    cout << ma << endl;

    //target sz = 990000;
    return 0;
}