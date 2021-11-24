#include "bits/stdc++.h" 
using namespace std; 

#define MAXN 10000001 
 
int spf[MAXN]; 

map <vector<int>,int> m;

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

void check(int x) {
    int num = x;
    set<int> s;

    while (x != 1) { 
        s.insert(spf[x]); 
        x = x / spf[x];
        if (s.size() > 2)
            return;
    }

    if (s.size() != 2)
        return;

    m[{(*s.begin()),*(++s.begin())}] = max(m[{(*s.begin()),*(++s.begin())}],num);
}

int main() { 
    sieve();

    for (int i = 2;i < 1e7+1;i++)
        check(i);

    unsigned long long res = 0;
    for (auto it : m)
        res += it.second;
    
    cout << res << endl;
    return 0; 
} 