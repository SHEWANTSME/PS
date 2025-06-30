// 점프왕 쩰리 (Small) - S1 - 2025.06.30
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int arr[65][65];
int vis[65][65];
bool flag=0;
void check(int x, int y){
    int now = arr[x][y];
    if(vis[x][y]==1 or vis[x][y]==-1)return;
    vis[x][y]=1;
    if(arr[x][y]==-1){flag=1;return;}
    if(x+now<=n and y+now<=n){
        check(x+now,y);
        check(x,y+now);
    }
    if(x+now<=n and y+now>n){
        check(x+now,y);
    }
    if(x+now>n and y+now<=n){
        check(x,y+now);
    }
    if(x+now>n and y+now >n){
        vis[x][y]=-1;
    }
    
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n ; j++)
            cin>>arr[i][j];
    check(1,1);
    if(flag) cout<<"HaruHaru"<<endl;
    else cout<<"Hing"<<endl;
}