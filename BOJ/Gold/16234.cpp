// 인구이동 - G4 - 2024/11/01
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, l ,r ;
int init_arr[101][101];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[4]={2,0,-2,0};
int ddy[4]={0,2,0,-2};
int ccnt =0;
void BFS(int x, int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    int cnt =1;
    int add =init_arr[x][y];
    vector<pair<int,int>>tmp;
    tmp.push_back({x,y});
    while(not q.empty()){
        int xx =q.front().first;
        int yy = q.front().second;
        int now = init_arr[xx][yy];
        vis[xx][yy]=1;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = xx+dx[i];
            int ny = yy+dy[i];
            int nnx = xx+ddx[i];
            int nny = yy+ddy[i];
            if(nx<1 or ny<1 or nx>=2*n or ny>=2*n)continue;
            if(init_arr[nx][ny]==1000)continue;
            if(vis[nnx][nny])continue;
            if(init_arr[nx][ny]==-1){
                q.push({nnx,nny});
                vis[nnx][nny]=1;
                cnt++;
                add+=init_arr[nnx][nny];
                tmp.push_back({nnx,nny});
            }
        }
    }
    int ret = add/cnt;
    if(ret==add){vis[x][y]=0;}
    if(ret !=add){
        for(auto &e: tmp){
            int tx=e.first;
            int ty=e.second;
            init_arr[tx][ty]=ret;
            for(int i=0;i<4;i++){
                int ttx = tx+dx[i];
                int tty = ty+dy[i];
                if(ttx<1 or tty<1 or ttx>=2*n or tty>=2*n)continue;
                if(init_arr[ttx][tty]==1000)continue;
                init_arr[ttx][tty]=1000;
            }
        }
    }
}
int main(){
    cin>>n>>l>>r;
    if(n==1){
        int k;cin>>k;cout<<0<<endl;exit(0);
    }
    for(int i=1;i<=2*n-1; i++){
        for(int j=1; j<=2*n-1; j++){
            if(i%2==1 and j%2==1)cin>>init_arr[i][j];
            if((i%2==0 and j%2==1) or (i%2==1 and j%2==0))init_arr[i][j]=1000;
            if(i%2==0 and j%2==0)init_arr[i][j] = 10000;
        }
    }
    while(1){
        bool chk=0;
        for(int i=1;i<=2*n-1; i++){
            for(int j=1; j<=2*n-1; j++){
                if((i%2==0 and j%2==1) or (i%2==1 and j%2==0)){
                    vector<pair<int,int>>tmp;
                    for(int k=0;k<4;k++){
                        int nx = i+dx[k];
                        int ny = j + dy[k];
                        if(nx<1 or ny<1 or nx>=2*n or ny>=2*n)continue;
                        if(init_arr[nx][ny]==10000)continue;
                        tmp.push_back({nx,ny});
                    }
                    int alpha = init_arr[tmp[0].first][tmp[0].second];
                    int beta = init_arr[tmp[1].first][tmp[1].second];
                    int dist = abs(alpha-beta);
                    if(dist>=l and dist<=r){
                        init_arr[i][j]= -1;
                        chk=1;
                    }
                }
            }
        }
        ccnt++;
        if(chk==0)break;   
        for(int i=1;i<=2*n-1; i++){
            for(int j=1; j<=2*n-1; j++){
                if(i%2==1 and j%2==1){
                    BFS(i,j);
                }
            }
        }
        for(int i=1; i<=2*n-1; i++){
            for(int j=1; j<=2*n-1; j++){
                    vis[i][j]=0;
            }
        }
    }
    cout<<ccnt-1<<endl;
}