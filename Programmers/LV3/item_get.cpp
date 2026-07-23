#include <string>
#include<queue>
#include <vector>
#include<iostream>
//#include<cstring>

using namespace std;

int arr[205][205];
int vis[205][205];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int upgrade(int v){// 0=EMPTY, 1=BORDER, 2=CORNER, 3=BLOCK
    if(v==3)return 3;
    if(v==0)return 1;
    return 2;
} 

void make_polygon(vector<vector<int>> rect){
    for(auto &r : rect){ r[0]*=2; r[1]*=2; r[2]*=2; r[3]*=2; }
    for(auto &r : rect){
        int x1=r[0], y1=r[1], x2=r[2], y2=r[3];
        for(int y=y1+1; y<y2; y++){
            arr[x1][y] = upgrade(arr[x1][y]);
            arr[x2][y] = upgrade(arr[x2][y]);
            arr[x1+1][y] = 3;
            arr[x2-1][y] = 3;
        }

        for(int x=x1+1; x<x2; x++){
            arr[x][y1] = upgrade(arr[x][y1]);
            arr[x][y2] = upgrade(arr[x][y2]);
            arr[x][y1+1] = 3;
            arr[x][y2-1] = 3;
        }
        arr[x1][y1]=2; arr[x1][y2]=2; arr[x2][y1]=2; arr[x2][y2]=2;
    }
}

void BFS(int cx, int cy, int ix, int iy){
    queue<pair<int,int>>q;
    q.push({cx,cy});
    vis[cx][cy]=1;
    
    while(not q.empty()){
        int ax =q.front().first;
        int ay = q.front().second;
        if(ax==ix and ay == iy)break;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = ax+dx[i];
            int ny= ay+dy[i];
            if(nx<0 or ny<0 or nx>200 or ny>200)continue;
            if(vis[nx][ny]>=1)continue;
            if(arr[nx][ny]==1 or arr[nx][ny]==2){
                vis[nx][ny]=vis[ax][ay]+1;
                q.push({nx,ny});
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int cx, int cy, int ix, int iy) {
    make_polygon(rectangle);
    cx*=2; cy*=2; ix*=2; iy*=2;
    BFS(cx,cy,ix,iy);
    int ans = vis[ix][iy] / 2;
    //cout<<ans<<endl;
    return ans;

}