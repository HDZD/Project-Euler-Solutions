#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

ull gets(vector <ull> &v,ull mask){
    ull s = 0;

    for (ull i = 0;i < v.size();i++)
        s += (mask & (1LL << i)) ? v[i] : 0;

    return s;
}

bool check (vector <ull> &v){
    map<ull,ull> found;
    ull p2 = 1 << v.size();

    for (ull i = 1;i < p2;i++){
        ull s = gets(v,i);
        if (found[s]) return false;
        found[s] = i;
    }

    auto it = found.begin();

    while (it != found.end()){
        auto it2 = it;
        it2++;
        if (it2 == found.end()) break;
        ull count1 = __builtin_popcount(it->second);
        ull count2 = __builtin_popcount(it2->second);
        if (count1 > count2) return false;
        it++;
    }

    return true;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    for (ull a = 20;a < 21;a++)
        for (ull b = a+1;b < 32;b++)
            for (ull c = b+1;c < 39;c++)
                for (ull d = c+1;d < 40;d++)
                    for (ull e = d+1;e < 41;e++)
                        for (ull f = e+1;f < 43;f++)
                            for (ull g = f+1;g < 46;g++){
                                vector <ull> v = {a,b,c,d,e,f,g};
                                if (check(v))
                                    for(ull l : v) cout << l;
                            }

    return 0;
}