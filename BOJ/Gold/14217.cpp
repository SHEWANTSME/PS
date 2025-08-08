// 그래프 탐색 - G5 - 2025.08.08
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;
int n,m,q;
vector<int> city[502];
vector<int> city2[502];
int vis[502];
int vis2[502];
void BFS(int root){
    queue<int>q;
    vis[1]=1;
    q.push(root);
    while(not q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto &e : city[now]){
            if(vis[e])continue;
            if(find(city2[e].begin(), city2[e].end(), now) != city2[e].end()){continue;} // city2[e]에 now가 있다면
            //if(city2[e].find(now) != city2[e].end()){continue;} // city2[e]에 now가 있다면

            //if(city2[e].size()>0){vis[e]=0;continue;}
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
        int x,a,b; cin>>x>>a>>b;
        vector<int>tmp(n+1);
        if(x==1){
            if(find(city2[a].begin(),city2[a].end(),b)!=city2[a].end()){// 이미 city2에서 a와 b가 연결되어 있다면
                city2[a].erase(find(city2[a].begin(), city2[a].end(), b));
                city2[b].erase(find(city2[b].begin(), city2[b].end(), a));
            }
            city[a].push_back(b);
            city[b].push_back(a);
            BFS(1);
            for(int j=1; j<=n;j++)vis[j]=0;
        }
        if(x==2){
            city2[a].push_back(b);
            city2[b].push_back(a);
            BFS(1);
            for(int j=1; j<=n;j++)vis[j]=0;
        }

    }
}