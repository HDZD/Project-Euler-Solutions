#include<bits/stdc++.h>
#define i128 __int128_t
using namespace std;
using ull=unsigned long long;
using ll=long long;

vector<bool> prime(1000001,true);
vector <ull> primes;
void SieveOfEratosthenes(ull n) {
    for (ull p = 2; p*p <= n; p++){
        if (prime[p] == true) {
            for (ull i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for(ull i=2;i<=n;i++)
        if(prime[i])
            primes.push_back(i);
}

i128 binpow(i128 a, i128 b, i128 m) {
    a %= m;
    i128 res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    SieveOfEratosthenes(1000001);
    
    for (i128 i = 0;i < primes.size();i++){
        i128 n = i+1;
        i128 p = primes[i];
        i128 mod = p*p;

        i128 calc = (binpow(p-1,n,mod) + binpow(p+1,n,mod))%mod;
        
        if (calc >= 1e10){
            cout << (ull)n << endl;
            break;
        }
    }
    
    return 0;
}