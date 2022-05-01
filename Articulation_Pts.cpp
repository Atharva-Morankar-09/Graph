
#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, int parent, int& time, vector<int>& vis, vector<int>& tin, vector<int>& lin, vector<int>& pts, vector<int> adj[])
{
    vis[curr]=1;
    tin[curr]=lin[curr]=time++;
    int child=0;

    for(auto it:adj[curr])
    {
        if(it==parent){continue;}

        if(vis[it]==0)
        {
            dfs(it,curr,time,vis,tin,lin,pts,adj);
            lin[curr]=min(lin[curr],lin[it]);
            child++;
            if(lin[it]>=tin[curr] && parent!=-1)
            {
                // pts[curr]=1;
                cout<<curr<<" ";
            }
        }
        else
        {
            lin[curr]=min(lin[curr],tin[it]);
        }
    }

    if(parent==-1 && child>1)
    {
        // pts[curr]=1;
        cout<<curr<<" ";
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    vector<int> vis(n,0);
    vector<int> tin(n,-1);
    vector<int> lin(n,-1);
    vector<int> pts(n,0);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int time=0; 

    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,-1,time,vis,tin,lin,pts,adj);
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     if(pts[i]==1)
    //     {
    //         cout<<i<<" ";
    //     }
    // }    
    return 0;
}