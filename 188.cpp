#include<bits/stdc++.h>
#define MAXN 1200000
using namespace std;
using ull=unsigned long long;
using ll=long long;
ull mod = 1e8;

ull binpow(ull a, ull b, ull m) {
    a %= m;
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ull up(ull a,ull b){
    if (b == 1) return a;

    return binpow(a,up(a,b-1),mod);
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cout << up(1777,1855) << endl;
    
    return 0;
}