// 부대 복귀 - LV3 - 2024.04.23
// node에서 dest 까지의 거리를 구하면 되는 문제
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int>graph[100003]; //인접리스트 graph
int vis[100003];
vector<int>ans;
void BFS(int node, int dest){
    if(node==dest){// BFS라서 재귀형태가 아니기 때문에, 처음부터 node==dest라면 거리가 0
        ans.push_back(0);
        return;
    }
    if(graph[node].empty()){// node에서 갈 수 있는 곳이 없다면 -1
        ans.push_back(-1);
        return;
    }
    fill(vis,vis+100003,-1);// vis 초기화
    queue<int>q;
    q.push(node);
    vis[node]=0;// 처음 시작하는 노드는 0
    while(not q.empty()){
        int cur = q.front();q.pop();
        for(auto &e : graph[cur]){
            if(vis[e]!=-1)continue;// 방문했던 곳이면 패스
            q.push(e);
            vis[e]=vis[cur]+1; // 거리는 이전 노드의 거리 + 1
        }
    }
    ans.push_back(vis[dest]);
    return;
}


vector<int> solution(int n, vector<vector<int>> arr, vector<int> src, int dest) {
    for(int i=0;i<arr.size();i++){
        int x,y;
        x=arr[i][0];y=arr[i][1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(auto &e : src){
        BFS(e,dest);
    }
    return ans;
}