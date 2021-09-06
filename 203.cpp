#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

vector<bool> prime(1e7+5,true);
vector <ull> primes;

void SieveOfEratosthenes(ull n) {
    for (ull p = 2; p*p <= n; p++){
        if (prime[p] == true) {
            for (ull i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for(ull i=2;i<=n;i++){
        if(prime[i])
            primes.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    SieveOfEratosthenes(1e7+5);
    
    unordered_set<ull> s,torem;
    vector<ull> squares;
    ull gen[50];
    for (ull i = 1;i < 51;i++)
        gen[i-1] = i,s.insert(i);

    ull lim = 49;

    while (lim>1){
        for (ull i = 1;i < lim;i++)
            gen[i] += gen[i-1],s.insert(gen[i]);
        lim--;
    }

    for (ull prime : primes)
        squares.push_back(prime*prime);

    for (ull l : s)
        for (ull sq : squares){
            if (sq > l) break;
            if (l % sq == 0){
                torem.insert(l);
                break;
            }
        }

    for (ull t : torem) s.erase(t);

    ull res = 0;

    for (ull l : s) res += l;

    cout << res << endl;
}