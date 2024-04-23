// 가장 먼 노드 - LV3 - 2024.04.23
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int vis[20001];
vector<int>graph[20001];
int cnt=0;
void BFS(int node, int dest){
    if(node==dest or graph[node].empty() ){
        return;
    }
    fill(vis,vis+20001,-1);
    queue<int>q;
    q.push(node);
    vis[node]=0;
    while(not q.empty()){
        int cur = q.front();q.pop();
        for(auto &e : graph[cur]){
            if(vis[e]!=-1)continue;
            q.push(e);
            vis[e]=vis[cur]+1; 
        }
    }
    sort(vis,vis+20001,greater<int>());
    int top=vis[0];
    for(int i=0;i<20001;i++){
        if(vis[i]==top)cnt++;
        else break;
    }
    return;
}

int solution(int n, vector<vector<int>> arr) {
    for(int i=0;i<arr.size();i++){
        int x,y;
        x=arr[i][0];y=arr[i][1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    BFS(1,n);// 처음엔 이렇게 안하고 for문으로 돌렸는데, 시간초과가 났다.
    // 그런데 생각해보면 그럴 필요 없고, 1에서 맨 마지막 숫자의 노드를 적으면
    // vis가 1에서 가장 먼 노드까지의 거리를 저장하고 있기 때문에
    // cnt를 세주면 된다.
    return cnt;
}