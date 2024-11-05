//현명한 나이트 - S1 - 2024/11/05
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fastio cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;
int n,m;
int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};
int kn_x,kn_y;
int main(){
    cin>>n>>m;
    vector<vector<int>> arr(n+1,vector <int>(n+1,0));
    vector<vector<int>> vis(n+1,vector <int>(n+1,0));
    cin>>kn_x>>kn_y;
    arr[kn_x][kn_y]=-1;
    vis[kn_x][kn_y]=1;
    queue<pair<pair<int,int>,int>>q;
    q.push({{kn_x,kn_y},1});
    int tmp=1;
    while(not q.empty()){
        int xx = q.front().first.first;
        int yy = q.front().first.second;
        int ttmp = q.front().second+1;
        vis[xx][yy]=1;
        q.pop();
        for(int i=0; i<8; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx<1 or ny<1 or nx>=n+1 or ny>=n+1)continue;
            if(vis[nx][ny])continue;
            if(arr[nx][ny]==-1)continue;
            vis[nx][ny]=1;
            q.push({{nx,ny},ttmp});
            arr[nx][ny]=ttmp;
        }ttmp++;
    }
    vector<int>ans;
    while(m--){
        int x,y;cin>>x>>y;
        if(arr[x][y]==-1)ans.push_back(0);
        else ans.push_back(arr[x][y]);
    }
    for(auto &e : ans){
        cout<<e-1<<" ";
    }
}