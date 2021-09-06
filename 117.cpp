#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
ull lim = 50;

unordered_map <ull,ull> m;

ull ways(ull i){
    if (i == lim) return 1;
    if (i > lim) return 0;

    if (m.count(i)) return m[i];

    return m[i] = ways(i+1) + ways(i+2) + ways(i+3) + ways(i+4);
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cout << ways(0) << endl;
    
    return 0;
}