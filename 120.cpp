#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ull rmax(ull x){
    ull sq = x*x;
    ull ma = 0;

    for (ull n = 1;n <= 2*x;n++)
        ma = max(ma,(binpow(x-1,n,sq) + binpow(x+1,n,sq))%sq);
    
    return ma;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    ull res = 0,i = 3;

    for (;i<1001;i++)
        res += rmax(i);

    cout << res << endl;

    return 0;
}