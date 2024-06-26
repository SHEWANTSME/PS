//상범 빌딩 - G5 - 2024/06/26
// 3차원 기본 BFS 
#include<iostream>
#include<algorithm>
#include<queue>
#define endl '\n'
using namespace std;
char building[31][31][31];
int vis[31][31][31];
int z,x,y;
int dx[6] = {0,1,-1,0,0,0};// for x방향
int dy[6] = {1,0,0,-1,0,0};// for y방향
int dz[6] = {0,0,0,0,1,-1};// for z방향
int main(){
    while(1){
        cin>>z>>x>>y;
        if(z==0 and x==0 and y==0) break;
        int sx,sy,sz;
        for(int k=0;k<z;k++){
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    cin>>building[k][i][j];
                    if(building[k][i][j]=='S'){
                        sx = i; sy = j; sz = k;
                    }
                }
            }
            //cout<<endl; -> 이게 없어야 되던데.? -> cin은 개행문자를 무시함 그래서 안함
        }
        queue<pair<int,pair<int,int>>>q;// for z,x,y
        q.push({sz,{sx,sy}});
        vis[sz][sx][sy]=1;
        bool flag = 0;
        int ans = 0;
        while(not q.empty()){
            auto tt = q.front();
            int zz = tt.first;
            int xx = tt.second.first;
            int yy = tt.second.second;
            q.pop();
            for(int i=0;i<6;i++){
                int nx = xx + dx[i];
                int ny = yy + dy[i];
                int nz = zz + dz[i];
                if(nx>=0 and ny>=0 and nz>=0 and nx<x and ny<y and nz<z and not vis[nz][nx][ny] and building[nz][nx][ny]!='#'){
                    if(building[nz][nx][ny]=='E'){
                        flag =1;ans = vis[zz][xx][yy];break;
                    }
                    vis[nz][nx][ny] = vis[zz][xx][yy]+1;
                    q.push({nz,{nx,ny}});
                }
            }
        }
        if(flag){cout<<"Escaped in "<<ans<<" minute(s)."<<endl;}
        else cout<<"Trapped!"<<endl;
        for(int k=0;k<z;k++){
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    vis[k][i][j]=0;
                }
            }
        }


    }

}