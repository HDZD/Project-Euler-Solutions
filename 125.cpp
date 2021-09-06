#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

ull lim = 1e8;
ull ilim = sqrt(lim);
set<ull> good;
unordered_map<ull,unordered_map<ull,bool>> seen;

bool isPal(ull x){
    if (x == 0 || x == 1) return false;
    string s = to_string(x);
    for (int i = 0;i < s.size()/2;i++)
        if (s[i] != s[s.size()-1-i]) return false;
    return true;
}

void gen(ull i,ull x){
    if (x > lim || i > ilim) return;
    if (seen[i][x]) return ;

    seen[i][x] = true;
    if (isPal(x))
        good.insert(x);

    gen(i+1,x+(i*i));
    gen(i+1,i*i);
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    gen(0,0);

    for (ull i = 0;i < ilim;i++)
        good.erase(i*i);

    ull res = 0;
    for (ull l : good)
        res += l;

    cout << res << endl;
    
    return 0;
}