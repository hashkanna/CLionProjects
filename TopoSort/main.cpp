#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
int timer=0;
bool cycle=false;
vector<int> colors;
vector<int> parents;
vector<int> tin;
vector<int> tout;

void dfs(int u, int p) {
    tin[u]=timer;
    timer+=1;
    colors[u]=1;
    parents[u]=p;
    for (auto v: g[u]) {
        if (colors[v]==1) {
            cycle=true;
            return;
        }
        if (colors[v]==0)
            dfs(v,u);
    }
    colors[u]=2;
    tout[u]=timer;
    timer+=1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    g.resize(n);
    for (int i=0; i<m; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
//        x--, y--;
        g[x].push_back(y);
//        g[y].push_back(x);
    }
    visited.resize(n, false);
    colors.resize(n,0);
    tin.resize(n,-1);
    tout.resize(n,-1);
    parents.resize(n,-1);

    for (int i=0; i<n; i++) {
        if (colors[i]==0) {
            dfs(i, i);
            if (cycle)
                break;
        }
    }

    if (cycle) {
        cout << "NO";
    } else {
        cout << "YES" << "\n";
        vector<pair<int,int> >V;
        for(int i=0;i<n;i++){
            pair<int,int>P=make_pair(tout[i],i);
            V.push_back(P);
        }
        sort(V.begin(),V.end());
        reverse(V.begin(),V.end());
        for(auto v: V)cout<<v.second<<" ";
    }
}