// 체스 - S1 - 2025/01/16
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,Q,K,P;
// Queen 방향
int qx[8] = {1,1,0,-1,-1,-1,0,1};
int qy[8] = {0,-1,-1,-1,0,1,1,1};
// Knight 방향
int kx[8] = {2,1,-1,-2,-2,-1,1,2};
int ky[8] = {-1,-2,-2,-1,1,2,2,1};

void Go(int x, int y, int i , vector<vector<int>>&v,int st){
    if(x<1 or y<1 or x>n or y>m) return;
    if(v[x][y]==0) v[x][y]=3;
    if(v[x][y]<0) return;
    if(v[x][y]>0){
        if(v[x][y]<=abs(st))v[x][y]=3;
    }
    Go(x+qx[i], y+qy[i],i,v,st);
}
void Browse(int x ,int y , int piece, vector<vector<int>>&v){
    if(piece == -3){ // Queen
       // if(v[x][y]<0)return;
        for(int i=0 ; i<8 ; i++){
            int nx = x + qx[i];
            int ny = y + qy[i];
            if(nx<1 or ny<1 or nx>n or ny>m)continue;
            if(v[nx][ny]<0) continue;
            Go(nx,ny,i,v,v[x][y]);
        }
    }
    if(piece == -2){ // Knight
        for(int i=0; i<8 ; i++){
            int nx = x + kx[i];
            int ny = y+ky[i];
            if(nx<1 or ny<1 or nx>n or ny>m)continue;
            if(v[nx][ny]<0) continue;
            v[nx][ny]= 2;
        }
    }

}

int main(){
    cin>>n>>m;
    vector<vector<int>>v(n+1 , vector<int>(m+1,0));
    cin>>Q;
    // 초기 KQP는 음수로 설정
    while(Q--){//Queen
        int x,y; cin>>x>>y;
        v[x][y]= -3;
    }
    cin>>K;
    while(K--){//Knight
        int x,y; cin>>x>>y;
        v[x][y]=-2;
    }
    cin>>P; 
    while(P--){//Pawn
        int x,y; cin>>x>>y;
        v[x][y] = -1;
    }
    for(int i=1 ;i<=n ; i++){
        for(int j=1; j<=m ; j++){
            if(v[i][j]==-3){ // Queen
                Browse(i,j,-3,v);
            }
            if(v[i][j]==-2){ // Knight
                Browse(i,j,-2,v);
            }
        }
    }

    // for(int i=1 ;i<=n ; i++){
    //     for(int j=1; j<=m ; j++){
    //         cout<<v[i][j]<<" ";
    //     }cout<<endl;
    // }
    int cnt=0;
     for(int i=1 ;i<=n ; i++){
        for(int j=1; j<=m ; j++){
            if(v[i][j]==0)cnt++;
        }
    }
    cout<<cnt<<endl;
}