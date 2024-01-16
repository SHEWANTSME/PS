//알고리즘 수업 - 너비 우선 탐색 3 - S2 - 2024/01/16
// find the depth of each node
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n,m,r;
vector<int>arr[100001];
int vis[100001];
int main(){
    fastio;
    cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        arr[u].push_back(v);arr[v].push_back(u);
    }
    queue<int>q;
    q.push(r);
    vis[r]=1;
    while(not q.empty()){
        int now = q.front();q.pop();
        for(auto &e:arr[now]){
            if(vis[e]>=1)continue;
            vis[e]=vis[now]+1;
            q.push(e);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<vis[i]-1<<"\n";
}
/*
1 - 4
  \ | \ 
    2 -3
*/