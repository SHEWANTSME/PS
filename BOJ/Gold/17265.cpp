// 나의 인생에는 수학과 함께 - G5 - 2023/03/10
// 무지성으로 모든경우 다 써서 해보려고 했는데 생각보다 많아서 그냥 원래 방식대로
// 아무리 봐도 dp -> 다시해보자
//처음부터 다 짜보는중
// dp로도 해보고 bfs로도 해보고 brute로도 해보자!
#include<iostream>
using namespace std;
int dp[6][6];
int n;
char arr[6][6];
int minn = 1e9;
int maxx = -1e9;
int dx[2]={0,1};
int dy[2] = {1,0};
void Cal_left(int x,int y){

}
void Cal_upper(int x, int y){

}
void Cal_dia(int x , int y){

}
void DP(int x, int y){
    if(n==3){
        if(x==2 and y==0) Cal_upper(x,y);
        if(x==1 and y==1) Cal_dia(x,y);
        if(x==0 and y==2) Cal_left(x,y);
        if(x==2 and y==2) Cal_dia(x,y);
    }
    else{
        if(x==2 and y==0) Cal_upper(x,y);
        if(x==4 and y==0) Cal_upper(x,y);
        if(x==1 and y==1) Cal_dia(x,y);
        if(x==0 and y==2) Cal_left(x,y);
        if(x==0 and y==4) Cal_left(x,y);
        if(x==2 and y==2) Cal_dia(x,y);
    }
}

void Func(int x, int y,int now){
    if(x==n-1 and y==n-1){
        minn = min(minn,now);
        maxx= max(maxx,now);
        return;
    }
    for(int i=0; i<2 ; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        int nw=now;
        int temp=arr[nx][ny]-'0';
        if(nx<0 or ny<0 or nx>=n or ny>=n)continue;
        if(arr[x][y]=='+'){
            nw+=temp;
        }
        if(arr[x][y]=='-'){
            nw-=temp;
        }
        if(arr[x][y]=='*'){
            nw*=temp;
        }
        Func(nx,ny,nw);
    }
}

int main(){
    /*
    (0,0)  -> 0
    (2,0),(1,1),(0,2) -> 2
    (4,0),(3,1),(2,2),(1,3),(0,4) -> 4
    (4,2),(3,3),(2,4) -> 6
    (4,4) ->8
    */
   cin>>n;
   for(int i=0; i<n ; i++){
    for(int j=0 ; j<n ; j++){
        cin>>arr[i][j];
    }
   }
   Func(0,0,arr[0][0]-'0');
   cout<<maxx<<" "<<minn<<endl;
}
//-------------------------------------------

// 나의 인생에는 수학과 함께 - G5 - 2023/03/10
// DP, BFS, bruteforce 다 되는듯
#include<iostream>
#include<algorithm>
using namespace std;
int n;
char arr[6][6];
int minn = 1e9;
int maxx = -1e9;
int dx[2]={0,1};
int dy[2] = {1,0};
void Func(int x, int y,int now){
    if(x==n-1 and y==n-1){
        minn = min(minn,now);
        maxx= max(maxx,now);
        return;
    }
    for(int i=0; i<2 ; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        int nw=now;
        int temp=arr[nx][ny]-'0';
        if(nx<0 or ny<0 or nx>=n or ny>=n)continue;
        if(arr[x][y]=='+') nw+=temp;
        if(arr[x][y]=='-') nw-=temp;
        if(arr[x][y]=='*') nw*=temp;
        Func(nx,ny,nw);
    }
}

int main(){
   cin>>n;
   for(int i=0; i<n ; i++){
    for(int j=0 ; j<n ; j++){
        cin>>arr[i][j];
    }
   }
   Func(0,0,arr[0][0]-'0');
   cout<<maxx<<" "<<minn<<endl;
}

