#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define par first
#define wt second 

void prims(vector<pair<ll,ll>> g[] ,ll n ,ll e ,ll src)
{
    vector<pair<ll,ll>> v(n);
    for(int i = 0;i < n;++i)
    {
        v[i].first = -1;
        v[i].second = 1e18;
    }
    int i = 0;
    int cur = src;
    v[cur].wt = 0;
    map<ll,ll> vis;
    while(i < n - 1)
    {
        ll vtx = 0;
        ll mn = 1e18;
        for(int j = 0;j < n;++j)
        {
            if(vis.find(j) == vis.end())
            {
                if(v[j].wt < mn)
                {
                    mn = v[j].wt;
                    vtx = j;
                }
            }
        }
        cur = vtx;
        vis[cur] = 1;
        for(auto x : g[cur])
        {
            if(v[x.first].wt > x.second && vis.find(x.first) == vis.end())
            {
                v[x.first].wt = x.second;
                v[x.first].par = cur;
            }
        }
        i++;
         
    }
    for(ll i = 1;i < n;++i)
    {
       /// cout << i << " "<< v[i].first<<endl; 
       
            cout << min(i , v[i].first) << " "<< max(i ,v[i].first) << " "<<v[i].second<<endl;
    }
}

int main()
{
  int V, e, tempX, tempY;
  cin >> V >> e;
   //////////// if(V < 56)cout << 1;
    vector<pair<ll,ll>> g[V];

    for(int i = 0;i < e;++i)
    {
        ll x ,y , z;
        cin >> x >> y >> z;
      g[x].push_back({y , z});
    g[y].push_back({x , z});
        
    }

    for(int i = 0; i < V; i++) {
        cout << i << "\t";
        for(int j = 0; j < g[i].size(); j++) {
            cout << g[i][j].first << " ";
             // << " " << g[i][j].second << " ";
        }

        cout << "\n";
    }

    prims(g , V , e , 0);   
    return 0;
}



/*

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define par first
#define wt second 

void prims(vector<pair<int,int>> g[] ,int n ,int e ,int src)
{
    vector<pair<int,int>> v(n);
    for(int i = 0;i < n;++i)
    {
        v[i].first = -1;
        v[i].second = 1e18;
    }
    int i = 0;
    int cur = src;
    v[cur].wt = 0;
    map<int,int> vis;
    while(i < n - 1)
    {
        int vtx = 0;
        int mn = 1e18;
        for(int j = 0;j < n;++j)
        {
            if(vis.find(j) == vis.end())
            {
                if(v[j].wt < mn)
                {
                    mn = v[j].wt;
                    vtx = j;
                }
            }
        }
        cur = vtx;
        vis[cur] = 1;
        for(auto x : g[cur])
        {
            if(vis.find(x.first) == vis.end() && v[x.first].wt > x.second)
            {
                v[x.first].wt = x.second;
                v[x.first].par = cur;
            }
        }
        i++;
         
    }
    for(int i = 1;i < n;++i)
    {
       /// cout << i << " "<< v[i].first<<endl; 
       
            cout << min(i , v[i].first) << " "<< max(i ,v[i].first) << " "<<v[i].second<<endl;
    }
}

int main()
{
  int V, e, tempX, tempY;
  cin >> V >> e;
   //////////// if(V < 56)cout << 1;
    vector<pair<int,int>> g[V];
    for(int i = 0;i < e;++i)
    {
        int x ,y , z;
        cin >> x >> y >> z;
      g[x].push_back({y , z});
    g[y].push_back({x , z});
        
    }
   prims(g , V , e , 0);   
  return 0;
}



*/
