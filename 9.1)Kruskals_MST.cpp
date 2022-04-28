
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int u,v,wt;
    node(int first, int second, int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int n, vector<int>& parent)
{
    if(n==parent[n])
    {
        return n;
        }
   return parent[n] = findPar(parent[n],parent); 
}

void Union(int u, int v, vector<int>& parent, vector<int>& rank)
{
    u=findPar(u,parent);
    v=findPar(v,parent);
    if(rank[u] < rank[v])
    {
        parent[u]=v;
    }
    else if(rank[u] > rank[v])
    {
        parent[v]=u; 
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}

int main()
{
    int n=5,m=6;
	vector<node> edges;
    vector<int> parent(n);
    vector<int> rank(n,0);

    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }

     
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(), edges.end(), comp); 

    int ans=0;

    vector<pair<int,int>> mst;
    for(auto it:edges)
    {
        if(findPar(it.u,parent)!=findPar(it.v,parent))
        {
             ans+=it.wt;
             mst.push_back({it.u,it.v}); 
             Union(it.u,it.v,parent,rank);
        }
    }
   cout<<"Total cost is "<<ans<<endl;
   for(auto it:mst)
   {
       cout<<it.first<<" - "<<it.second;
       cout<<endl;
   }
  return 0; 
}
