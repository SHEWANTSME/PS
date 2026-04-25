// 내리막 길 - G5 - 2026.04.25
#include<iostream>
using namespace std;
int n,m;
int arr[501][501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dp[501][501];
int dfs(int x,int y){
    if(x==n-1 and y==m-1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y]=0;
    for(int i=0; i<4;i++){
        int nx = x+ dx[i];
        int ny = y+ dy[i];
        if(nx>=0 and ny>=0 and nx<n and ny<m){
            if(arr[nx][ny]<arr[x][y]) dp[x][y]+=dfs(nx,ny);
        }
    }
    return dp[x][y];
}
int main(){
    cin>>n>>m;
    for(int i=0 ; i<n; i++){
        for(int j=0; j<m ; j++){
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
    }
    cout<<dfs(0,0)<<endl;
}