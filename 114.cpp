#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
ull lim = 50;

unordered_map <ull,ull> m;

ull ways(ull i){
    if (i == lim || i == lim+1) return 1;
    if (i > lim+1) return 0;

    if (m.count(i)) return m[i];

    ull res = ways(i+1);
    for (int t = 4;t <= lim;t++)
        res += ways(i+t);

    return m[i] = res;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cout << ways(0) + 1 << endl;
    
    return 0;
}