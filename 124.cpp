#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

#define MAXN 100001 
 
int spf[MAXN]; 

void sieve() { 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 

    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 

                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

ull rad(ull x) {
    unordered_set<ull> s;
    ull r = 1;
    while (x != 1) { 
        s.insert(spf[x]);
        x = x / spf[x]; 
    }
    for (ull l : s)
        r *= l;
    return r;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    sieve();

    vector<vector<ull>> v;

    for (ull x = 1;x <= 100000;x++){
        v.push_back({rad(x),x});
    }

    sort(v.begin(),v.end());

    cout << v[10000-1][1] << endl;
    
    return 0;
}