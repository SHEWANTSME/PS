// 농장관리 - G5 - 2024/10/09
// retry해보자!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int cnt=0;
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1  ,1,1,0,-1,-1};
int arr[101][71];
int vis[101][71];
bool check(int x, int y){
    int now = arr[x][y];
    bool flag= 1;
    vis[x][y]=1;
    //vector<pair<int,int>>tmp = {{x,y}};
    for(int i=0; i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<1 or ny<1 or nx>n or ny>m)continue;
        if(arr[nx][ny]>now){flag=0;}
        else if(arr[nx][ny]== now and not vis[nx][ny]){
            vis[nx][ny]=1;
            if(not check(nx,ny)){
                flag=0;
            }
        }
    }
    return flag;
}
// void check(int x, int y){
//     int now = arr[x][y];
//     bool flag=0;
//     vector<pair<int,int>>tmp;
//     if(vis[x][y]==1)return;
//     vis[x][y]=1;
//     for(int i=0;i<8;i++){
//         int nx= x+dx[i];
//         int ny=y+dy[i];
//         if(nx<1 or ny<1 or nx>n or ny>m) continue;
//         if(flag)break; 
//         if(now<arr[nx][ny])flag=1;
//         if(now==arr[nx][ny]){
//             tmp.push_back({nx,ny});
//         }
//     }
//     if(flag){return;}
//     if(tmp.empty()){
//         cnt++;return;
//     }
//     while(not tmp.empty()){
//         auto x = tmp.back();
//         tmp.pop_back();
//         check(x.first,x.second);
//     }
// }
int main(){
    cin>>n>>m;
    for(int i=1; i<=n;i++)
        for(int j=1; j<=m;j++)
            cin>>arr[i][j];

    for(int i=1; i<=n;i++){
        for(int j=1; j<=m;j++){
            if(not vis[i][j] and check(i,j)) {
                cnt++;
            }}}

    cout<<cnt<<endl;
}