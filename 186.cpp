#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

vector <ull> dp = vector <ull> (2e8,-1);

ull LFG (ull k) {
    if (k <= 55)
        return dp[k] = ((100003 - (200003 * k) + (300007*k*k*k)) % 1000000);

    if (dp[k] != -1) return dp[k];

    return dp[k] = (dp[k-24] + dp[k-55]) % 1000000;
}

unordered_map<ull,unordered_set<ull>> g;

//This DFS will overflow the stack so we need iterattive one
// ull dfs(ull x){
//     if (visited[x]) return 0;
//     visited[x] = true;
//     ull t = 1;
//     for (ull adj : g[x])
//         t += dfs(adj);
//     return t;
// }

ull dfs (ull x){
    vector <bool> visited(1e6+1,false);

    ull r = 0;
    stack <ull> s;
    s.push(x);

    while (!s.empty()){
        ull top = s.top();
        s.pop();
        if (visited[top]) continue;
        visited[top] = true;
        for (ull adj : g[top])
            s.push(adj);
        r++;
    }

    return r;
}

ull check (ull lim){
    g.clear();

    cout << "Trying " << lim << endl;

    ull res = 0;
    lim = min(lim,(ull)1e8);

    cout << "Direct PM connections found: ";
    for (ull x = 1;x < lim;x++){
        ull caller = LFG(2*x-1);
        ull called = LFG(2*x);

        if (caller == 524287 || called == 524287)
            cout << x << ' ';

        if (caller == called)
            continue;
        
        g[caller].insert(called);
        g[called].insert(caller);
        res++;
    }
    cout << endl << "Construction Done" << endl;

    ull connected = dfs(524287);

    cout << "Total PM Connections: " << connected << " | Number of valid calls: " << res << endl << endl;

    return connected;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    ull l = 1e6,r = 1e7;

    while (l < r){
        ull mid = (l+r)/2;
        if (check(mid) >= 990000)
            r = mid;
        else
            l = mid + 1;
    }
    
    return 0;
}