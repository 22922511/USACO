#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int>par;
vector<vector<int>>adj;
int n;
void dfs(int nod,int pa){
     par[nod]=pa;
    
     for(auto id :adj[nod]){
        if(par[id]==0){
            dfs(id,3-pa);
        }
    }
}
signed  main()
{
     cin>>n;
     adj.resize(n+1);
     par.assign(n+1,0);
     for(int i=0;i<n-1;i++){
         int a,b;
         cin>>a>>b;
         adj[a].push_back(b);
         adj[b].push_back(a);
     }
     dfs(1,1);
     int c=0,uc=0;
     
     for(int i=1;i<=n;i++){
         int id=par[i];
         if(id==1) c++;
         if(id==2) uc++;
     }
     cout<<c*uc-n+1<<"\n";
     return 0;
}
