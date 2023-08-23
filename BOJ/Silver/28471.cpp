// W키가 빠진 성원이 - S1 - 2023/08/23
// 한방에 풀어따 후후
// 그냥 거꾸로 생각해보면 간단함
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
char arr[2001][2001];
int visited[2001][2001];
//w키 제외하고 모든 방향 다 존재 -> w키는 위로한칸
// 근데 지금 F에서부터 시작하니까 아래로 내려가는거 안된다고 보고 해야지
int dx[7] = {0,-1,0,1,1,-1,-1};
int dy[7] = {1,0,-1,1,-1,1,-1};
int n,sx,sy;
int main(){
    cin>>n;
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n ; j++){
            scanf(" %c", &arr[i][j]);// 붙어있는 char들은 이렇게 받아야 함
            if(arr[i][j]=='F'){sx=i;sy=j;}
        }
    }
    queue<pair<int,int>>q;
    q.push({sx,sy});
    visited[sx][sy]=1;
    while(not q.empty()){
        int x = q.front().first;
        int y =q.front().second;
        q.pop();
        for(int i=0 ; i<7 ; i++){
            int nx= x + dx[i];
            int ny= y + dy[i];
            if(nx<1 or ny<1 or nx>n or ny>n)continue;
            if(visited[nx][ny])continue;
            if(arr[nx][ny]=='#')continue;
            visited[nx][ny]=1;
            q.push({nx,ny});
        }
    }
    int ans=0;
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n;j++){
            if(visited[i][j]==1)ans++;
        }
    }
    cout<<ans-1<<endl;
    // n==1일때 오류가 생길 수도 있는데, n=1일땐 경우가 F 하나밖에 없어서
    // 따로 경우처리 할 필요가 없었음

}