#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
ull lim = 50;

unordered_map<ull,ull> r,g,b;

ull red(ull i){
    if (i == lim) return 1;
    if (i > lim) return 0;

    if (r.count(i)) return r[i];

    return r[i] = red(i+2) + red(i+1);
}

ull green(ull i){
    if (i == lim) return 1;
    if (i > lim) return 0;

    if (g.count(i)) return g[i];

    return g[i] = green(i+3) + green(i+1);
}

ull blue(ull i){
    if (i == lim) return 1;
    if (i > lim) return 0;

    if (b.count(i)) return b[i];

    return b[i] = blue(i+4) + blue(i+1);
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cout << red (0) + green(0) + blue(0) - 3 << endl;
    
    return 0;
}