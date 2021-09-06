#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

vector<bool> prime(1e8,true);
set <ull> primes;

void SieveOfEratosthenes(long long n) {
    for (long long p = 2; p*p <= n; p++)
        if (prime[p] == true) 
            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;

    for(long long i=2;i<=n;i++)
        if(prime[i])
            primes.insert(i);
}

bool check (ull x){
    ull lim = sqrt(x)+3;

    for (ull i = 2;i < lim;i++)
        if (x%i==0)
            if (!prime[i+(x/i)])
                return false;

    return true;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    SieveOfEratosthenes(1e8);

    ull res = 0;
    for (ull p : primes)
        if (check(p-1))
            res += p-1;

    cout << res << endl;

    return 0;
}