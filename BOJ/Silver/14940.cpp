// 쉬운 최단거리 - S1 - 2024/11/04
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int arr[1001][1001];
int ans[1001][1001];
int vis[1001][1001];
int st_x,st_y;
void BFS(int x,int y,int tmp){
    int now = arr[x][y];
    queue<pair<pair<int,int>,int>>q;
    q.push({{x,y},0});
    vis[x][y]=1;
    while(not q.empty()){
        int xx = q.front().first.first;
        int yy = q.front().first.second;
        int ttmp = q.front().second+1;
        vis[xx][yy]=1;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = xx + dx[i];
            int ny= yy + dy[i];
            if(nx<1 or ny<1 or nx>n or ny>m)continue;
            if(vis[nx][ny])continue;
            if(arr[nx][ny]==0)continue;
            vis[nx][ny]=1;
            q.push({{nx,ny},ttmp});
            ans[nx][ny]=ttmp;
        }ttmp++;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1 ;j<=m ;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){st_x=i; st_y=j;}
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1 ;j<=m ;j++){
            ans[i][j]=-1;
        }
    }
    BFS(st_x,st_y,0);
    for(int i=1; i<=n; i++){
        for(int j=1 ;j<=m ;j++){
            if(ans[i][j]==-1 and arr[i][j]==0)ans[i][j]=0;
            if(ans[i][j]==-1 and arr[i][j]==2)ans[i][j]=0;
        }
    }    
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m;j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
}