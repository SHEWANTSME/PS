// 로봇 청소기 - G5 - 2023/04/06
// 중요한건, 후진이 가능하면 반대방향으로만 후진을 진행하고
// 후진상황에서 벽을 만나면 그대로 종료해야함.
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

// 후진 -> ddx -> dx랑 부호만 다름
int ddx[4]={1,0,-1,0};// 1  0  -1  0 
int ddy[4]={0,-1,0,1};// 0  -1  0  1
int stx, sty,n,r,c;//n=0:북,n=1동,n=2남,n=3서
int cnt = 0;
void Robot(int xx,int yy, int nn){
    // 걍 다시짜야겠따 머리아프군
    if(room[xx][yy]==0 and cleaned[xx][yy]==0){
        cnt++; cleaned[xx][yy]=1;//1번.
    }
    int arr[4];
    if(nn==0){arr[0]=3;arr[1]=2;arr[2]=1;arr[3]=0;}// 북쪽을 바라보고 있을때, arr[0]은 9시방향,arr[1]은 6시방향, arr[2]는 3시, 0시 이렇게
    if(nn==1){arr[0]=0;arr[1]=3;arr[2]=2;arr[3]=1;}// 동쪽을 ``, arr[0]:0시, arr[1]:9시 ,6시 ,,
    if(nn==2){arr[0]=1;arr[1]=0;arr[2]=3;arr[3]=2;}// 현재 방향과 반시계가 어떻게 돌아가는지 파악하면 된다.
    if(nn==3){arr[0]=2;arr[1]=1;arr[2]=0;arr[3]=3;}
    for(int i=0 ; i<4 ; i++){
        // 3경우들
        int nx = xx+dx[arr[i]];
        int ny = yy+dy[arr[i]];
        if(nx<0 or ny<0 or nx>=r or ny>=c)continue;
        if(room[nx][ny])continue;
        if(cleaned[nx][ny])continue;
        Robot(nx,ny,arr[i]);
        return;
     }
        if(room[xx+ddx[nn]][yy+ddy[nn]]==1) return; //2-b
        else Robot(xx+ddx[nn],yy+ddy[nn],nn);//2-a
}
int main(){
    cin>>r>>c;
    cin>>stx>>sty>>n;
    for(int i=0; i<r;i++)
        for(int j=0;j<c;j++)
            cin>>room[i][j];
    Robot(stx,sty,n); 
    //for(int i=0; i<r ; i++){
    //    for(int j=0 ; j<c ; j++){
    //        cout<<cleaned[i][j]<<" ";
    //    }cout<<endl;
    //}
    cout<<cnt<<endl;
}

// 하 더러운 문제군
// 그냥 하라는대로 하면 되는데, 내가 처음에 생각했던것처럼 도는게 아니고
// nn:0 -> 3,2,1,0이면 nn:1 -> 0,3,2,1 이렇게 됨.. 이게 첨엔 생각이 안났음
// 처음엔 그냥 3,2,1,0이면 그다음엔 2,1,0,3겠지 이렇게만 생각했음.