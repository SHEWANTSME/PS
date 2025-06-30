//공주님을 구해라! - G5 - 2025.06.30
// 조건 들어간 BFS -> 검 get하면 manhattan distance 추가해서 거리계산 하면 됨
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,t;
int arr[101][101];
int vis[101][101];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
queue<pair<int,int>>q;
vector<pair<int,int>>v;
int main(){
    cin>>n>>m>>t;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m;j++)
            cin>>arr[i][j];
    vis[1][1]=1;
    q.push({1,1});
    while(not q.empty()){
        auto now = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int xx = now.first+dx[i];
            int yy = now.second+dy[i];
            if(xx<1 or yy<1 or xx>n or yy>m)continue;
            if(arr[xx][yy]==1)continue;
            if(vis[xx][yy]>=1)continue;
            q.push({xx,yy});
            vis[xx][yy]=vis[now.first][now.second]+1;
            if(arr[xx][yy]==2){
                v.push_back({xx,yy});continue;
            }
        }
    }    
    if(not v.empty()){
        int tt = v[0].first;
        int qq = v[0].second;
        int x = n - tt + m - qq + vis[tt][qq]-1;
        int y = vis[n][m]-1;
        if(y<0) {
            if(x<=t){cout<<x<<endl;exit(0);}
            else {cout<<"Fail"<<endl;exit(0);}
        }
        if(min(x,y)<=t and y>=0) {cout<<min(x,y)<<endl; exit(0);}
        if(min(x,y)>t){cout<<"Fail"<<endl;exit(0);}
    }
    if(vis[n][m]==0){cout<<"Fail"<<endl;exit(0);}
    if(v.empty()){
        if(vis[n][m]-1<=t) {cout<<vis[n][m]-1<<endl;exit(0);}
        else cout<<"Fail"<<endl;
    }
    
}