#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

bool bouncy(ull x){
    string s = to_string(x);

    if (s.size() < 2) return false;
    
    bool up = false,down = false;
    for (int i = 1;i < s.size();i++){
        int dif = s[i] - s[i-1];
        if (dif == 0) continue;
        if (dif > 0) up = true;
        if (dif < 0) down = true;
        if (up && down) return true;
    }
    
    return false;
}

int main () {
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(false);

    ull bounce = 0,notb = 0;

    for (ull i = 1;1;i++){
        // cout << i << ' ' << bouncy(i) << endl;
        if (bouncy(i)) bounce++;
        else notb++;
        long double perc = ((long double) bounce)/ i * 100;
        if (perc >= 99) {
            cout << bounce << ' ' << notb << ' ' << perc << endl;
            cout << i << endl;
            break;
        }
    }

    return 0;
}