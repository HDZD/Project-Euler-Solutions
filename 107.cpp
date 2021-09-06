#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
#define V 40

bool isValidEdge(int u, int v, vector<bool> inMST)
{
   if (u == v)
       return false;
   if (inMST[u] == false && inMST[v] == false)
        return false;
   else if (inMST[u] == true && inMST[v] == true)
        return false;
   return true;
}
  
int primMST(int cost[][V])
{  
    vector<bool> inMST(V, false);
  
    // Include first vertex in MST
    inMST[0] = true;
  
    // Keep adding edges while number of included
    // edges does not become V-1.
    int edge_count = 0, mincost = 0;
    while (edge_count < V - 1) {
  
        // Find minimum weight valid edge.  
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {               
                if (cost[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            printf("Edge %d:(%d, %d) cost: %d \n", 
                         edge_count++, a, b, min);
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    printf("\n Minimum cost= %d \n", mincost);
    return mincost;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("matrix.txt","r",stdin);

    int g[40][40];
    for (int i = 0;i < 40;i++){
        for (int j = 0;j < 40;j++){
            cin >> g[i][j];
            if (!g[i][j]) g[i][j] = INT_MAX;
        }
    }

    ll total = 0;
    for (int i = 0;i < 40;i++){
        for (int j = 0;j < 40;j++){
            if (g[i][j] != INT_MAX) total+= g[i][j];
        }
    }
    total /= 2;
    cout << total << endl;
    cout << total - primMST(g) << endl;
}