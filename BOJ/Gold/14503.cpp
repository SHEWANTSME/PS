// 로봇 청소기 - G5 - 2023/04/06
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
rule check : 
about 방향 : 0:북, 1:동 , 2:남 , 3:서 
1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
    a. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
    b. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3. 현재 칸의 주변4칸 중 청소되지 않은 빈 칸이 있는 경우,
    a. 반시계 방향으로 90도 회전한다.
    b. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
    c. 1번으로 돌아간다.
*/
bool room[51][51];
bool cleaned[51][51];
int dx[4] = {-1,0,1,0};// -1  0  1  0
int dy[4]= {0,1,0,-1};//  0   1  0  -1

int ddx[4]={1,0,-1,0};// -1  0  1  0 
int ddy[4]={0,-1,0,1};// 0  -1  0  1
int stx, sty,n,r,c;//n=0:북,n=1동,n=2남,n=3서
int cnt = 0;
void Robot(int xx,int yy, int nn){
    if(room[xx][yy]== 0 and cleaned[xx][yy]==0){
        cleaned[xx][yy]=1;
        cnt++;
    }

    // 일단 방향 체크부터 하자
    bool flag = 0;
    for(int i=0 ; i<4 ; i++){
        if(flag==1)break;
        int kx = dx[i]+xx;
        int ky = dy[i]+yy;
        if(kx<0 or ky<0 or kx>=r or ky>=c)continue;
        if(cleaned[kx][ky]==1 )continue;
        flag=1;
    }
    if(flag!=1){
        int back= nn+2;
        if(back>=4)back-=4;
        int nnx = xx+dx[back];
        int nny=yy+dy[back];
        if(nnx<0 or nny<0 or nnx>=r or nny>=c)return;
        if(room[nnx][nny]==1)return;
        // if(cleaned[nnx][nny]==1)return;
        Robot(nnx,nny,nn);
        return;
    }
    else{
        for(int i=nn; i<nn+4 ; i++){
            int tmp=i;
            if(tmp>=4) tmp-=4;
            int nx = xx+ddx[tmp];
            int ny = yy+ddy[tmp];
            //if(nx<0 or ny<0 or nx>=r or ny>=c)continue;
            if(cleaned[nx][ny]==1 or room[nx][ny]==1)continue;
            Robot(nx,ny,tmp);
            return;
        }
    }

    //nn=0 -> 1,2,3체크
    //nn=1 -> 2,3,0체크
    //nn=2 -> 3,0,1
    //nn=3-> 0,1,2
    //nn
   
    

}
int main(){
    cin>>r>>c;
    cin>>stx>>sty>>n;
    for(int i=0; i<r;i++)
        for(int j=0;j<c;j++)
            cin>>room[i][j];
    Robot(stx,sty,n);
    cout<<cnt<<endl;
    // for(int i=0; i<r ; i++){
    //     for(int j=0 ; j<c ; j++){
    //         cout<<cleaned[i][j]<<" ";
    //     }cout<<endl;
    // }

}