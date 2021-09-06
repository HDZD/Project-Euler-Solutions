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

vector <ull> split(string s){
    vector <ull> ret;
    string t;

    for (char c : s)
        if (c == ' ')
            ret.push_back(stoull(t)),t.clear();
        else
            t += c;

    ret.push_back(stoull(t));
    return ret;
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

    freopen("sets.txt","r",stdin);

    ull res = 0;
    for (int i = 0;i < 100;i++){
        string s;
        getline(cin,s);
        vector <ull> v = split(s);
        if (check(v))
            for (ull l : v) res += l;
    }

    cout << res << endl;

    return 0;
}