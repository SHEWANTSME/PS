// 죽음의 등굣길 - S1 - 2024.06.25
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,x;
int arr[101][101];
int vis[101][101];
int dx[2]= {1,0};
int dy[2]= {0,1};

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    cin>>x;
    int w = m+n-2;
    int st = arr[0][0];
    int en = arr[n-1][m-1];
    if(w<=x){// 점프로 한방에 갈 수 있는경우
        if(st==en) cout<<"ALIVE"<<endl;//시작과 끝이 같으면 살고
        else cout<<"DEAD"<<endl;//아님 사망
        exit(0);
    }
    if(st!=en){//시작과 끝이 다르면 무조건 죽음
        cout<<"DEAD"<<endl;
        exit(0);
    }
    vis[0][0]=1;
    queue<pair<int,int>>q;
    q.push({0,0});
    while(not q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        if(xx==n-1 and yy==m-1){
            cout<<"ALIVE"<<endl;exit(0);//끝에 도달하면 살아있음
        }
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                if(xx==i and yy==j)continue;//자기자신은 제외 -> 이미 queue에 들어감
                int dist = abs(xx-i)+abs(yy-j);// 이게 어차피 지나온건 vis로 체크해서 맨해튼 거리로만 체크해도 무방
                if(dist<=x and arr[i][j]==st and not vis[i][j]){// 점프거리 이하 + 시작점과 같은색 + 아직 방문안한곳
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
    }
    cout<<"DEAD"<<endl;//아님 사망
}


    //헛짓거리
    // while(not q.empty()){
    //     auto tt = q.front();
    //     int xx = tt.first;
    //     int yy = tt.second;
    //     q.pop();
    //     if(x+xx<=m){
    //         vis[0][x+xx] = -1;
    //         for(int i=0;i<n;i++){
    //             if(x+xx-i<0)break;
    //             vis[i][x+xx-i]=-1;
    //             for(int j=0;j<x+xx-i;j++){
    //                 vis[i][j]=-1;
    //             }
    //         }            
    //     }
    //     if(x+xx>m){// 예를 들어 x =10 , m=7 -> x-m +1 = 4니까  arr[x-m+1][m-1] 부터 왼쪽 아래 대각선행 
    // //만약 n=3이라서 4가 안되면, 그럼 애초에 위의 if에서 걸러짐
    //     vis[x+xx-m+1][m-1]=-1;
    //     for(int i=0;i<=x+xx-m+1;i++){
    //         for(int j=0;j<=m-1;j++){
    //             vis[i][j]=-1;
    //         }
    //     }
    //     for(int i=xx;i<n;i++){
    //         if(x-m+1+i>=n)break;
    //         vis[x-m+1+i][m-1-i]=-1;
    //         for(int j=yy;j<m-1-i;j++){
    //             vis[x-m+1+i][j]=-1;
    //         }
    //     }
    // }

    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==0 and j==0)continue;
    //         if(vis[i][j]==-1 and arr[i][j]==st){
    //             q.push({i,j});
    //         }
    //     }
    // }




    // if(x<=m){
    //     //arr[0][x]부터 왼쪽 아래 대각선행
    //     vis[0][x] = -1;
    //     for(int i=0;i<n;i++){
    //         if(x-i<0)break;
    //         vis[i][x-i]=-1;
    //         for(int j=0;j<x-i;j++){
    //             vis[i][j]=-1;
    //         }
    //     }
    // }
    // if(x>m){// 예를 들어 x =10 , m=7 -> x-m +1 = 4니까  arr[x-m+1][m-1] 부터 왼쪽 아래 대각선행 
    // //만약 n=3이라서 4가 안되면, 그럼 애초에 위의 if에서 걸러짐
    //     vis[x-m+1][m-1]=-1;
    //     for(int i=0;i<=x-m+1;i++){
    //         for(int j=0;j<=m-1;j++){
    //             vis[i][j]=-1;
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         if(x-m+1+i>=n)break;
    //         vis[x-m+1+i][m-1-i]=-1;
    //         for(int j=0;j<m-1-i;j++){
    //             vis[x-m+1+i][j]=-1;
    //         }
    //     }
    // }
    // queue<pair<int,int>>q;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==0 and j==0)continue;
    //         if(vis[i][j]==-1 and arr[i][j]==st){
    //             q.push({i,j});
    //         }
    //     }
    // }

    // queue<pair<int, int>> q;
    // q.push({0, 0});
    // vis[0][0]=1;
    // int st = arr[0][0];
    // while(not q.empty()){
    //     auto tt = q.front();
    //     int xx = tt.first;
    //     int yy = tt.second;
    //     q.pop();
    //     if(xx == n-1 and yy==m-1){
    //         cout<<"ALIVE"<<endl;
    //         exit(0);
    //     }
    //     for(int i=0;i<2;i++){
    //         for(int j=1;j<=x;j++){
    //             int nx = xx + dir[i][0]*j;
    //             int ny = yy + dir[i][1]*j;
    //             if(nx>=0 and ny>=0 and nx<n and ny<m and not vis[nx][ny] and arr[nx][ny]==st){
    //                 vis[nx][ny]=1;q.push({nx,ny});
    //             }
    //         }
    //     }
    // }
    // cout<<"DEAD"<<endl;

