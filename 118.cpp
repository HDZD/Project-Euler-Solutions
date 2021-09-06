#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

vector<bool> prime(1e8+5,true);

set <set <ull> > good;

void SieveOfEratosthenes(ull n) {
    for (ull p = 2; p*p <= n; p++)
        if (prime[p] == true)
            for (ull i = p * p; i <= n; i += p)
                prime[i] = false;
}

bool isPrime(ull x){
    ull sq = sqrt(x)+3;

    for (ull i = 2;i < sq && i < x;i++)
        if (x%i == 0)
            return false;

    return true;
}

bool p (ull x){
    if (!x || x == 1) return false;
    if (x < 1e8+5) return prime[x];
    return isPrime(x);
}

void check (vector <int> &s,ull i,ull cur,set <ull> taken){
    if (i == s.size() && !cur) good.insert(taken);
    if (i == s.size()) return ;
    
    cur = cur*10 + s[i];

    //add current digit to running number (that should become prime later)
    check(s,i+1,cur,taken);

    //take the current number as a prime and start taking a new number
    if (p(cur)) {
        set <ull> takeextra = taken;
        takeextra.insert(cur);
        check(s,i+1,0,takeextra);
    }
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    SieveOfEratosthenes(1e8+5);
    
    vector <int> s = {1,2,3,4,5,6,7,8,9};

    do
        check(s,0,0,set<ull> ());
    while (next_permutation(s.begin(),s.end()));

    cout << good.size() << endl;

    return 0;
}