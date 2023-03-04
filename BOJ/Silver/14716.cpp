// 이 문제도 뭉텅이를 찾는거임
// 그냥 백준에서 바로 풀어봐야지
// 현수막 - S1 - 2023/03/05
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dx[8] = {0,1,-1,0,1,1,-1,-1}; // 상하좌우 + 대각선들까지 하니까 
int dy[8] = {1,0,0,-1,1,-1,1,-1}; // 상하좌우 + 대각선들까지 하니까 
int r,c;
int arr[251][251];
bool visited[251][251];
int cnt=0;
void DFS(int x, int y){ // 처음엔 visited만 생각해줬는데 
// 해당 문제에서는 방문여부와 현재 arr의 값이 1인 뭉텅이만 찾고 싶으니까
    if(visited[x][y])return;// 여기에도 추가적인 조건이 들어가야하고
    visited[x][y]=1;
    for(int i=0 ; i<8 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 or ny<0 or nx>=r or ny >=c)continue;
        if(visited[nx][ny])continue;//여기에도 들어가야겠죠?
        DFS(nx,ny);
    }
}
int main(){
    cin>>r>>c;
    for(int i=0 ; i<r ; i++)
        for(int j=0 ; j<c ; j++)
            cin>>arr[i][j];
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            if(not visited[i][j] and arr[i][j] == 1){
                DFS(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
// 위 풀이는 틀렸다. 왜 틀렸을까? 생각해보면 