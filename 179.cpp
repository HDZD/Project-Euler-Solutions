#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
ull MAXN = 1e7+5;

int spf[10000005]; 

void sieve() 
{ 
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

ull divCount(int x) 
{ 
    ull ret=1;
    unordered_map<ull,ull> m;
    while (x != 1)
    {
        m[spf[x]]++; 
        x = x / spf[x]; 
    }
    for (auto it : m)
        ret *= it.second+1;
    return ret; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    sieve();
    ull res = 0;
    ull prev = divCount(2),now;
    for (ull i = 3;i <= 1e7;i++){
        now = divCount(i);
        if (now == prev) res ++;
        prev = now;
    }

    cout << res << endl;
    return 0;
}