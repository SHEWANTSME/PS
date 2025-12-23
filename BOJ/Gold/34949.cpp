// 이대로 가면 되나요? - G5 - 2025.12.23
// 딱 봤을때 DFS가 떠올라서 DFS로 품
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;
int n;
int arr[200001];
int vis[200001]; // vis=1 : 현재 탐색 경로에 포함된 노드 , vis=0 : 포함 안된 노드
int dp[200001];// 0: 아직 안품, -1: 사이클, 양수: 도달하는 노드 수
int DFS(int node){
    int now = node;
    if(now == n)return dp[now]=0;// now가 n이면 도달 노드 수 0
    if(dp[now]!=0)return dp[now]; // 이미 계산된 거면 바로 반환
    if(vis[now]==1) return dp[now]=-1;// 사이클 -> -1 반환
    vis[now]=1;// now를 현재 탐색 경로에 포함
    int nxt = arr[now];
    int res = DFS(nxt);// nxt로 이동
    vis[now]=0;//이걸 왜 해주냐? -> 다른 경로에서 now를 방문할 수 있게 -> 현재 탐색 경로에서만 포함시키고 끝나면 빼줌
    if(res==-1) return dp[now]=-1; // 다음 node가 사이클이면 나도 사이클
    else return dp[now]=res+1;// 다음 node가 사이클이 아니면 +1 해서 반환
}
int main(){
    cin>>n;
    for(int i=1; i<=n ;i++)
        cin>>arr[i];
    for(int i=1; i<n; i++)
        cout<<DFS(i)<<endl;
    cout<<0<<endl;
}
/*
DFS(1): 전부 계산 + dp 저장
DFS(2): dp[2] 바로 반환
DFS(3): dp[3] 바로 반환
...
*/