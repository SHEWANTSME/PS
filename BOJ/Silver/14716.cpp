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
    if(visited[x][y] or arr[x][y] == 0)return;// 이렇게 바뀌고
    visited[x][y]=1;
    for(int i=0 ; i<8 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 or ny<0 or nx>=r or ny >=c)continue;
        if(visited[nx][ny] or arr[nx][ny]==0)continue;//이렇게 바뀌어야겠죠
        DFS(nx,ny);
    }
    // 뭉텅이를 찾는 노하우는 알아두는게 좋음.
    // 그리고 왜 맨첨 if랑 for문 안의 if문이 겹치냐고 생각할 수도 있는데
    // main에서 DFS에 맨 처음 들어갈때 맨처음 요소는 for문으로 안걸러지니까 
    // 저렇게 맨첨if랑 for안의 if랑 써줘야하는거임.
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
// 이젠 맞는 풀이