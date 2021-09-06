#include<bits/stdc++.h>
#define MAXN 1200000
using namespace std;
using ull=unsigned long long;
using ll=long long;

bool found [100000000] = {};
vector<bool> prime(1e8+5,true);
vector <long long> primes;
void SieveOfEratosthenes(long long n) {
    for (long long p = 2; p*p <= n; p++)
        if (prime[p] == true)
            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;
    for(long long i=2;i<=n;i++)
        if(prime[i])
            primes.push_back(i);
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    SieveOfEratosthenes(1e8+5);

    for (ull i = 0;i <  primes.size() && primes[i]*primes[i] < 1e8;i++)
        for (ull j = i;j <  primes.size() && primes[i]*primes[j] < 1e8;j++)
            found [primes[i]*primes[j]] = true;

    ull res = 0;

    for (bool b : found)
        if (b) res++;
    
    cout << res << endl;
    
    return 0;
}