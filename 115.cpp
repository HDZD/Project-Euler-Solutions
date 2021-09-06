#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

unordered_map <ull,ull> ma;

ull ways(ull i,ull m,ull n){
    if (i == n || i == n+1) return 1;
    if (i > n+1) return 0;

    if (ma.count(i)) return ma[i];

    ull res = ways(i+1,m,n);
    for (int t = m+1;t <= n;t++)
        res += ways(i+t,m,n);

    return ma[i] = res;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cout << ways(0,50,168) + 1 << endl;
    //Binary searched this by hand lol
    //ans = 168
    
    return 0;
}