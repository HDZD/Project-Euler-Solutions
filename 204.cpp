#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

vector<bool> prime(101,true);
vector <long long> primes;
set <ull> r;
void SieveOfEratosthenes(long long n) {
    for (long long p = 2; p*p <= n; p++){
        if (prime[p] == true) {
            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for(long long i=2;i<=n;i++){
        if(prime[i])
            primes.push_back(i);
    }
}

void gen(int i,ull s){
    if (i == primes.size() || s > 1e9) return;
    r.insert(s);
    gen(i,s * primes[i]);
    gen(i+1,s);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    SieveOfEratosthenes(100);

    gen (0,1);

    int i = 0;
    for (ull l : r){
        if (i == 50) break;
        cout << l << ' ';
        i++;
    }

    cout << r.size() << endl;
}