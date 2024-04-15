//양갈래 배열 출력하기 - S1 - 2024/04/12
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
#define fastio cin.tie(0) , cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n,m;
char c;
int st_num=1;
int temp[5][6];
int visvis[5][6];
int dx_U[4]={1,0,-1,0};
int dy_U[4]={0,-1,0,1};
int dx_D[4]={-1,0,1,0};
int dy_D[4]={0,-1,0,1};

int dx_L[4]={0,-1,0,1};
int dy_L[4]={1,0,-1,0};
int dx_R[4]={0,-1,0,1};
int dy_R[4]={-1,0,1,0};
void DFS_U(int x ,int y,int num, vector<vector<int>> &arr, vector<vector<int>>&vis,int cur_num){
    // 여기선 &로 넘겨줘야지
    if(num==(n*(m+1)/2)){ 
        return;}
    vis[x][y]=1;
    int nx = x+dx_U[cur_num];
    int ny = y+dy_U[cur_num];
    if(nx>=0 and ny>=0 and nx<n and ny<m){
        if(vis[nx][ny]==1){
            cur_num++;
            cur_num%=4;
            vis[x][y]=0;
            DFS_U(x,y,num,arr,vis,cur_num);
        }
        else{
            arr[nx][ny]=num+1;
            DFS_U(nx,ny,num+1,arr,vis,cur_num);
        }
    }
      else{
        cur_num++;
        cur_num%=4;
        vis[x][y]=0;
        DFS_U(x,y,num,arr,vis,cur_num);
    }

}
void DFS_D(int x, int y, int num,vector<vector<int>> &arr, vector<vector<int>>&vis,int cur_num){
    if(num==(n*(m+1)/2)) return;
    vis[x][y]=1;
    int nx = x+dx_D[cur_num];
    int ny = y+dy_D[cur_num];
    if(nx>=0 and ny>=0 and nx<n and ny<m){
        if(vis[nx][ny]==1){
            cur_num++;
            cur_num%=4;
            vis[x][y]=0;
            DFS_D(x,y,num,arr,vis,cur_num);
        }
        else{
            arr[nx][ny]=num+1;
            DFS_D(nx,ny,num+1,arr,vis,cur_num);
        }
    }
      else{
        cur_num++;
        cur_num%=4;
        vis[x][y]=0;
        DFS_D(x,y,num,arr,vis,cur_num);
    }

}
void DFS_L(int x, int y, int num,vector<vector<int>> &arr, vector<vector<int>>&vis,int cur_num){
    if(num==(((n+1)/2)*m)) return;
    vis[x][y]=1;
    int nx = x+dx_L[cur_num];
    int ny = y+dy_L[cur_num];
    if(nx>=0 and ny>=0 and nx<n and ny<m){
        if(vis[nx][ny]==1){
            cur_num++;
            cur_num%=4;
            vis[x][y]=0;
            DFS_L(x,y,num,arr,vis,cur_num);
        }
        else{
            arr[nx][ny]=num+1;
            DFS_L(nx,ny,num+1,arr,vis,cur_num);
        }
    }
    else{
        cur_num++;
        cur_num%=4;
        vis[x][y]=0;
        DFS_L(x,y,num,arr,vis,cur_num);
    }

}
void DFS_R(int x, int y, int num,vector<vector<int>> &arr, vector<vector<int>>&vis,int cur_num){
    if(num==(((n+1)/2)*m)) return;
    vis[x][y]=1;
    int nx = x+dx_R[cur_num];
    int ny = y+dy_R[cur_num];
    if(nx>=0 and ny>=0 and nx<n and ny<m){
        if(vis[nx][ny]==1){
            cur_num++;
            cur_num%=4;
            vis[x][y]=0;
            DFS_R(x,y,num,arr,vis,cur_num);
        }
        else{
            arr[nx][ny]=num+1;
            DFS_R(nx,ny,num+1,arr,vis,cur_num);
        }
    }
    else{
        cur_num++;
        cur_num%=4;
        vis[x][y]=0;
        DFS_R(x,y,num,arr,vis,cur_num);
    }
}
int main(){
    fastio;
    cin>>n>>m>>c;
    if(c=='U'|| c=='D'){
    vector<vector<int>> arr(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
        if(c=='U'){
            int st_x = 0;
            int st_y = (m+1)/2-1;
            arr[st_x][st_y]=st_num;
            DFS_U(st_x, st_y, st_num, arr, vis,0);
            for(int i=0 ; i<n ; i++){
                int tt=1;
                for(int j=0; j<m; j++){
                    if(j<=st_y)cout<<arr[i][j]<<" ";
                    else{
                        cout<<arr[i][j-tt*2]<<" ";
                        tt++;
                    }
                }cout<<endl;
            }
        }
        else{
            int st_x = n-1;
            int st_y = (m+1)/2-1;
            arr[st_x][st_y]=st_num;
            DFS_D(st_x, st_y, st_num, arr, vis,0);
            for(int i=0 ; i<n ; i++){
                int tt=1;
                for(int j=0; j<m; j++){
                    if(j<=st_y)cout<<arr[i][j]<<" ";
                    else{
                        cout<<arr[i][j-tt*2]<<" ";
                        tt++;
                    }
                }cout<<endl;
            }
        }
    }
    if(c=='L'|| c=='R'){
    vector<vector<int>> arr2(n, vector<int>(m, 0));
    vector<vector<int>> vis2(n, vector<int>(m, 0));
        if(c=='L'){
            int st_x = (n+1)/2-1;
            int st_y = 0;
            arr2[st_x][st_y]=st_num;
            DFS_L(st_x, st_y, st_num, arr2, vis2,0);
            for(int i=0; i<n; i++){
                if(i<=st_x){
                    for(int j=0; j<m; j++){
                        cout<<arr2[i][j]<<" ";
                    }cout<<endl;
                }
                else{
                    for(int j=0; j<m; j++){
                        cout<<arr2[i-(i-st_x)*2][j]<<" ";
                    }cout<<endl;
                }
            }
        }
        else{
            int st_x = (n+1)/2-1;
            int st_y = m-1;
            arr2[st_x][st_y]=st_num;
            DFS_R(st_x, st_y, st_num, arr2, vis2,0);
            for(int i=0; i<n; i++){
                if(i<=st_x){
                    for(int j=0; j<m; j++){
                        cout<<arr2[i][j]<<" ";
                    }cout<<endl;
                }
                else{
                    for(int j=0; j<m; j++){
                        cout<<arr2[i-(i-st_x)*2][j]<<" ";
                    }cout<<endl;
                }
            }
        }
    }
}