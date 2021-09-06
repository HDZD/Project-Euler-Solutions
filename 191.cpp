#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

ull lim = 30;
unordered_map<ull,unordered_map<ull,unordered_map<bool,ull>>> dp;
ull gen (ull cur,ull consAbs,bool late){
    if (cur == lim) return 1;

    if (dp[cur][consAbs].count(late)) return dp[cur][consAbs][late];

    ull ret = 0;
    if (!late) ret += gen(cur+1,0,true);
    if (consAbs < 2) ret += gen(cur+1,consAbs+1,late);
    return dp[cur][consAbs][late] = ret + gen(cur+1,0,late);
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cout << gen(0,0,false) << endl;

    return 0;
}