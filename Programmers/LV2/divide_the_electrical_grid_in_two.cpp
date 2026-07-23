#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

int minn = 10000000;  // 지금까지 찾은 "두 그룹 크기 차이"의 최솟값 (초기값은 충분히 큰 수)

// node_A에서 시작해서, node_B 방향으로는 절대 넘어가지 않으면서
// 갈 수 있는 모든 노드의 개수(=node_A가 속한 쪽 그룹의 크기)를 구하는 함수
// => 즉, "node_A-node_B" 간선을 끊은 상태에서 BFS를 도는 것과 같은 효과
int BFS(int node_A, int node_B, vector<vector<int>> graph){
    queue<int> q;
    vector<int> vis(graph.size());  // 노드 번호를 인덱스로 쓰니까 크기는 graph.size()(=n+1)면 충분
    vis[node_A] = 1;                // 시작 노드 방문 처리
    q.push(node_A);
    int cnt = 1;                    // 시작 노드(node_A) 자기 자신도 그룹의 일원이므로 1부터 시작

    while (not q.empty()) {
        int now = q.front();
        q.pop();
        for (auto &e : graph[now]) {   // now와 직접 연결된 노드들을 하나씩 확인
            if (vis[e] == 1) continue;     // 이미 방문한 노드면 건너뜀 (중복 방문 방지)
            if (e == node_B) continue;     // node_B로 가는 간선은 "끊긴 것"으로 취급 -> 여기가 끊긴 wire를 구현한 부분!
            cnt++;
            vis[e] = 1;
            q.push(e);
        }
    }
    return cnt;  // node_A가 속한 그룹의 전체 노드 개수
}

int solution(int n, vector<vector<int>> wires) {
    // 1단계: 그래프(인접리스트)를 "완성"한다 (BFS 돌리기 전에 모든 wire를 다 반영)
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < wires.size(); i++) {
        int node_A = wires[i][0];
        int node_B = wires[i][1];
        graph[node_A].push_back(node_B);
        graph[node_B].push_back(node_A);
    }

    // 2단계: 완성된 그래프를 두고, wire를 하나씩 "끊는다고 가정"하며 모두 시도
    for (int i = 0; i < wires.size(); i++) {
        int node_A = wires[i][0];
        int node_B = wires[i][1];

        // node_A~node_B 간선을 끊었을 때, node_A가 속한 그룹의 크기
        int result = BFS(node_A, node_B, graph);

        // 전체가 n개인데 한쪽이 result개면, 나머지 한쪽은 (n-result)개
        // 두 그룹의 차이 = |result - (n-result)| = |2*result - n|
        minn = min(minn, abs(result * 2 - n));
    }

    return minn;  // 모든 wire를 끊어본 것 중 가장 균형 잡힌(차이가 가장 작은) 경우
}