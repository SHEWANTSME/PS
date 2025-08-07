// 그래프 탐색 2 - S1 - 2025.08.07
// 예외가 될만한것들 생각하고 풀어주면 됨. BFS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;
int n,m,q;
vector<int> city[1002];
int vis[1002];
void BFS(int root){
    queue<int>q;
    vis[1]=1;
    q.push(root);
    while(not q.empty()){
        int now = q.front();
        q.pop();
        for(auto &e : city[now]){
            if(vis[e])continue;
            vis[e]=vis[now]+1;
            q.push(e);
        }
    }
    for(int i=1; i<n;i++){
        cout<<vis[i]-1<<" ";
    }
    cout<<vis[n]-1<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        if(a==b)continue;
        city[a].push_back(b);
        city[b].push_back(a);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b; cin>>a>>b;
        vector<int>tmp(n+1);
        if(a==b){
            BFS(1);
            for(int j=1; j<=n;j++)vis[j]=0;
        }
        else{
            city[a].push_back(b);
            city[b].push_back(a);    
            BFS(1);
            for(int j=1; j<=n;j++)vis[j]=0;
        }
    }
}