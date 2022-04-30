
#include <bits/stdc++.h>
using namespace std;

void bridge(int curr, int parent, int &t, vector<int> &time, vector<int> &low, vector<int> &vis, vector<int> adj[])
{
    vis[curr] = 1;
    time[curr] = low[curr] = t++;
    for (auto it : adj[curr])
    {
        if(it==parent){continue;}
        if (vis[it] == 0)
        {
            bridge(it, curr, t, time, low, vis, adj);
            low[it] = min(low[it], low[curr]);
            if (low[it] > time[curr])
            {
                cout << curr << " " << it <<endl;
            }
        }
        else
        {
            low[curr] = min(low[curr], time[it]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> vis(n, 0);
    vector<int> time(n, -1);
    vector<int> low(n, -1);
    int t = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            bridge(i, -1, t, time, low, vis, adj);
        }
    }
  return 0;  
}