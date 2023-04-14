// 킹 - S3 - 2023/04/14
// 그냥 하라고 하는대로 하면됨.. 다만 
// 체스판을 내가 편한 arr의 형태로 바꾸는게 좀 귀찮
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int chess[9][9];
char king_1,stone_1;
int king_2,stone_2,n;
// a1~h1 
/*
  a b c d e f g h
8 
7 
6 
5 
4 
3 
2 
1 

*/
int dx[8]={0,0,1,-1,-1,-1,1,1};
int dy[8]={1,-1,0,0,1,-1,1,-1};
string dir[8]={"R","L","B","T","RT","LT","RB","LB"};
int main(){
    cin>>king_1>>king_2;
    int kx = 10-king_2-1;
    int ky = king_1-64;
    chess[kx][ky]=1;
    // king_1이 A :1 ,B: 2,C,D,E,F,G,H : 8  -> -64하면 됨
    // king_2가 1~8이면 (10 - king_2 -1)
    // 그니까 arr[10-king_2-1][king_1-64] = king's 위치
    cin>>stone_1>>stone_2;
    int sx = 10-stone_2-1;
    int sy=stone_1-64;
    chess[sx][sy]=-1;
    // arr[10-stone_2-1][stone_1-64]= stone's위치
    cin>>n;
    // cout<<king_1 << " " << king_2 << endl;
    // cout<<stone_1 << " "<<stone_2 << endl;
    // cout<<n<<endl;
    
    while(n--){
        string s;
        cin>>s;
        for(int i=0;i<8;i++){
            if(s!=dir[i])continue;
            if(s==dir[i]){
                int nx = kx+dx[i];
                int ny = ky+dy[i];
                if(nx<1 or ny<1 or nx>8 or ny>8)continue;
                if(chess[nx][ny]!=-1){
                    chess[kx][ky]=0;
                    chess[nx][ny]=1;
                    kx=nx;ky=ny;
                    break;
                }
                if(chess[nx][ny]==-1){
                    sx = sx+dx[i];
                    sy=sy+dy[i];
                    if(sx<1 or sy<1 or sx>8 or sy>8){sx-=dx[i];sy-=dy[i];break;}
                    chess[kx][ky]=0;
                    chess[nx][ny]=1;
                    chess[sx][sy]=-1;
                    kx=nx;ky=ny;
                    break;
                }
            }
        }
    }
    cout<< char(ky+64)<<10-kx-1<<endl;
    //cout<<kx<<" " << ky<<endl;
    cout<<char(sy+64)<<10-sx-1<< endl;
}