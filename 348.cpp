#include<bits/stdc++.h>
#define MAXN 1200000
using namespace std;
using ull=unsigned long long;
using ll=long long;

ull lim = 1e4;
map<ull,ull> ways;

bool pal(ull x){
    string s = to_string(x);

    for (int i = 0;i < s.size()/2;i++)
        if (s[i] != s[s.size()-1-i])
            return false;
    
    return true;
}

void check (ull x){
    if (pal(x))
        ways[x]++;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    for (ull x = 1;x < lim*10;x++)
        for (ull y = 1;y < lim;y++)
            check (x*x+y*y*y);

    int  i = 0;
    ull res = 0;
    for (auto it : ways){
        if (i == 5) break;
        if (it.second == 4)
            res += it.first,i++;
    }

    cout << res << endl;

    return 0;
}