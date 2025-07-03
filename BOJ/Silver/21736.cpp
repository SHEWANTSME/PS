// 헌내기는 친구가 필요해 - S2 - 2025.07.03
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n,m;
char arr[601][601];
int x,y;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int vis[601][601];
int ans=0;
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        string s; cin>>s;
        for(int j=0; j<s.size();j++){
            arr[i][j+1] = s[j];
            if(arr[i][j+1] == 'I'){x=i,y=j+1;}
        }
    }
    
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    while(not q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        //vis[xx][yy]=1;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = dx[i]+xx;
            int ny = dy[i]+yy;
            if(nx<1 or ny<1 or nx>n or ny>m) continue;
            if(vis[nx][ny]) continue;
            if(arr[nx][ny]=='X') continue;
            if(arr[nx][ny]=='P') ans++;
            q.push({nx,ny});
            vis[nx][ny]=1;
        }
    }
    if(ans==0)cout<<"TT"<<endl;
    else cout<<ans<<endl;
}