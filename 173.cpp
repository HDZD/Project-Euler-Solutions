#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
ull lim = 100;

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    vector <ull> v;

    ull res = 0;

    for (ull i = 8;i <= lim;i += 4)
        v.push_back(i);

    for (ull i = 0;i < v.size();i++){
        ull sum = 0;
        for (ull j = i;j < v.size() && sum + v[j] <= lim;j+=2)
            res++,sum += v[j];
    }

    cout << res << endl;
    
    return 0;
}