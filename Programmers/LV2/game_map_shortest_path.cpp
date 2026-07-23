#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
void BFS(vector<vector<int>>&vis, vector<vector<int>>maps){
    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0][0]=1;
    while(not q.empty()){
        int ax=q.front().first;
        int ay=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = ax+dx[i];
            int ny = ay+dy[i];
            if(nx<0 or ny<0 or nx>=maps.size() or ny>=maps[0].size())continue;
            if(vis[nx][ny]>=1)continue;
            if(maps[nx][ny]==0)continue;
            vis[nx][ny]= vis[ax][ay]+1;
            q.push({nx,ny});
        }
    }
    //cout<<vis[maps.size()-1][maps.size()-1]<<endl;
}

int solution(vector<vector<int> > maps){
    vector<vector<int>>vis(maps.size(), vector<int>(maps[0].size(),0));
    BFS(vis,maps);
    //cout<<vis[maps.size()-1][maps.size()-1]<<endl;
    if(vis[maps.size()-1][maps[0].size()-1]==0) return -1;
    else return vis[maps.size()-1][maps[0].size()-1];
    
}