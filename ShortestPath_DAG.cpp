
#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

void topo(int curr, stack<int> &st, vector<pair<int, int>> adj[], vector<int> vis)
{
    vis[curr] = 1;
    for (auto it : adj[curr])
    {
        if (vis[it.first] == 0)
        {
            topo(it.first, st, adj, vis);
        }
    }
    st.push(curr);
}

void Path(int src, int n, vector<pair<int, int>> adj[])
{
    stack<int> st;
    vector<int> vis(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            topo(src, st, adj, vis);
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (dist[curr] != INT_MAX)
        {
            for (auto it : adj[curr])
            {
                if (dist[curr] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[curr] + it.second;
                }
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        dist[i] == INT_MAX ? cout << "Unreachable" : cout << dist[i];
        cout<<" ";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    Path(0, n, adj);
    return 0;
}
